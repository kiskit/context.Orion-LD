/*
*
* Copyright 2013 Telefonica Investigacion y Desarrollo, S.A.U
*
* This file is part of Orion Context Broker.
*
* Orion Context Broker is free software: you can redistribute it and/or
* modify it under the terms of the GNU Affero General Public License as
* published by the Free Software Foundation, either version 3 of the
* License, or (at your option) any later version.
*
* Orion Context Broker is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero
* General Public License for more details.
*
* You should have received a copy of the GNU Affero General Public License
* along with Orion Context Broker. If not, see http://www.gnu.org/licenses/.
*
* For those usages not covered by this license please contact with
* iot_support at tid dot es
*
* Author: Fermin Galan Marquez
*/
#include <string>

#include "logMsg/logMsg.h"
#include "logMsg/traceLevels.h"

#include "common/globals.h"
#include "common/MimeType.h"
#include "common/sem.h"
#include "alarmMgr/alarmMgr.h"

#include "orionld/types/OrionldTenant.h"             // OrionldTenant
#include "orionld/common/orionldState.h"             // orionldState

#include "mongoBackend/MongoGlobal.h"
#include "mongoBackend/connectionOperations.h"
#include "mongoBackend/safeMongo.h"
#include "mongoBackend/dbConstants.h"
#include "mongoBackend/mongoUpdateContextAvailabilitySubscription.h"
#include "ngsi9/UpdateContextAvailabilitySubscriptionRequest.h"
#include "ngsi9/UpdateContextAvailabilitySubscriptionResponse.h"



/* ****************************************************************************
*
* USING
*/
using mongo::BSONObj;
using mongo::OID;
using mongo::BSONArrayBuilder;
using mongo::BSONObjBuilder;



/* ****************************************************************************
*
* mongoUpdateContextAvailabilitySubscription - 
*/
HttpStatusCode mongoUpdateContextAvailabilitySubscription
(
  UpdateContextAvailabilitySubscriptionRequest*   requestP,
  UpdateContextAvailabilitySubscriptionResponse*  responseP,
  const std::string&                              fiwareCorrelator,
  OrionldTenant*                                  tenantP
)
{
  bool reqSemTaken;

  if (tenantP == NULL)
    tenantP = orionldState.tenantP;

  reqSemTake(__FUNCTION__, "ngsi9 update subscription request", SemWriteOp, &reqSemTaken);

  /* Look for document */
  BSONObj     sub;
  std::string err;
  OID         id;

  if (!safeGetSubId(&requestP->subscriptionId, &id, &responseP->errorCode))
  {
    reqSemGive(__FUNCTION__, "ngsi9 update subscription request (mongo assertion exception)", reqSemTaken);

    if (responseP->errorCode.code == SccContextElementNotFound)
    {
      std::string details = std::string("invalid OID mimeType: '") + requestP->subscriptionId.get() + "'";
      alarmMgr.badInput(clientIp, details);
    }
    else  // SccReceiverInternalError
    {
      LM_E(("Runtime Error (exception getting OID: %s)", responseP->errorCode.details.c_str()));
    }

    return SccOk;
  }

  if (!collectionFindOne(tenantP->avSubscriptions, BSON("_id" << id), &sub, &err))
  {
    reqSemGive(__FUNCTION__, "ngsi9 update subscription request (mongo db exception)", reqSemTaken);
    responseP->errorCode.fill(SccReceiverInternalError, err);

    return SccOk;
  }

  if (sub.isEmpty())
  {
    responseP->errorCode.fill(SccContextElementNotFound);
    reqSemGive(__FUNCTION__, "ngsi9 update subscription request (no subscriptions found)", reqSemTaken);

    return SccOk;
  }

  /* We start with an empty BSONObjBuilder and process requestP for all the fields that can
   * be updated. I don't like too much this strategy (I would have preferred to start with
   * a copy of the original document, then modify as neded, but this doesn't seem to be easy
   * using the API provide by the Mongo C++ driver)
   *
   * FIXME: a better implementation strategy could be doing an findAndModify() query to do the
   * update, so detecting if the document was not found, instead of using findOne() + update()
   * with $set operation. One operations to MongoDb. vs two operations.
   */
  BSONObjBuilder newSub;

  /* Entities (mandatory) */
  BSONArrayBuilder entities;
  for (unsigned int ix = 0; ix < requestP->entityIdVector.size(); ++ix)
  {
    EntityId* en = requestP->entityIdVector[ix];

    if (en->type == "")
    {
      entities.append(BSON(CASUB_ENTITY_ID << en->id <<
                           CASUB_ENTITY_ISPATTERN << en->isPattern));
    }
    else
    {
      entities.append(BSON(CASUB_ENTITY_ID << en->id <<
                           CASUB_ENTITY_TYPE << en->type <<
                           CASUB_ENTITY_ISPATTERN << en->isPattern));
    }
  }

  newSub.append(CASUB_ENTITIES, entities.arr());

  /* Attributes (always taken into account) */
  BSONArrayBuilder attrs;

  for (unsigned int ix = 0; ix < requestP->attributeList.size(); ++ix)
  {
      attrs.append(requestP->attributeList[ix]);
  }
  newSub.append(CASUB_ATTRS, attrs.arr());

  /* Duration (optional) */
  if (requestP->duration.isEmpty())
  {
    newSub.append(CASUB_EXPIRATION, getIntOrLongFieldAsLongF(&sub, CASUB_EXPIRATION));
  }
  else
  {
    int64_t expiration = orionldState.requestTime + requestP->duration.parse();

    newSub.append(CASUB_EXPIRATION, (long long) expiration);
    LM_T(LmtMongo, ("New subscription expiration: %l", expiration));
  }

  /* Reference is not updatable, so it is appended directly */
  newSub.append(CASUB_REFERENCE, getStringFieldF(&sub, CASUB_REFERENCE));

  int count = sub.hasField(CASUB_COUNT) ? getIntFieldF(&sub, CASUB_COUNT) : 0;

  /* The hasField check is needed due to lastNotification/count could not be present in the original doc */
  if (sub.hasField(CASUB_LASTNOTIFICATION))
  {
    newSub.append(CASUB_LASTNOTIFICATION, getIntFieldF(&sub, CASUB_LASTNOTIFICATION));
  }

  if (sub.hasField(CASUB_COUNT))
  {
    newSub.append(CASUB_COUNT, count);
  }

  //
  // FIXME P5: RenderFormat right now hardcoded to "JSON" (RF_LEGACY),
  //           in the future the RenderFormat will be taken from the payload
  //

  /* Adding format to use in notifications */
  newSub.append(CASUB_FORMAT, "JSON");

  /* Update document in MongoDB */

  BSONObj      bson    = BSON("_id" << OID(requestP->subscriptionId.get()));

  if (!collectionUpdate(tenantP->avSubscriptions, bson, newSub.obj(), false, &err))
  {
    reqSemGive(__FUNCTION__, "ngsi9 update subscription request (mongo db exception)", reqSemTaken);
    responseP->errorCode.fill(SccReceiverInternalError, err);

    return SccOk;
  }

  //
  // FIXME P5: RenderFormat right now hardcoded to RF_LEGACY,
  //           in the future the RenderFormat will be taken from the payload
  //

  /* Send notifications for matching context registrations */
  processAvailabilitySubscription(requestP->entityIdVector,
                                  requestP->attributeList,
                                  requestP->subscriptionId.get(),
                                  getStringFieldF(&sub, CASUB_REFERENCE),
                                  RF_LEGACY,
                                  tenantP,
                                  fiwareCorrelator);

  /* Duration is an optional parameter, it is only added in the case they
   * was used for update */
  if (!requestP->duration.isEmpty())
  {
    responseP->duration = requestP->duration;
  }

  responseP->subscriptionId = requestP->subscriptionId;
  reqSemGive(__FUNCTION__, "ngsi9 update subscription request", reqSemTaken);

  return SccOk;
}
