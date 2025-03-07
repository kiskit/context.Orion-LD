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
#include "kjson/kjBuilder.h"                                     // kjBuilder
}

#include "logMsg/logMsg.h"                                       // LM_*
#include "logMsg/traceLevels.h"                                  // Lmt*

#include "orionld/context/OrionldContext.h"                      // OrionldContext
#include "orionld/common/orionldState.h"                         // coreContextUrl
#include "orionld/context/orionldContextSimplify.h"              // Own interface



// -----------------------------------------------------------------------------
//
// orionldContextSimplify - simplify the context, if possible
//
// Only for arrays.
// Any string in the array, that is the Core Context, is removed from the array
// If after processing, there is only ONE item in the array, that item is returned
// as the context, regardless of its type.
//
// If on the other hand the array becomes empty after removal of Core Context, the NULL is returned.
// The caller needs to check for this.
//
KjNode* orionldContextSimplify(KjNode* contextTreeP, int* itemsInArrayP)
{
  KjNode* nodeP       = contextTreeP->value.firstChildP;
  int    itemsInArray = 0;

  while (nodeP != NULL)
  {
    KjNode* next = nodeP->next;

    if ((nodeP->type == KjString) && (strcmp(nodeP->value.s, coreContextUrl) == 0))
      kjChildRemove(contextTreeP, nodeP);
    else
      ++itemsInArray;

    nodeP = next;
  }

  if (itemsInArrayP != 0)
    *itemsInArrayP = itemsInArray;

  return contextTreeP;
}
