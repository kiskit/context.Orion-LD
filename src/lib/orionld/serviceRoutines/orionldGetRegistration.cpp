/*
*
* Copyright 2018 FIWARE Foundation e.V.
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
* Author: Ken Zangelin and Larysse Savanna
*/
#include "logMsg/logMsg.h"                                     // LM_*
#include "logMsg/traceLevels.h"                                // Lmt*

#include "orionld/common/orionldState.h"                       // orionldState
#include "orionld/common/orionldError.h"                       // orionldError
#include "orionld/mongoBackend/mongoLdRegistrationGet.h"       // mongoLdRegistrationGet
#include "orionld/kjTree/kjTreeFromRegistration.h"             // kjTreeFromRegistration
#include "orionld/serviceRoutines/orionldGetRegistration.h"    // Own Interface



// ----------------------------------------------------------------------------
//
// orionldGetRegistration -
//
bool orionldGetRegistration(void)
{
  ngsiv2::Registration  registration;
  char*                 details;

  if (mongoLdRegistrationGet(&registration, orionldState.wildcard[0], orionldState.tenantP, &orionldState.httpStatusCode, &details) != true)
  {
    orionldError(OrionldResourceNotFound, details, orionldState.wildcard[0], 404);
    return false;
  }

  // Transform to KjNode tree
  orionldState.httpStatusCode  = SccOk;
  orionldState.responseTree    = kjTreeFromRegistration(&registration);

  return true;
}
