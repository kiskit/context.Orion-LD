/*
*
* Copyright 2019 FIWARE Foundation e.V.
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
extern "C"
{
#include "kjson/KjNode.h"                                        // KjNode
#include "kjson/kjBuilder.h"                                     // kjString, kjChildAdd
}

#include "logMsg/logMsg.h"                                       // LM_*
#include "logMsg/traceLevels.h"                                  // Lmt*

#include "orionld/common/orionldState.h"                         // orionldState
#include "orionld/common/attributeNotUpdated.h"                  // Own interface



// ----------------------------------------------------------------------------
//
// attributeNotUpdated -
//
void attributeNotUpdated(KjNode* notUpdatedP, const char* attrName, const char* title, const char* detail)
{
  KjNode* notUpdatedDetailsP = kjObject(orionldState.kjsonP, NULL);
  KjNode* attrNameP          = kjString(orionldState.kjsonP, "attributeName", attrName);
  char    reason[512];

  if (detail != NULL)
    snprintf(reason, sizeof(reason), "%s: %s", title, detail);
  else
    snprintf(reason, sizeof(reason), "%s", title);

  KjNode* reasonP            = kjString(orionldState.kjsonP, "reason", reason);

  kjChildAdd(notUpdatedDetailsP, attrNameP);
  kjChildAdd(notUpdatedDetailsP, reasonP);

  kjChildAdd(notUpdatedP, notUpdatedDetailsP);
}
