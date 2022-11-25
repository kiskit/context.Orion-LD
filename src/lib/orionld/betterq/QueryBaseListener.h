
// Generated from Query.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "QueryListener.h"


/**
 * This class provides an empty implementation of QueryListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  QueryBaseListener : public QueryListener {
public:

  virtual void enterQuery(QueryParser::QueryContext * /*ctx*/) override { }
  virtual void exitQuery(QueryParser::QueryContext * /*ctx*/) override { }

  virtual void enterQuerytermortermandassoc(QueryParser::QuerytermortermandassocContext * /*ctx*/) override { }
  virtual void exitQuerytermortermandassoc(QueryParser::QuerytermortermandassocContext * /*ctx*/) override { }

  virtual void enterQuerytermassocornot(QueryParser::QuerytermassocornotContext * /*ctx*/) override { }
  virtual void exitQuerytermassocornot(QueryParser::QuerytermassocornotContext * /*ctx*/) override { }

  virtual void enterQuerytermassoc(QueryParser::QuerytermassocContext * /*ctx*/) override { }
  virtual void exitQuerytermassoc(QueryParser::QuerytermassocContext * /*ctx*/) override { }

  virtual void enterQuerytermandassoc(QueryParser::QuerytermandassocContext * /*ctx*/) override { }
  virtual void exitQuerytermandassoc(QueryParser::QuerytermandassocContext * /*ctx*/) override { }

  virtual void enterQueryterm(QueryParser::QuerytermContext * /*ctx*/) override { }
  virtual void exitQueryterm(QueryParser::QuerytermContext * /*ctx*/) override { }

  virtual void enterDottedpath(QueryParser::DottedpathContext * /*ctx*/) override { }
  virtual void exitDottedpath(QueryParser::DottedpathContext * /*ctx*/) override { }

  virtual void enterAttribute(QueryParser::AttributeContext * /*ctx*/) override { }
  virtual void exitAttribute(QueryParser::AttributeContext * /*ctx*/) override { }

  virtual void enterQoperator(QueryParser::QoperatorContext * /*ctx*/) override { }
  virtual void exitQoperator(QueryParser::QoperatorContext * /*ctx*/) override { }

  virtual void enterPatternop(QueryParser::PatternopContext * /*ctx*/) override { }
  virtual void exitPatternop(QueryParser::PatternopContext * /*ctx*/) override { }

  virtual void enterPatternnoop(QueryParser::PatternnoopContext * /*ctx*/) override { }
  virtual void exitPatternnoop(QueryParser::PatternnoopContext * /*ctx*/) override { }

  virtual void enterGreatereq(QueryParser::GreatereqContext * /*ctx*/) override { }
  virtual void exitGreatereq(QueryParser::GreatereqContext * /*ctx*/) override { }

  virtual void enterGreater(QueryParser::GreaterContext * /*ctx*/) override { }
  virtual void exitGreater(QueryParser::GreaterContext * /*ctx*/) override { }

  virtual void enterLess(QueryParser::LessContext * /*ctx*/) override { }
  virtual void exitLess(QueryParser::LessContext * /*ctx*/) override { }

  virtual void enterLesseq(QueryParser::LesseqContext * /*ctx*/) override { }
  virtual void exitLesseq(QueryParser::LesseqContext * /*ctx*/) override { }

  virtual void enterEqual(QueryParser::EqualContext * /*ctx*/) override { }
  virtual void exitEqual(QueryParser::EqualContext * /*ctx*/) override { }

  virtual void enterUnequal(QueryParser::UnequalContext * /*ctx*/) override { }
  virtual void exitUnequal(QueryParser::UnequalContext * /*ctx*/) override { }

  virtual void enterOthervalue(QueryParser::OthervalueContext * /*ctx*/) override { }
  virtual void exitOthervalue(QueryParser::OthervalueContext * /*ctx*/) override { }

  virtual void enterQtrue(QueryParser::QtrueContext * /*ctx*/) override { }
  virtual void exitQtrue(QueryParser::QtrueContext * /*ctx*/) override { }

  virtual void enterQfalse(QueryParser::QfalseContext * /*ctx*/) override { }
  virtual void exitQfalse(QueryParser::QfalseContext * /*ctx*/) override { }

  virtual void enterValue(QueryParser::ValueContext * /*ctx*/) override { }
  virtual void exitValue(QueryParser::ValueContext * /*ctx*/) override { }

  virtual void enterRange(QueryParser::RangeContext * /*ctx*/) override { }
  virtual void exitRange(QueryParser::RangeContext * /*ctx*/) override { }

  virtual void enterValuelist(QueryParser::ValuelistContext * /*ctx*/) override { }
  virtual void exitValuelist(QueryParser::ValuelistContext * /*ctx*/) override { }

  virtual void enterCompequalityvalue(QueryParser::CompequalityvalueContext * /*ctx*/) override { }
  virtual void exitCompequalityvalue(QueryParser::CompequalityvalueContext * /*ctx*/) override { }

  virtual void enterUri(QueryParser::UriContext * /*ctx*/) override { }
  virtual void exitUri(QueryParser::UriContext * /*ctx*/) override { }

  virtual void enterLogicalop(QueryParser::LogicalopContext * /*ctx*/) override { }
  virtual void exitLogicalop(QueryParser::LogicalopContext * /*ctx*/) override { }

  virtual void enterOrop(QueryParser::OropContext * /*ctx*/) override { }
  virtual void exitOrop(QueryParser::OropContext * /*ctx*/) override { }

  virtual void enterAndop(QueryParser::AndopContext * /*ctx*/) override { }
  virtual void exitAndop(QueryParser::AndopContext * /*ctx*/) override { }

  virtual void enterComparablevalue(QueryParser::ComparablevalueContext * /*ctx*/) override { }
  virtual void exitComparablevalue(QueryParser::ComparablevalueContext * /*ctx*/) override { }

  virtual void enterQuotedstr(QueryParser::QuotedstrContext * /*ctx*/) override { }
  virtual void exitQuotedstr(QueryParser::QuotedstrContext * /*ctx*/) override { }

  virtual void enterNotaquote(QueryParser::NotaquoteContext * /*ctx*/) override { }
  virtual void exitNotaquote(QueryParser::NotaquoteContext * /*ctx*/) override { }

  virtual void enterQuotedstringchar(QueryParser::QuotedstringcharContext * /*ctx*/) override { }
  virtual void exitQuotedstringchar(QueryParser::QuotedstringcharContext * /*ctx*/) override { }

  virtual void enterRegex(QueryParser::RegexContext * /*ctx*/) override { }
  virtual void exitRegex(QueryParser::RegexContext * /*ctx*/) override { }

  virtual void enterRegexchar(QueryParser::RegexcharContext * /*ctx*/) override { }
  virtual void exitRegexchar(QueryParser::RegexcharContext * /*ctx*/) override { }

  virtual void enterNotaparenthesis(QueryParser::NotaparenthesisContext * /*ctx*/) override { }
  virtual void exitNotaparenthesis(QueryParser::NotaparenthesisContext * /*ctx*/) override { }

  virtual void enterDatetime(QueryParser::DatetimeContext * /*ctx*/) override { }
  virtual void exitDatetime(QueryParser::DatetimeContext * /*ctx*/) override { }

  virtual void enterDate(QueryParser::DateContext * /*ctx*/) override { }
  virtual void exitDate(QueryParser::DateContext * /*ctx*/) override { }

  virtual void enterTime(QueryParser::TimeContext * /*ctx*/) override { }
  virtual void exitTime(QueryParser::TimeContext * /*ctx*/) override { }

  virtual void enterNumber(QueryParser::NumberContext * /*ctx*/) override { }
  virtual void exitNumber(QueryParser::NumberContext * /*ctx*/) override { }

  virtual void enterOpeningpar(QueryParser::OpeningparContext * /*ctx*/) override { }
  virtual void exitOpeningpar(QueryParser::OpeningparContext * /*ctx*/) override { }

  virtual void enterClosingpar(QueryParser::ClosingparContext * /*ctx*/) override { }
  virtual void exitClosingpar(QueryParser::ClosingparContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

