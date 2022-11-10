//
// Created by unby7436 on 07/11/22.
//

#include "ScopesqConcreteListener.h"
#include "ScopesqParser.h"
#include "ScopesQ.h"
#include <boost/shared_ptr.hpp>

using namespace std;

void ScopesqConcreteListener::enterScopesq(ScopesqParser::ScopesqContext *context) {
    isFailed = false;
    scopesq = new ScopesQ;
}

void ScopesqConcreteListener::exitScopesq(ScopesqParser::ScopesqContext *context) {
}

void ScopesqConcreteListener::exitToplevelwildcard(ScopesqParser::ToplevelwildcardContext *) {
    OrScopeQ orScope;
    ScopeQ scope;
    scope.AddLevel("#");
    orScope.Append(scope);
    scopesq->Append(orScope);
    cout << "exit top level wildcard" <<endl;
}

void ScopesqConcreteListener::enterOrscopeq(ScopesqParser::OrscopeqContext *context) {
    orScope = new OrScopeQ;
}

void ScopesqConcreteListener::exitOrscopeq(ScopesqParser::OrscopeqContext *context) {
    if (context->SCOPEHIERARCHYWILDCARD() != nullptr) {
        orScope->Last().AddLevel("#");
    }
    scopesq->Append(*orScope); // TODO memory leak
}

void ScopesqConcreteListener::enterScopeq(ScopesqParser::ScopeqContext *context) {
    scope = new ScopeQ;
}

void ScopesqConcreteListener::exitScopeq(ScopesqParser::ScopeqContext *context) {
    orScope->Append(*scope); // TODO memory leak
}

void ScopesqConcreteListener::enterScopeqlevel(ScopesqParser::ScopeqlevelContext *context) {
}

void ScopesqConcreteListener::exitScopeqlevel(ScopesqParser::ScopeqlevelContext *context) {
    if (context->IDENTIFIER() != nullptr) {
        scope->AddLevel(context->IDENTIFIER()->getText());
    } else {
        scope->AddLevel(context->SCOPELEVELWILDCARD()->getText());
    }
}

ScopesQ *ScopesqConcreteListener::getScopesq() const {
    return scopesq;
}
void ScopesqConcreteListener::syntaxError(antlr4::Recognizer *recognizer, antlr4::Token *offendingSymbol, size_t line,
                                        size_t charPositionInLine, const string &msg, std::exception_ptr e) {
    isFailed = true;
    errorMessage = msg + " (character index " + to_string(charPositionInLine) + ")";
}

const std::string &ScopesqConcreteListener::getErrorMessage() const {
    return errorMessage;
}
