
// Generated from Query.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  QueryParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, DOTS = 5, DOT = 6, FALSE = 7, 
    TRUE = 8, EQUAL = 9, UNEQUAL = 10, GREATEREQ = 11, GREATER = 12, LESSEQ = 13, 
    LESS = 14, EXP = 15, DOTTEDATTRNAME = 16, ATTRNAME = 17, QUOTE = 18, 
    ZERO = 19, NONZERODIGIT = 20, PLUS = 21, MINUS = 22, OROP = 23, ANDOP = 24, 
    DATE = 25, TIME = 26, DATETIME = 27, URI = 28, SCHEME = 29, URICHAR = 30, 
    PATTERNOP = 31, PATTERNNOOP = 32, OPENINGPAR = 33, CLOSINGPAR = 34, 
    ESCAPEDBACKSLASH = 35, BACKSLASH = 36, OTHERLEXEDCHAR = 37, UNICODE = 38
  };

  enum {
    RuleQuery = 0, RuleQuerytermortermassoc = 1, RuleQuerytermassoc = 2, 
    RuleQueryterm = 3, RuleDottedpath = 4, RuleAttribute = 5, RuleQoperator = 6, 
    RulePatternop = 7, RulePatternnoop = 8, RuleGreatereq = 9, RuleGreater = 10, 
    RuleLess = 11, RuleLesseq = 12, RuleEqual = 13, RuleUnequal = 14, RuleOthervalue = 15, 
    RuleQtrue = 16, RuleQfalse = 17, RuleValue = 18, RuleRange = 19, RuleValuelist = 20, 
    RuleCompequalityvalue = 21, RuleUri = 22, RuleLogicalop = 23, RuleOrop = 24, 
    RuleAndop = 25, RuleComparablevalue = 26, RuleQuotedstr = 27, RuleNotaquote = 28, 
    RuleQuotedstringchar = 29, RuleRegex = 30, RuleRegexchar = 31, RuleNotaparenthesis = 32, 
    RuleDatetime = 33, RuleDate = 34, RuleTime = 35, RuleNumber = 36, RuleFrac = 37, 
    RuleQint = 38, RuleAnydigit = 39, RuleOpeningpar = 40, RuleClosingpar = 41
  };

  explicit QueryParser(antlr4::TokenStream *input);
  ~QueryParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class QueryContext;
  class QuerytermortermassocContext;
  class QuerytermassocContext;
  class QuerytermContext;
  class DottedpathContext;
  class AttributeContext;
  class QoperatorContext;
  class PatternopContext;
  class PatternnoopContext;
  class GreatereqContext;
  class GreaterContext;
  class LessContext;
  class LesseqContext;
  class EqualContext;
  class UnequalContext;
  class OthervalueContext;
  class QtrueContext;
  class QfalseContext;
  class ValueContext;
  class RangeContext;
  class ValuelistContext;
  class CompequalityvalueContext;
  class UriContext;
  class LogicalopContext;
  class OropContext;
  class AndopContext;
  class ComparablevalueContext;
  class QuotedstrContext;
  class NotaquoteContext;
  class QuotedstringcharContext;
  class RegexContext;
  class RegexcharContext;
  class NotaparenthesisContext;
  class DatetimeContext;
  class DateContext;
  class TimeContext;
  class NumberContext;
  class FracContext;
  class QintContext;
  class AnydigitContext;
  class OpeningparContext;
  class ClosingparContext; 

  class  QueryContext : public antlr4::ParserRuleContext {
  public:
    QueryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<QuerytermortermassocContext *> querytermortermassoc();
    QuerytermortermassocContext* querytermortermassoc(size_t i);
    antlr4::tree::TerminalNode *EOF();
    std::vector<LogicalopContext *> logicalop();
    LogicalopContext* logicalop(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  QueryContext* query();

  class  QuerytermortermassocContext : public antlr4::ParserRuleContext {
  public:
    QuerytermortermassocContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QuerytermContext *queryterm();
    QuerytermassocContext *querytermassoc();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  QuerytermortermassocContext* querytermortermassoc();

  class  QuerytermassocContext : public antlr4::ParserRuleContext {
  public:
    QuerytermassocContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OpeningparContext *openingpar();
    std::vector<QuerytermContext *> queryterm();
    QuerytermContext* queryterm(size_t i);
    ClosingparContext *closingpar();
    std::vector<LogicalopContext *> logicalop();
    LogicalopContext* logicalop(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  QuerytermassocContext* querytermassoc();

  class  QuerytermContext : public antlr4::ParserRuleContext {
  public:
    QuerytermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AttributeContext *attribute();
    QoperatorContext *qoperator();
    ComparablevalueContext *comparablevalue();
    EqualContext *equal();
    CompequalityvalueContext *compequalityvalue();
    UnequalContext *unequal();
    PatternopContext *patternop();
    RegexContext *regex();
    PatternnoopContext *patternnoop();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  QuerytermContext* queryterm();

  class  DottedpathContext : public antlr4::ParserRuleContext {
  public:
    DottedpathContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DOTTEDATTRNAME();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DottedpathContext* dottedpath();

  class  AttributeContext : public antlr4::ParserRuleContext {
  public:
    AttributeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<DottedpathContext *> dottedpath();
    DottedpathContext* dottedpath(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AttributeContext* attribute();

  class  QoperatorContext : public antlr4::ParserRuleContext {
  public:
    QoperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    EqualContext *equal();
    UnequalContext *unequal();
    GreatereqContext *greatereq();
    GreaterContext *greater();
    LessContext *less();
    LesseqContext *lesseq();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  QoperatorContext* qoperator();

  class  PatternopContext : public antlr4::ParserRuleContext {
  public:
    PatternopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PATTERNOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PatternopContext* patternop();

  class  PatternnoopContext : public antlr4::ParserRuleContext {
  public:
    PatternnoopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PATTERNNOOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PatternnoopContext* patternnoop();

  class  GreatereqContext : public antlr4::ParserRuleContext {
  public:
    GreatereqContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GREATEREQ();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  GreatereqContext* greatereq();

  class  GreaterContext : public antlr4::ParserRuleContext {
  public:
    GreaterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GREATER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  GreaterContext* greater();

  class  LessContext : public antlr4::ParserRuleContext {
  public:
    LessContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LESS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LessContext* less();

  class  LesseqContext : public antlr4::ParserRuleContext {
  public:
    LesseqContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LESSEQ();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LesseqContext* lesseq();

  class  EqualContext : public antlr4::ParserRuleContext {
  public:
    EqualContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EQUAL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  EqualContext* equal();

  class  UnequalContext : public antlr4::ParserRuleContext {
  public:
    UnequalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UNEQUAL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  UnequalContext* unequal();

  class  OthervalueContext : public antlr4::ParserRuleContext {
  public:
    OthervalueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QfalseContext *qfalse();
    QtrueContext *qtrue();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  OthervalueContext* othervalue();

  class  QtrueContext : public antlr4::ParserRuleContext {
  public:
    QtrueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TRUE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  QtrueContext* qtrue();

  class  QfalseContext : public antlr4::ParserRuleContext {
  public:
    QfalseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FALSE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  QfalseContext* qfalse();

  class  ValueContext : public antlr4::ParserRuleContext {
  public:
    ValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ComparablevalueContext *comparablevalue();
    OthervalueContext *othervalue();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ValueContext* value();

  class  RangeContext : public antlr4::ParserRuleContext {
  public:
    RangeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ComparablevalueContext *> comparablevalue();
    ComparablevalueContext* comparablevalue(size_t i);
    antlr4::tree::TerminalNode *DOTS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RangeContext* range();

  class  ValuelistContext : public antlr4::ParserRuleContext {
  public:
    ValuelistContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ValueContext *> value();
    ValueContext* value(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ValuelistContext* valuelist();

  class  CompequalityvalueContext : public antlr4::ParserRuleContext {
  public:
    CompequalityvalueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OthervalueContext *othervalue();
    ValuelistContext *valuelist();
    RangeContext *range();
    UriContext *uri();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  CompequalityvalueContext* compequalityvalue();

  class  UriContext : public antlr4::ParserRuleContext {
  public:
    UriContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *URI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  UriContext* uri();

  class  LogicalopContext : public antlr4::ParserRuleContext {
  public:
    LogicalopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OropContext *orop();
    AndopContext *andop();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LogicalopContext* logicalop();

  class  OropContext : public antlr4::ParserRuleContext {
  public:
    OropContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OROP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  OropContext* orop();

  class  AndopContext : public antlr4::ParserRuleContext {
  public:
    AndopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ANDOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AndopContext* andop();

  class  ComparablevalueContext : public antlr4::ParserRuleContext {
  public:
    ComparablevalueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NumberContext *number();
    QuotedstrContext *quotedstr();
    DatetimeContext *datetime();
    DateContext *date();
    TimeContext *time();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ComparablevalueContext* comparablevalue();

  class  QuotedstrContext : public antlr4::ParserRuleContext {
  public:
    QuotedstrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> QUOTE();
    antlr4::tree::TerminalNode* QUOTE(size_t i);
    std::vector<QuotedstringcharContext *> quotedstringchar();
    QuotedstringcharContext* quotedstringchar(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  QuotedstrContext* quotedstr();

  class  NotaquoteContext : public antlr4::ParserRuleContext {
  public:
    NotaquoteContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *QUOTE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  NotaquoteContext* notaquote();

  class  QuotedstringcharContext : public antlr4::ParserRuleContext {
  public:
    QuotedstringcharContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NotaquoteContext *notaquote();
    antlr4::tree::TerminalNode *ESCAPEDBACKSLASH();
    antlr4::tree::TerminalNode *BACKSLASH();
    antlr4::tree::TerminalNode *QUOTE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  QuotedstringcharContext* quotedstringchar();

  class  RegexContext : public antlr4::ParserRuleContext {
  public:
    RegexContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CLOSINGPAR();
    std::vector<RegexcharContext *> regexchar();
    RegexcharContext* regexchar(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RegexContext* regex();

  class  RegexcharContext : public antlr4::ParserRuleContext {
  public:
    RegexcharContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NotaparenthesisContext *notaparenthesis();
    antlr4::tree::TerminalNode *BACKSLASH();
    antlr4::tree::TerminalNode *OPENINGPAR();
    antlr4::tree::TerminalNode *CLOSINGPAR();
    antlr4::tree::TerminalNode *ESCAPEDBACKSLASH();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RegexcharContext* regexchar();

  class  NotaparenthesisContext : public antlr4::ParserRuleContext {
  public:
    NotaparenthesisContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPENINGPAR();
    antlr4::tree::TerminalNode *CLOSINGPAR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  NotaparenthesisContext* notaparenthesis();

  class  DatetimeContext : public antlr4::ParserRuleContext {
  public:
    DatetimeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DATETIME();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DatetimeContext* datetime();

  class  DateContext : public antlr4::ParserRuleContext {
  public:
    DateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DATE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DateContext* date();

  class  TimeContext : public antlr4::ParserRuleContext {
  public:
    TimeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TIME();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TimeContext* time();

  class  NumberContext : public antlr4::ParserRuleContext {
  public:
    NumberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QintContext *qint();
    antlr4::tree::TerminalNode *MINUS();
    FracContext *frac();
    antlr4::tree::TerminalNode *EXP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  NumberContext* number();

  class  FracContext : public antlr4::ParserRuleContext {
  public:
    FracContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DOT();
    std::vector<AnydigitContext *> anydigit();
    AnydigitContext* anydigit(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FracContext* frac();

  class  QintContext : public antlr4::ParserRuleContext {
  public:
    QintContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ZERO();
    antlr4::tree::TerminalNode *NONZERODIGIT();
    std::vector<AnydigitContext *> anydigit();
    AnydigitContext* anydigit(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  QintContext* qint();

  class  AnydigitContext : public antlr4::ParserRuleContext {
  public:
    AnydigitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ZERO();
    antlr4::tree::TerminalNode* ZERO(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NONZERODIGIT();
    antlr4::tree::TerminalNode* NONZERODIGIT(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AnydigitContext* anydigit();

  class  OpeningparContext : public antlr4::ParserRuleContext {
  public:
    OpeningparContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPENINGPAR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  OpeningparContext* openingpar();

  class  ClosingparContext : public antlr4::ParserRuleContext {
  public:
    ClosingparContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CLOSINGPAR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ClosingparContext* closingpar();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

