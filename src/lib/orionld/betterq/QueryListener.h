
// Generated from Query.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "QueryParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by QueryParser.
 */
class  QueryListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterQuery(QueryParser::QueryContext *ctx) = 0;
  virtual void exitQuery(QueryParser::QueryContext *ctx) = 0;

  virtual void enterQuerytermortermandassoc(QueryParser::QuerytermortermandassocContext *ctx) = 0;
  virtual void exitQuerytermortermandassoc(QueryParser::QuerytermortermandassocContext *ctx) = 0;

  virtual void enterQuerytermassocornot(QueryParser::QuerytermassocornotContext *ctx) = 0;
  virtual void exitQuerytermassocornot(QueryParser::QuerytermassocornotContext *ctx) = 0;

  virtual void enterQuerytermassoc(QueryParser::QuerytermassocContext *ctx) = 0;
  virtual void exitQuerytermassoc(QueryParser::QuerytermassocContext *ctx) = 0;

  virtual void enterQuerytermandassoc(QueryParser::QuerytermandassocContext *ctx) = 0;
  virtual void exitQuerytermandassoc(QueryParser::QuerytermandassocContext *ctx) = 0;

  virtual void enterQueryterm(QueryParser::QuerytermContext *ctx) = 0;
  virtual void exitQueryterm(QueryParser::QuerytermContext *ctx) = 0;

  virtual void enterDottedpath(QueryParser::DottedpathContext *ctx) = 0;
  virtual void exitDottedpath(QueryParser::DottedpathContext *ctx) = 0;

  virtual void enterAttribute(QueryParser::AttributeContext *ctx) = 0;
  virtual void exitAttribute(QueryParser::AttributeContext *ctx) = 0;

  virtual void enterQoperator(QueryParser::QoperatorContext *ctx) = 0;
  virtual void exitQoperator(QueryParser::QoperatorContext *ctx) = 0;

  virtual void enterPatternop(QueryParser::PatternopContext *ctx) = 0;
  virtual void exitPatternop(QueryParser::PatternopContext *ctx) = 0;

  virtual void enterPatternnoop(QueryParser::PatternnoopContext *ctx) = 0;
  virtual void exitPatternnoop(QueryParser::PatternnoopContext *ctx) = 0;

  virtual void enterGreatereq(QueryParser::GreatereqContext *ctx) = 0;
  virtual void exitGreatereq(QueryParser::GreatereqContext *ctx) = 0;

  virtual void enterGreater(QueryParser::GreaterContext *ctx) = 0;
  virtual void exitGreater(QueryParser::GreaterContext *ctx) = 0;

  virtual void enterLess(QueryParser::LessContext *ctx) = 0;
  virtual void exitLess(QueryParser::LessContext *ctx) = 0;

  virtual void enterLesseq(QueryParser::LesseqContext *ctx) = 0;
  virtual void exitLesseq(QueryParser::LesseqContext *ctx) = 0;

  virtual void enterEqual(QueryParser::EqualContext *ctx) = 0;
  virtual void exitEqual(QueryParser::EqualContext *ctx) = 0;

  virtual void enterUnequal(QueryParser::UnequalContext *ctx) = 0;
  virtual void exitUnequal(QueryParser::UnequalContext *ctx) = 0;

  virtual void enterOthervalue(QueryParser::OthervalueContext *ctx) = 0;
  virtual void exitOthervalue(QueryParser::OthervalueContext *ctx) = 0;

  virtual void enterQtrue(QueryParser::QtrueContext *ctx) = 0;
  virtual void exitQtrue(QueryParser::QtrueContext *ctx) = 0;

  virtual void enterQfalse(QueryParser::QfalseContext *ctx) = 0;
  virtual void exitQfalse(QueryParser::QfalseContext *ctx) = 0;

  virtual void enterValue(QueryParser::ValueContext *ctx) = 0;
  virtual void exitValue(QueryParser::ValueContext *ctx) = 0;

  virtual void enterRange(QueryParser::RangeContext *ctx) = 0;
  virtual void exitRange(QueryParser::RangeContext *ctx) = 0;

  virtual void enterValuelist(QueryParser::ValuelistContext *ctx) = 0;
  virtual void exitValuelist(QueryParser::ValuelistContext *ctx) = 0;

  virtual void enterCompequalityvalue(QueryParser::CompequalityvalueContext *ctx) = 0;
  virtual void exitCompequalityvalue(QueryParser::CompequalityvalueContext *ctx) = 0;

  virtual void enterUri(QueryParser::UriContext *ctx) = 0;
  virtual void exitUri(QueryParser::UriContext *ctx) = 0;

  virtual void enterLogicalop(QueryParser::LogicalopContext *ctx) = 0;
  virtual void exitLogicalop(QueryParser::LogicalopContext *ctx) = 0;

  virtual void enterOrop(QueryParser::OropContext *ctx) = 0;
  virtual void exitOrop(QueryParser::OropContext *ctx) = 0;

  virtual void enterAndop(QueryParser::AndopContext *ctx) = 0;
  virtual void exitAndop(QueryParser::AndopContext *ctx) = 0;

  virtual void enterComparablevalue(QueryParser::ComparablevalueContext *ctx) = 0;
  virtual void exitComparablevalue(QueryParser::ComparablevalueContext *ctx) = 0;

  virtual void enterQuotedstr(QueryParser::QuotedstrContext *ctx) = 0;
  virtual void exitQuotedstr(QueryParser::QuotedstrContext *ctx) = 0;

  virtual void enterNotaquote(QueryParser::NotaquoteContext *ctx) = 0;
  virtual void exitNotaquote(QueryParser::NotaquoteContext *ctx) = 0;

  virtual void enterQuotedstringchar(QueryParser::QuotedstringcharContext *ctx) = 0;
  virtual void exitQuotedstringchar(QueryParser::QuotedstringcharContext *ctx) = 0;

  virtual void enterRegex(QueryParser::RegexContext *ctx) = 0;
  virtual void exitRegex(QueryParser::RegexContext *ctx) = 0;

  virtual void enterRegexchar(QueryParser::RegexcharContext *ctx) = 0;
  virtual void exitRegexchar(QueryParser::RegexcharContext *ctx) = 0;

  virtual void enterNotaparenthesis(QueryParser::NotaparenthesisContext *ctx) = 0;
  virtual void exitNotaparenthesis(QueryParser::NotaparenthesisContext *ctx) = 0;

  virtual void enterDatetime(QueryParser::DatetimeContext *ctx) = 0;
  virtual void exitDatetime(QueryParser::DatetimeContext *ctx) = 0;

  virtual void enterDate(QueryParser::DateContext *ctx) = 0;
  virtual void exitDate(QueryParser::DateContext *ctx) = 0;

  virtual void enterTime(QueryParser::TimeContext *ctx) = 0;
  virtual void exitTime(QueryParser::TimeContext *ctx) = 0;

  virtual void enterNumber(QueryParser::NumberContext *ctx) = 0;
  virtual void exitNumber(QueryParser::NumberContext *ctx) = 0;

  virtual void enterFrac(QueryParser::FracContext *ctx) = 0;
  virtual void exitFrac(QueryParser::FracContext *ctx) = 0;

  virtual void enterQint(QueryParser::QintContext *ctx) = 0;
  virtual void exitQint(QueryParser::QintContext *ctx) = 0;

  virtual void enterAnydigit(QueryParser::AnydigitContext *ctx) = 0;
  virtual void exitAnydigit(QueryParser::AnydigitContext *ctx) = 0;

  virtual void enterOpeningpar(QueryParser::OpeningparContext *ctx) = 0;
  virtual void exitOpeningpar(QueryParser::OpeningparContext *ctx) = 0;

  virtual void enterClosingpar(QueryParser::ClosingparContext *ctx) = 0;
  virtual void exitClosingpar(QueryParser::ClosingparContext *ctx) = 0;


};

