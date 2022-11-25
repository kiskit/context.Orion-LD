//
// Created by unby7436 on 22/11/22.
//

#ifndef ORIONLD_QBUILDER_H
#define ORIONLD_QBUILDER_H

#include "context.Orion-LD/src/lib/orionld/q/QNode.h"

class QBuilder {
public:
    static QNode* Build(const char* q, char** qRenderP, bool* v2ValidP, bool* isMqP, bool qToDbModel);
};


#endif //ORIONLD_QBUILDER_H
