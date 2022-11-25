//
// Created by unby7436 on 22/11/22.
//

#ifndef ORIONLD_QUERYBUILDERLISTENER_H
#define ORIONLD_QUERYBUILDERLISTENER_H

#include "QueryBaseListener.h"
#include "orionld/q/QNode.h"

class QueryBuilderListener : public QueryBaseListener {
private:
    std::vector<QNode*> nodes;
public:
    virtual void exitQuery(QueryParser::QueryContext * /*ctx*/) override;

    virtual void exitQuerytermortermandassoc(QueryParser::QuerytermortermandassocContext * /*ctx*/) override;

    virtual void exitQuerytermassocornot(QueryParser::QuerytermassocornotContext * /*ctx*/) override;

    virtual void exitQuerytermassoc(QueryParser::QuerytermassocContext * /*ctx*/) override;

    virtual void exitQuerytermandassoc(QueryParser::QuerytermandassocContext * /*ctx*/) override;

    virtual void exitQueryterm(QueryParser::QuerytermContext * /*ctx*/) override;

    virtual void exitDottedpath(QueryParser::DottedpathContext * /*ctx*/) override;

    virtual void exitAttribute(QueryParser::AttributeContext * /*ctx*/) override;

    virtual void exitQoperator(QueryParser::QoperatorContext * /*ctx*/) override;

    virtual void exitPatternop(QueryParser::PatternopContext * /*ctx*/) override;

    virtual void exitPatternnoop(QueryParser::PatternnoopContext * /*ctx*/) override;

    virtual void exitGreatereq(QueryParser::GreatereqContext * /*ctx*/) override;

    virtual void exitGreater(QueryParser::GreaterContext * /*ctx*/) override;

    virtual void exitLess(QueryParser::LessContext * /*ctx*/) override;

    virtual void exitLesseq(QueryParser::LesseqContext * /*ctx*/) override;

    virtual void exitEqual(QueryParser::EqualContext * /*ctx*/) override;

    virtual void exitUnequal(QueryParser::UnequalContext * /*ctx*/) override;

    virtual void exitOthervalue(QueryParser::OthervalueContext * /*ctx*/) override;

    virtual void exitQtrue(QueryParser::QtrueContext * /*ctx*/) override;

    virtual void exitQfalse(QueryParser::QfalseContext * /*ctx*/) override;

    virtual void exitValue(QueryParser::ValueContext * /*ctx*/) override;

    virtual void exitRange(QueryParser::RangeContext * /*ctx*/) override;

    virtual void exitValuelist(QueryParser::ValuelistContext * /*ctx*/) override;

    virtual void exitCompequalityvalue(QueryParser::CompequalityvalueContext * /*ctx*/) override;

    virtual void exitUri(QueryParser::UriContext * /*ctx*/) override;

    virtual void exitLogicalop(QueryParser::LogicalopContext * /*ctx*/) override;

    virtual void exitOrop(QueryParser::OropContext * /*ctx*/) override;

    virtual void exitAndop(QueryParser::AndopContext * /*ctx*/) override;

    virtual void exitComparablevalue(QueryParser::ComparablevalueContext * /*ctx*/) override;

    virtual void exitQuotedstr(QueryParser::QuotedstrContext * /*ctx*/) override;

    virtual void exitNotaquote(QueryParser::NotaquoteContext * /*ctx*/) override;

    virtual void exitQuotedstringchar(QueryParser::QuotedstringcharContext * /*ctx*/) override;

    virtual void exitRegex(QueryParser::RegexContext * /*ctx*/) override;

    virtual void exitRegexchar(QueryParser::RegexcharContext * /*ctx*/) override;

    //virtual void exitNotaparenthesis(QueryParser::NotaparenthesisContext * /*ctx*/) override;

    virtual void exitDatetime(QueryParser::DatetimeContext * /*ctx*/) override;

    virtual void exitDate(QueryParser::DateContext * /*ctx*/) override;

    virtual void exitTime(QueryParser::TimeContext * /*ctx*/) override;

    virtual void exitNumber(QueryParser::NumberContext * /*ctx*/) override;

    virtual void exitOpeningpar(QueryParser::OpeningparContext * /*ctx*/) override;

    virtual void exitClosingpar(QueryParser::ClosingparContext * /*ctx*/) override;

    virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override;

    virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override;

    virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override;
};


#endif //ORIONLD_QUERYBUILDERLISTENER_H
