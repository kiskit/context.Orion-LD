//
// Created by unby7436 on 07/11/22.
//

#ifndef ORIONLD_SCOPECONCRETELISTENER_H
#define ORIONLD_SCOPECONCRETELISTENER_H

#include "ScopesqBaseListener.h"
#include "ScopesQ.h"

using namespace std;

class ScopesqConcreteListener : public ScopesqBaseListener,
                                public antlr4::BaseErrorListener,
                                public antlr4::DefaultErrorStrategy {
public:
    ScopesQ *getScopesq() const;

private:
    bool isFailed;
    string errorMessage;
    ScopesQ *scopesq;
    OrScopeQ *orScope;
    ScopeQ *scope;
public:
    void enterScopesq(ScopesqParser::ScopesqContext *) override;

    void exitScopesq(ScopesqParser::ScopesqContext *) override;

    void exitToplevelwildcard(ScopesqParser::ToplevelwildcardContext *) override;

    void enterOrscopeq(ScopesqParser::OrscopeqContext *) override;

    void exitOrscopeq(ScopesqParser::OrscopeqContext *) override;

    void enterScopeq(ScopesqParser::ScopeqContext *) override;

    void exitScopeq(ScopesqParser::ScopeqContext *) override;

    void enterScopeqlevel(ScopesqParser::ScopeqlevelContext *) override;

    void exitScopeqlevel(ScopesqParser::ScopeqlevelContext *) override;

    virtual ~ScopesqConcreteListener() {}

    void syntaxError(antlr4::Recognizer *recognizer, antlr4::Token *offendingSymbol, size_t line,
                     size_t charPositionInLine, const std::string &msg, std::exception_ptr e) override;

    bool hasFailed() {return isFailed;}
    const std::string &getErrorMessage() const;

};

#endif //ORIONLD_SCOPECONCRETELISTENER_H
