//
// Created by unby7436 on 22/11/22.
//

#include "QBuilder.h"

#include "logMsg/logMsg.h"
#include "orionld/betterq/QueryLexer.h"
#include "orionld/betterq/QueryParser.h"
#include "orionld/betterq/QueryConcreteListener.h"
#include "orionld/betterq/QPrint.h"
#include "orionld/common/quoteProtect.h"
#include "orionld/common/orionldError.h"
#include "orionld/types/OrionldResponseErrorType.h"
#include "orionld/q/qLexListRender.h"
#include "orionld/common/orionldState.h"                       // orionldState

using namespace std;
QNode *QBuilder::Build(const char *q, char **qRenderP, bool *v2ValidP, bool *isMqP, bool qToDbModel) {
    orionldState.useMalloc = true;  // the Q-Tree needs real alloction for the sub-cache

    stringstream stream(q);
    antlr4::ANTLRInputStream input(stream);
    QueryLexer lexer(&input);
    lexer.removeErrorListeners();
    antlr4::CommonTokenStream tokens(&lexer);

    QueryParser parser(&tokens);
    Ref<antlr4::BailErrorStrategy> strategy(new antlr4::BailErrorStrategy());
    parser.setErrorHandler(strategy);
    QueryConcreteListener listener(true, qToDbModel, true);
    parser.addParseListener(&listener);
    parser.removeErrorListeners();
    parser.addErrorListener(&listener);
    try {
        parser.query();
        if (listener.hasFailed()) {
            const char *error = listener.getErrorMessage().c_str();
            orionldError(OrionldBadRequestData, "Invalid Q-Filter", error, 400);
            LM_RE(nullptr, ("Error (qLex: %s: %s)", "invalid q filter", error));
        }
        if (qRenderP != NULL) {
            // NOTE: qLexListRender MUST NOT destroy the qList!!!
            *qRenderP = qLexListRender2(listener.getNode(), v2ValidP, isMqP);
            cout << "Once rendered: " << *qRenderP << endl;
            if (*qRenderP == NULL) {
                // qLexListRender prepares orionldError
                return NULL;
            }
        }
    } catch (antlr4::ParseCancellationException &e) {
        string error = listener.getErrorMessage().c_str();
        if (error.length() == 0) {
            string illegal = parser.getCurrentToken()->getText();
            error = "illegal <" + quoteProtect(illegal) + "> at index " +
                    to_string(parser.getCurrentToken()->getCharPositionInLine());
        }
        orionldError(OrionldBadRequestData, "Invalid Q-Filter", error.c_str(), 400);
        LM_RE(nullptr, ("Error (qLex: %s: %s)", "invalid q filter", error.c_str()));
    }
    orionldState.useMalloc = false;  // the Q-Tree needs real alloction for the sub-cache

    return listener.getNode();
}