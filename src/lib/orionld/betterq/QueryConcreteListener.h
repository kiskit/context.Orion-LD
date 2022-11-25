#pragma once

#include "antlr4-runtime.h"

#include "QueryParser.h"
#include "QueryBaseListener.h"
#include "orionld/q/QNode.h"

/* This class acts as both a listener and an error listener
 * */
class QueryConcreteListener
        : public QueryBaseListener, public antlr4::BaseErrorListener, public antlr4::DefaultErrorStrategy {
private:
    QNode *result;
    std::vector<QNode *> stack;
    bool forDB, qToDbModel, timestampToFloat;

    std::string errorMessage;

    bool isFailed = false;

public:

    QueryConcreteListener(bool _forDB, bool _qToDbModel, bool _timestampToFloat) : result(nullptr), forDB(_forDB),
                                                                                   qToDbModel(_qToDbModel),
                                                                                   timestampToFloat(
                                                                                           _timestampToFloat) {}
    void exitQuery(QueryParser::QueryContext *ctx) override;
    void exitQuerytermortermandassoc(QueryParser::QuerytermortermandassocContext *ctx) override;
    void exitQuerytermassoc(QueryParser::QuerytermassocContext *ctx) override;

    void exitQuerytermandassoc(QueryParser::QuerytermandassocContext *ctx) override;

    void exitQueryterm(QueryParser::QuerytermContext *ctx) override;

    void exitAttribute(QueryParser::AttributeContext *ctx) override;

    void exitPatternop(QueryParser::PatternopContext *ctx) override;

    void exitPatternnoop(QueryParser::PatternnoopContext *ctx) override;

    void exitGreatereq(QueryParser::GreatereqContext * /*ctx*/) override;

    void exitGreater(QueryParser::GreaterContext * /*ctx*/) override;

    void exitLess(QueryParser::LessContext * /*ctx*/) override;

    void exitLesseq(QueryParser::LesseqContext * /*ctx*/) override;

    void exitEqual(QueryParser::EqualContext *ctx) override;

    void exitUnequal(QueryParser::UnequalContext *ctx) override;

    void exitOrop(QueryParser::OropContext *ctx) override;

    void exitAndop(QueryParser::AndopContext *ctx) override;

    void exitQuotedstr(QueryParser::QuotedstrContext * /*ctx*/) override;

    void exitDate(QueryParser::DateContext *ctx) override;

    void exitDatetime(QueryParser::DatetimeContext *ctx) override;

    void exitTime(QueryParser::TimeContext * /*ctx*/) override;

    void exitQtrue(QueryParser::QtrueContext * /*ctx*/) override;

    void exitQfalse(QueryParser::QfalseContext * /*ctx*/) override;

    void exitRange(QueryParser::RangeContext *ctx) override;

    void exitValuelist(QueryParser::ValuelistContext *ctx) override;

    void exitUri(QueryParser::UriContext *ctx) override;

    void exitNumber(QueryParser::NumberContext *ctx) override;

    void exitRegex(QueryParser::RegexContext *ctx) override;

    void exitOpeningpar(QueryParser::OpeningparContext *ctx) override;

    void exitDottedpath(QueryParser::DottedpathContext *ctx) override;

    void syntaxError(antlr4::Recognizer *recognizer, antlr4::Token *offendingSymbol, size_t line,
                     size_t charPositionInLine, const std::string &msg, std::exception_ptr e) override;

    QNode *getNode();

    bool hasFailed() const;

    const std::string &getErrorMessage() const;

    void processLogicalAndNodes(std::vector<QNode *> &queryTermOrTermAssocStack, std::vector<QNode *> &orStack) const;

    void processLogicalOrNodes(std::vector<QNode *> &orStack);
};

