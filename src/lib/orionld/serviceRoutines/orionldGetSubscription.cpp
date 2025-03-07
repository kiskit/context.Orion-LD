/*
*
* Copyright 2022 FIWARE Foundation e.V.
*
* This file is part of Orion-LD Context Broker.
*
* Orion-LD Context Broker is free software: you can redistribute it and/or
* modify it under the terms of the GNU Affero General Public License as
* published by the Free Software Foundation, either version 3 of the
* License, or (at your option) any later version.
*
* Orion-LD Context Broker is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero
* General Public License for more details.
*
* You should have received a copy of the GNU Affero General Public License
* along with Orion-LD Context Broker. If not, see http://www.gnu.org/licenses/.
*
* For those usages not covered by this license please contact with
* orionld at fiware dot org
*
* Author: Ken Zangelin
*/
#include "logMsg/logMsg.h"                                       // LM_*

#include "orionld/common/orionldState.h"                         // orionldState
#include "orionld/common/orionldError.h"                         // orionldError
#include "orionld/legacyDriver/legacyGetSubscription.h"          // legacyGetSubscription
#include "cache/subCache.h"                                      // CachedSubscription, subCacheItemLookup
#include "orionld/kjTree/kjTreeFromCachedSubscription.h"         // kjTreeFromCachedSubscription
#include "orionld/serviceRoutines/orionldGetSubscription.h"      // Own Interface



// ----------------------------------------------------------------------------
//
// orionldGetSubscription -
//
bool orionldGetSubscription(void)
{
  if (experimental == false)
    return legacyGetSubscription();

  if (orionldState.uriParamOptions.fromDb == true)
  {
    //
    // GET Subscription with mongoc is yet to be implemented, so, we'll have to use the old Legacy function ...
    // BUT, not if mongocOnly is set
    //
    if (mongocOnly == true)
    {
      orionldError(OrionldOperationNotSupported, "Not Implemented", "this request does not support the new mongoc driver", 501);
      return false;
    }

    return legacyGetSubscription();
  }

  char*                 subscriptionId = orionldState.wildcard[0];
  CachedSubscription*   cSubP          = subCacheItemLookup(orionldState.tenantP->tenant, subscriptionId);

  if (cSubP != NULL)
  {
    orionldState.httpStatusCode = 200;
    orionldState.responseTree   = kjTreeFromCachedSubscription(cSubP, orionldState.uriParamOptions.sysAttrs, orionldState.out.contentType == JSONLD);

    return true;
  }

  orionldError(OrionldResourceNotFound, "subscription not found", subscriptionId, 404);
  return false;
}
