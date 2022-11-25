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
#include <stdio.h>                                             // snprintf
#include <stdlib.h>                                            // malloc

extern "C"
{
#include "kalloc/kaAlloc.h"                                    // kaAlloc
#include "kalloc/kaRealloc.h"                                  // kaRealloc
}

#include "logMsg/logMsg.h"                                     // LM_*

#include "orionld/common/orionldState.h"                       // orionldState
#include "orionld/common/orionldError.h"                       // orionldError
#include "orionld/common/dotForEq.h"                           // dotForEq
#include "orionld/q/QNode.h"                                   // QNode
#include "orionld/q/qVariableFix.h"                            // qVariableFix
#include "orionld/q/qLexListRender.h"                          // Own interface



// -----------------------------------------------------------------------------
//
// intToString -
//
const char* intToString(QNode* qItemP, char* buf, int bufLen)
{
  snprintf(buf, bufLen - 1, "%lld", qItemP->value.i);
  return buf;
}



// -----------------------------------------------------------------------------
//
// floatToString -
//
const char* floatToString(QNode* qItemP, char* buf, int bufLen)
{
  snprintf(buf, bufLen - 1, "%f", qItemP->value.f);
  return buf;
}



// -----------------------------------------------------------------------------
//
// regexToString -
//
const char* regexToString(QNode* qItemP, char* buf, int bufLen)
{
  return "REGEX";
}

char* addToBuf(const char * toAdd, char* addTo) {
    int len = strlen (toAdd);
    strncpy(addTo, toAdd, len);
    return &(addTo[len]);
}

bool requiresParenthesis(QNode* parent, QNode* child) {
    return (((parent->type == QNodeOr) || (parent->type == QNodeAnd)) &&
            ((child->type == QNodeOr) || (child->type == QNodeAnd)) &&
            (parent->type != child->type));
}

// Does it after parsing
char* qLexListRenderRec(QNode* qListP, bool* validInV2P, bool* isMqP, char* buf, bool requiresPar) {
    char* bufP;
    char staticBuf[512];
    bool isLeaf  = false;
    switch (qListP->type)
    {
        // these two don't exist anymore after parsing
        case QNodeOpen:
        case QNodeClose:
        case QNodeVoid:         bufP = NULL;                                 break;
        // Multi operand operators (could work for bi operand)
        case QNodeOr:
            bufP = (char*) "|";
            *validInV2P = false;
            isLeaf = false;
            break;
        case QNodeAnd:
            bufP = (char*) ";";
            isLeaf = false;
            break;
        case QNodeComma:
            bufP = (char*) ",";
            isLeaf = false;
            break;
        case QNodeExists:       bufP = NULL;
            bufP = qListP->value.children->value.s;
            isLeaf = true;
            break;
        case QNodeNotExists:    bufP = (char*) "!";
            isLeaf = false;
            break;
        // bi-operand operators
        case QNodeRange:        bufP = (char*) "..";
            isLeaf = false;
            break;
        case QNodeGT:           bufP = (char*) ">";
            isLeaf = false;
            break;
        case QNodeLT:           bufP = (char*) "<";
            isLeaf = false;
            break;
        case QNodeEQ:           bufP = (char*) "==";
            isLeaf = false;
            break;
        case QNodeNE:           bufP = (char*) "!=";
            isLeaf = false;
            break;
        case QNodeGE:           bufP = (char*) ">=";
            isLeaf = false;
            break;
        case QNodeLE:           bufP = (char*) "<=";
            isLeaf = false;
            break;
        case QNodeMatch:        bufP = (char*) "~=";
            isLeaf = false;
            break;
        case QNodeNoMatch:      bufP = (char*) "!~=";
            isLeaf = false;
            break;
        // Leaves
        case QNodeIntegerValue: intToString(qListP, staticBuf, sizeof(staticBuf));
            bufP = staticBuf;
            isLeaf = true;
            break;
        case QNodeFloatValue:   floatToString(qListP, staticBuf, sizeof(staticBuf));
            bufP = staticBuf;
            isLeaf = true;
            break;
        case QNodeRegexpValue:
            regexToString(qListP, staticBuf, sizeof(staticBuf));
            *validInV2P = false;
            bufP = staticBuf;
            isLeaf = true;
            break;
        case QNodeStringValue:
            sprintf(staticBuf, "\"%s\"",qListP->value.s);
            bufP = staticBuf;
            isLeaf = true;
            break;
        case QNodeTrueValue:    bufP = (char*) "true";
            isLeaf = true;
            break;
        case QNodeFalseValue:   bufP = (char *) "false";
            isLeaf = true;
            break;
        case QNodeVariable:
            char* detail;
            // bufP = qVariableFix(qListP->value.v, false, isMqP, reinterpret_cast<char **>(&detail));

            /*
            if (bufP == NULL)
            {
                orionldError(OrionldInternalError, "qVariableFix failed", detail, 500);
                return NULL;
            }
            */
            bufP = qListP->value.v;
            isLeaf = true;
            break;
    }
    if (bufP != NULL) {
        if (isLeaf) {
            buf = addToBuf(bufP, buf);
        } else {

            if (requiresPar) {
                buf = addToBuf("(", buf);
            }
            for (auto child = qListP->value.children; child != NULL; child = child->next) {
                bool par = requiresParenthesis(qListP, child); // will child require parenthesis
                buf = qLexListRenderRec(child, validInV2P, isMqP, buf, par);
                if (child->next != NULL) {
                    buf = addToBuf(bufP, buf);
                }
            }
            if (requiresPar) {
                buf = addToBuf(")", buf);
            }
        }
    }
    return buf;
}

char* qLexListRender2(QNode* qListP, bool* validInV2P, bool* isMqP){
    int    outSize = 512;
    char*  outP    = kaAlloc(&orionldState.kalloc, outSize);  // kaRealloc if needed
    char*  outPSave = outP;
    qLexListRenderRec(qListP, validInV2P, isMqP, outP, false);
    return outPSave;
}

// -----------------------------------------------------------------------------
//
// qLexListRender -
//

char* qLexListRender(QNode* qListP, bool* validInV2P, bool* isMqP)
{
  int    outSize = 512;
  char*  outP    = kaAlloc(&orionldState.kalloc, outSize);  // kaRealloc if needed
  int    outIx   = 0;
  char*  detail;

  *validInV2P = true;   // Set to false later if need be (in the switch below)
  *isMqP      = false;  // Set to true later if need be (qVariableFix)

  for (QNode* qItemP = qListP; qItemP != NULL; qItemP = qItemP->next)
  {
    char  buf[32];
    char* bufP = buf;

    switch (qItemP->type)
    {
    case QNodeVoid:         bufP = NULL;                                 break;
    case QNodeOpen:         bufP = (char*) "("; *validInV2P = false;     break;
    case QNodeClose:        bufP = (char*) ")"; *validInV2P = false;     break;
    case QNodeAnd:          bufP = (char*) ";";                          break;
    case QNodeOr:           bufP = (char*) "|"; *validInV2P = false;     break;
    case QNodeExists:       bufP = NULL;                                 break;
    case QNodeNotExists:    bufP = (char*) "!";                          break;
    case QNodeGT:           bufP = (char*) ">";                          break;
    case QNodeLT:           bufP = (char*) "<";                          break;
    case QNodeEQ:           bufP = (char*) "==";                         break;
    case QNodeNE:           bufP = (char*) "!=";                         break;
    case QNodeGE:           bufP = (char*) ">=";                         break;
    case QNodeLE:           bufP = (char*) "<=";                         break;
    case QNodeMatch:        bufP = (char*) "~=";                         break;
    case QNodeNoMatch:      bufP = (char*) "!~=";                        break;
    case QNodeComma:        bufP = (char*) ",";                          break;
    case QNodeRange:        bufP = (char*) "..";                         break;
    case QNodeIntegerValue: intToString(qItemP, buf, sizeof(buf));       break;
    case QNodeFloatValue:   floatToString(qItemP, buf, sizeof(buf));     break;
    case QNodeStringValue:  bufP = qItemP->value.s;                      break;
    case QNodeTrueValue:    bufP = (char*) "true";                       break;
    case QNodeFalseValue:   bufP = (char*) "false";                      break;
    case QNodeRegexpValue:
      regexToString(qItemP, buf, sizeof(buf));
      *validInV2P = false;
      break;
    case QNodeVariable:
      bufP = qVariableFix(qItemP->value.v, false, isMqP, &detail);
      if (bufP == NULL)
      {
        orionldError(OrionldInternalError, "qVariableFix failed", detail, 500);
        return NULL;
      }
      break;
    }

    if (bufP == NULL)
      continue;

    // If it's a QNodeStringValue we need to add %22 before and after => 6 extra bytes
    int extra = (qItemP->type == QNodeStringValue)? 6 : 0;
    int len   = strlen(bufP);
    if (outIx + len + extra >= outSize)
    {
      char* newBuf = kaRealloc(&orionldState.kalloc, outP, outSize + 512);

      if (newBuf == NULL)
      {
        free(outP);
        orionldError(OrionldInternalError, "Out of memory", "allocating room for Q-List", 500);
        return NULL;
      }
      outP = newBuf;
      outSize += 512;
    }

    if (qItemP->type == QNodeStringValue)
    {
      outP[outIx++] = '%';
      outP[outIx++] = '2';
      outP[outIx++] = '2';
    }

    strncpy(&outP[outIx], bufP, len);

    outIx += len;

    if (qItemP->type == QNodeStringValue)
    {
      outP[outIx++] = '%';
      outP[outIx++] = '2';
      outP[outIx++] = '2';
    }

    outP[outIx] = 0;
  }

  outP[outIx] = 0;
  return outP;
}
