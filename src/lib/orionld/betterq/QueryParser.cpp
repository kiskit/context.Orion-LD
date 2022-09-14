
// Generated from Query.g4 by ANTLR 4.9.2


#include "QueryListener.h"

#include "QueryParser.h"


using namespace antlrcpp;
using namespace antlr4;

QueryParser::QueryParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

QueryParser::~QueryParser() {
  delete _interpreter;
}

std::string QueryParser::getGrammarFileName() const {
  return "Query.g4";
}

const std::vector<std::string>& QueryParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& QueryParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- QueryContext ------------------------------------------------------------------

QueryParser::QueryContext::QueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<QueryParser::QuerytermortermassocContext *> QueryParser::QueryContext::querytermortermassoc() {
  return getRuleContexts<QueryParser::QuerytermortermassocContext>();
}

QueryParser::QuerytermortermassocContext* QueryParser::QueryContext::querytermortermassoc(size_t i) {
  return getRuleContext<QueryParser::QuerytermortermassocContext>(i);
}

tree::TerminalNode* QueryParser::QueryContext::EOF() {
  return getToken(QueryParser::EOF, 0);
}

std::vector<QueryParser::LogicalopContext *> QueryParser::QueryContext::logicalop() {
  return getRuleContexts<QueryParser::LogicalopContext>();
}

QueryParser::LogicalopContext* QueryParser::QueryContext::logicalop(size_t i) {
  return getRuleContext<QueryParser::LogicalopContext>(i);
}


size_t QueryParser::QueryContext::getRuleIndex() const {
  return QueryParser::RuleQuery;
}

void QueryParser::QueryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQuery(this);
}

void QueryParser::QueryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQuery(this);
}

QueryParser::QueryContext* QueryParser::query() {
  QueryContext *_localctx = _tracker.createInstance<QueryContext>(_ctx, getState());
  enterRule(_localctx, 0, QueryParser::RuleQuery);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(84);
    querytermortermassoc();
    setState(90);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == QueryParser::OROP

    || _la == QueryParser::ANDOP) {
      setState(85);
      logicalop();
      setState(86);
      querytermortermassoc();
      setState(92);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(93);
    match(QueryParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuerytermortermassocContext ------------------------------------------------------------------

QueryParser::QuerytermortermassocContext::QuerytermortermassocContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

QueryParser::QuerytermContext* QueryParser::QuerytermortermassocContext::queryterm() {
  return getRuleContext<QueryParser::QuerytermContext>(0);
}

QueryParser::QuerytermassocContext* QueryParser::QuerytermortermassocContext::querytermassoc() {
  return getRuleContext<QueryParser::QuerytermassocContext>(0);
}


size_t QueryParser::QuerytermortermassocContext::getRuleIndex() const {
  return QueryParser::RuleQuerytermortermassoc;
}

void QueryParser::QuerytermortermassocContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQuerytermortermassoc(this);
}

void QueryParser::QuerytermortermassocContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQuerytermortermassoc(this);
}

QueryParser::QuerytermortermassocContext* QueryParser::querytermortermassoc() {
  QuerytermortermassocContext *_localctx = _tracker.createInstance<QuerytermortermassocContext>(_ctx, getState());
  enterRule(_localctx, 2, QueryParser::RuleQuerytermortermassoc);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(97);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case QueryParser::DOTTEDATTRNAME: {
        enterOuterAlt(_localctx, 1);
        setState(95);
        queryterm();
        break;
      }

      case QueryParser::OPENINGPAR: {
        enterOuterAlt(_localctx, 2);
        setState(96);
        querytermassoc();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuerytermassocContext ------------------------------------------------------------------

QueryParser::QuerytermassocContext::QuerytermassocContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

QueryParser::OpeningparContext* QueryParser::QuerytermassocContext::openingpar() {
  return getRuleContext<QueryParser::OpeningparContext>(0);
}

std::vector<QueryParser::QuerytermContext *> QueryParser::QuerytermassocContext::queryterm() {
  return getRuleContexts<QueryParser::QuerytermContext>();
}

QueryParser::QuerytermContext* QueryParser::QuerytermassocContext::queryterm(size_t i) {
  return getRuleContext<QueryParser::QuerytermContext>(i);
}

QueryParser::ClosingparContext* QueryParser::QuerytermassocContext::closingpar() {
  return getRuleContext<QueryParser::ClosingparContext>(0);
}

std::vector<QueryParser::LogicalopContext *> QueryParser::QuerytermassocContext::logicalop() {
  return getRuleContexts<QueryParser::LogicalopContext>();
}

QueryParser::LogicalopContext* QueryParser::QuerytermassocContext::logicalop(size_t i) {
  return getRuleContext<QueryParser::LogicalopContext>(i);
}


size_t QueryParser::QuerytermassocContext::getRuleIndex() const {
  return QueryParser::RuleQuerytermassoc;
}

void QueryParser::QuerytermassocContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQuerytermassoc(this);
}

void QueryParser::QuerytermassocContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQuerytermassoc(this);
}

QueryParser::QuerytermassocContext* QueryParser::querytermassoc() {
  QuerytermassocContext *_localctx = _tracker.createInstance<QuerytermassocContext>(_ctx, getState());
  enterRule(_localctx, 4, QueryParser::RuleQuerytermassoc);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(99);
    openingpar();
    setState(100);
    queryterm();
    setState(106);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == QueryParser::OROP

    || _la == QueryParser::ANDOP) {
      setState(101);
      logicalop();
      setState(102);
      queryterm();
      setState(108);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(109);
    closingpar();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuerytermContext ------------------------------------------------------------------

QueryParser::QuerytermContext::QuerytermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

QueryParser::AttributeContext* QueryParser::QuerytermContext::attribute() {
  return getRuleContext<QueryParser::AttributeContext>(0);
}

QueryParser::QoperatorContext* QueryParser::QuerytermContext::qoperator() {
  return getRuleContext<QueryParser::QoperatorContext>(0);
}

QueryParser::ComparablevalueContext* QueryParser::QuerytermContext::comparablevalue() {
  return getRuleContext<QueryParser::ComparablevalueContext>(0);
}

QueryParser::EqualContext* QueryParser::QuerytermContext::equal() {
  return getRuleContext<QueryParser::EqualContext>(0);
}

QueryParser::CompequalityvalueContext* QueryParser::QuerytermContext::compequalityvalue() {
  return getRuleContext<QueryParser::CompequalityvalueContext>(0);
}

QueryParser::UnequalContext* QueryParser::QuerytermContext::unequal() {
  return getRuleContext<QueryParser::UnequalContext>(0);
}

QueryParser::PatternopContext* QueryParser::QuerytermContext::patternop() {
  return getRuleContext<QueryParser::PatternopContext>(0);
}

QueryParser::RegexContext* QueryParser::QuerytermContext::regex() {
  return getRuleContext<QueryParser::RegexContext>(0);
}

QueryParser::PatternnoopContext* QueryParser::QuerytermContext::patternnoop() {
  return getRuleContext<QueryParser::PatternnoopContext>(0);
}


size_t QueryParser::QuerytermContext::getRuleIndex() const {
  return QueryParser::RuleQueryterm;
}

void QueryParser::QuerytermContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQueryterm(this);
}

void QueryParser::QuerytermContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQueryterm(this);
}

QueryParser::QuerytermContext* QueryParser::queryterm() {
  QuerytermContext *_localctx = _tracker.createInstance<QuerytermContext>(_ctx, getState());
  enterRule(_localctx, 6, QueryParser::RuleQueryterm);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(132);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(111);
      attribute();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(112);
      attribute();
      setState(113);
      qoperator();
      setState(114);
      comparablevalue();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(116);
      attribute();
      setState(117);
      equal();
      setState(118);
      compequalityvalue();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(120);
      attribute();
      setState(121);
      unequal();
      setState(122);
      compequalityvalue();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(124);
      attribute();
      setState(125);
      patternop();
      setState(126);
      regex();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(128);
      attribute();
      setState(129);
      patternnoop();
      setState(130);
      regex();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DottedpathContext ------------------------------------------------------------------

QueryParser::DottedpathContext::DottedpathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QueryParser::DottedpathContext::DOTTEDATTRNAME() {
  return getToken(QueryParser::DOTTEDATTRNAME, 0);
}


size_t QueryParser::DottedpathContext::getRuleIndex() const {
  return QueryParser::RuleDottedpath;
}

void QueryParser::DottedpathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDottedpath(this);
}

void QueryParser::DottedpathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDottedpath(this);
}

QueryParser::DottedpathContext* QueryParser::dottedpath() {
  DottedpathContext *_localctx = _tracker.createInstance<DottedpathContext>(_ctx, getState());
  enterRule(_localctx, 8, QueryParser::RuleDottedpath);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(134);
    match(QueryParser::DOTTEDATTRNAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AttributeContext ------------------------------------------------------------------

QueryParser::AttributeContext::AttributeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<QueryParser::DottedpathContext *> QueryParser::AttributeContext::dottedpath() {
  return getRuleContexts<QueryParser::DottedpathContext>();
}

QueryParser::DottedpathContext* QueryParser::AttributeContext::dottedpath(size_t i) {
  return getRuleContext<QueryParser::DottedpathContext>(i);
}


size_t QueryParser::AttributeContext::getRuleIndex() const {
  return QueryParser::RuleAttribute;
}

void QueryParser::AttributeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttribute(this);
}

void QueryParser::AttributeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttribute(this);
}

QueryParser::AttributeContext* QueryParser::attribute() {
  AttributeContext *_localctx = _tracker.createInstance<AttributeContext>(_ctx, getState());
  enterRule(_localctx, 10, QueryParser::RuleAttribute);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(136);
    dottedpath();
    setState(141);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == QueryParser::T__0) {
      setState(137);
      match(QueryParser::T__0);
      setState(138);
      dottedpath();
      setState(139);
      match(QueryParser::T__1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QoperatorContext ------------------------------------------------------------------

QueryParser::QoperatorContext::QoperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

QueryParser::EqualContext* QueryParser::QoperatorContext::equal() {
  return getRuleContext<QueryParser::EqualContext>(0);
}

QueryParser::UnequalContext* QueryParser::QoperatorContext::unequal() {
  return getRuleContext<QueryParser::UnequalContext>(0);
}

QueryParser::GreatereqContext* QueryParser::QoperatorContext::greatereq() {
  return getRuleContext<QueryParser::GreatereqContext>(0);
}

QueryParser::GreaterContext* QueryParser::QoperatorContext::greater() {
  return getRuleContext<QueryParser::GreaterContext>(0);
}

QueryParser::LessContext* QueryParser::QoperatorContext::less() {
  return getRuleContext<QueryParser::LessContext>(0);
}

QueryParser::LesseqContext* QueryParser::QoperatorContext::lesseq() {
  return getRuleContext<QueryParser::LesseqContext>(0);
}


size_t QueryParser::QoperatorContext::getRuleIndex() const {
  return QueryParser::RuleQoperator;
}

void QueryParser::QoperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQoperator(this);
}

void QueryParser::QoperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQoperator(this);
}

QueryParser::QoperatorContext* QueryParser::qoperator() {
  QoperatorContext *_localctx = _tracker.createInstance<QoperatorContext>(_ctx, getState());
  enterRule(_localctx, 12, QueryParser::RuleQoperator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(149);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case QueryParser::EQUAL: {
        enterOuterAlt(_localctx, 1);
        setState(143);
        equal();
        break;
      }

      case QueryParser::UNEQUAL: {
        enterOuterAlt(_localctx, 2);
        setState(144);
        unequal();
        break;
      }

      case QueryParser::GREATEREQ: {
        enterOuterAlt(_localctx, 3);
        setState(145);
        greatereq();
        break;
      }

      case QueryParser::GREATER: {
        enterOuterAlt(_localctx, 4);
        setState(146);
        greater();
        break;
      }

      case QueryParser::LESS: {
        enterOuterAlt(_localctx, 5);
        setState(147);
        less();
        break;
      }

      case QueryParser::LESSEQ: {
        enterOuterAlt(_localctx, 6);
        setState(148);
        lesseq();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PatternopContext ------------------------------------------------------------------

QueryParser::PatternopContext::PatternopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QueryParser::PatternopContext::PATTERNOP() {
  return getToken(QueryParser::PATTERNOP, 0);
}


size_t QueryParser::PatternopContext::getRuleIndex() const {
  return QueryParser::RulePatternop;
}

void QueryParser::PatternopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPatternop(this);
}

void QueryParser::PatternopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPatternop(this);
}

QueryParser::PatternopContext* QueryParser::patternop() {
  PatternopContext *_localctx = _tracker.createInstance<PatternopContext>(_ctx, getState());
  enterRule(_localctx, 14, QueryParser::RulePatternop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(151);
    match(QueryParser::PATTERNOP);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PatternnoopContext ------------------------------------------------------------------

QueryParser::PatternnoopContext::PatternnoopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QueryParser::PatternnoopContext::PATTERNNOOP() {
  return getToken(QueryParser::PATTERNNOOP, 0);
}


size_t QueryParser::PatternnoopContext::getRuleIndex() const {
  return QueryParser::RulePatternnoop;
}

void QueryParser::PatternnoopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPatternnoop(this);
}

void QueryParser::PatternnoopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPatternnoop(this);
}

QueryParser::PatternnoopContext* QueryParser::patternnoop() {
  PatternnoopContext *_localctx = _tracker.createInstance<PatternnoopContext>(_ctx, getState());
  enterRule(_localctx, 16, QueryParser::RulePatternnoop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(153);
    match(QueryParser::PATTERNNOOP);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GreatereqContext ------------------------------------------------------------------

QueryParser::GreatereqContext::GreatereqContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QueryParser::GreatereqContext::GREATEREQ() {
  return getToken(QueryParser::GREATEREQ, 0);
}


size_t QueryParser::GreatereqContext::getRuleIndex() const {
  return QueryParser::RuleGreatereq;
}

void QueryParser::GreatereqContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGreatereq(this);
}

void QueryParser::GreatereqContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGreatereq(this);
}

QueryParser::GreatereqContext* QueryParser::greatereq() {
  GreatereqContext *_localctx = _tracker.createInstance<GreatereqContext>(_ctx, getState());
  enterRule(_localctx, 18, QueryParser::RuleGreatereq);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(155);
    match(QueryParser::GREATEREQ);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GreaterContext ------------------------------------------------------------------

QueryParser::GreaterContext::GreaterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QueryParser::GreaterContext::GREATER() {
  return getToken(QueryParser::GREATER, 0);
}


size_t QueryParser::GreaterContext::getRuleIndex() const {
  return QueryParser::RuleGreater;
}

void QueryParser::GreaterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGreater(this);
}

void QueryParser::GreaterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGreater(this);
}

QueryParser::GreaterContext* QueryParser::greater() {
  GreaterContext *_localctx = _tracker.createInstance<GreaterContext>(_ctx, getState());
  enterRule(_localctx, 20, QueryParser::RuleGreater);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(157);
    match(QueryParser::GREATER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LessContext ------------------------------------------------------------------

QueryParser::LessContext::LessContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QueryParser::LessContext::LESS() {
  return getToken(QueryParser::LESS, 0);
}


size_t QueryParser::LessContext::getRuleIndex() const {
  return QueryParser::RuleLess;
}

void QueryParser::LessContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLess(this);
}

void QueryParser::LessContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLess(this);
}

QueryParser::LessContext* QueryParser::less() {
  LessContext *_localctx = _tracker.createInstance<LessContext>(_ctx, getState());
  enterRule(_localctx, 22, QueryParser::RuleLess);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(159);
    match(QueryParser::LESS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LesseqContext ------------------------------------------------------------------

QueryParser::LesseqContext::LesseqContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QueryParser::LesseqContext::LESSEQ() {
  return getToken(QueryParser::LESSEQ, 0);
}


size_t QueryParser::LesseqContext::getRuleIndex() const {
  return QueryParser::RuleLesseq;
}

void QueryParser::LesseqContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLesseq(this);
}

void QueryParser::LesseqContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLesseq(this);
}

QueryParser::LesseqContext* QueryParser::lesseq() {
  LesseqContext *_localctx = _tracker.createInstance<LesseqContext>(_ctx, getState());
  enterRule(_localctx, 24, QueryParser::RuleLesseq);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(161);
    match(QueryParser::LESSEQ);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EqualContext ------------------------------------------------------------------

QueryParser::EqualContext::EqualContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QueryParser::EqualContext::EQUAL() {
  return getToken(QueryParser::EQUAL, 0);
}


size_t QueryParser::EqualContext::getRuleIndex() const {
  return QueryParser::RuleEqual;
}

void QueryParser::EqualContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqual(this);
}

void QueryParser::EqualContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqual(this);
}

QueryParser::EqualContext* QueryParser::equal() {
  EqualContext *_localctx = _tracker.createInstance<EqualContext>(_ctx, getState());
  enterRule(_localctx, 26, QueryParser::RuleEqual);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(163);
    match(QueryParser::EQUAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnequalContext ------------------------------------------------------------------

QueryParser::UnequalContext::UnequalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QueryParser::UnequalContext::UNEQUAL() {
  return getToken(QueryParser::UNEQUAL, 0);
}


size_t QueryParser::UnequalContext::getRuleIndex() const {
  return QueryParser::RuleUnequal;
}

void QueryParser::UnequalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnequal(this);
}

void QueryParser::UnequalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnequal(this);
}

QueryParser::UnequalContext* QueryParser::unequal() {
  UnequalContext *_localctx = _tracker.createInstance<UnequalContext>(_ctx, getState());
  enterRule(_localctx, 28, QueryParser::RuleUnequal);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(165);
    match(QueryParser::UNEQUAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OthervalueContext ------------------------------------------------------------------

QueryParser::OthervalueContext::OthervalueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

QueryParser::QfalseContext* QueryParser::OthervalueContext::qfalse() {
  return getRuleContext<QueryParser::QfalseContext>(0);
}

QueryParser::QtrueContext* QueryParser::OthervalueContext::qtrue() {
  return getRuleContext<QueryParser::QtrueContext>(0);
}


size_t QueryParser::OthervalueContext::getRuleIndex() const {
  return QueryParser::RuleOthervalue;
}

void QueryParser::OthervalueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOthervalue(this);
}

void QueryParser::OthervalueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOthervalue(this);
}

QueryParser::OthervalueContext* QueryParser::othervalue() {
  OthervalueContext *_localctx = _tracker.createInstance<OthervalueContext>(_ctx, getState());
  enterRule(_localctx, 30, QueryParser::RuleOthervalue);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(169);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case QueryParser::FALSE: {
        enterOuterAlt(_localctx, 1);
        setState(167);
        qfalse();
        break;
      }

      case QueryParser::TRUE: {
        enterOuterAlt(_localctx, 2);
        setState(168);
        qtrue();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QtrueContext ------------------------------------------------------------------

QueryParser::QtrueContext::QtrueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QueryParser::QtrueContext::TRUE() {
  return getToken(QueryParser::TRUE, 0);
}


size_t QueryParser::QtrueContext::getRuleIndex() const {
  return QueryParser::RuleQtrue;
}

void QueryParser::QtrueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQtrue(this);
}

void QueryParser::QtrueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQtrue(this);
}

QueryParser::QtrueContext* QueryParser::qtrue() {
  QtrueContext *_localctx = _tracker.createInstance<QtrueContext>(_ctx, getState());
  enterRule(_localctx, 32, QueryParser::RuleQtrue);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(171);
    match(QueryParser::TRUE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QfalseContext ------------------------------------------------------------------

QueryParser::QfalseContext::QfalseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QueryParser::QfalseContext::FALSE() {
  return getToken(QueryParser::FALSE, 0);
}


size_t QueryParser::QfalseContext::getRuleIndex() const {
  return QueryParser::RuleQfalse;
}

void QueryParser::QfalseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQfalse(this);
}

void QueryParser::QfalseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQfalse(this);
}

QueryParser::QfalseContext* QueryParser::qfalse() {
  QfalseContext *_localctx = _tracker.createInstance<QfalseContext>(_ctx, getState());
  enterRule(_localctx, 34, QueryParser::RuleQfalse);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(173);
    match(QueryParser::FALSE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValueContext ------------------------------------------------------------------

QueryParser::ValueContext::ValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

QueryParser::ComparablevalueContext* QueryParser::ValueContext::comparablevalue() {
  return getRuleContext<QueryParser::ComparablevalueContext>(0);
}

QueryParser::OthervalueContext* QueryParser::ValueContext::othervalue() {
  return getRuleContext<QueryParser::OthervalueContext>(0);
}


size_t QueryParser::ValueContext::getRuleIndex() const {
  return QueryParser::RuleValue;
}

void QueryParser::ValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValue(this);
}

void QueryParser::ValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValue(this);
}

QueryParser::ValueContext* QueryParser::value() {
  ValueContext *_localctx = _tracker.createInstance<ValueContext>(_ctx, getState());
  enterRule(_localctx, 36, QueryParser::RuleValue);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(177);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case QueryParser::QUOTE:
      case QueryParser::ZERO:
      case QueryParser::NONZERODIGIT:
      case QueryParser::MINUS:
      case QueryParser::DATE:
      case QueryParser::TIME:
      case QueryParser::DATETIME: {
        enterOuterAlt(_localctx, 1);
        setState(175);
        comparablevalue();
        break;
      }

      case QueryParser::FALSE:
      case QueryParser::TRUE: {
        enterOuterAlt(_localctx, 2);
        setState(176);
        othervalue();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RangeContext ------------------------------------------------------------------

QueryParser::RangeContext::RangeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<QueryParser::ComparablevalueContext *> QueryParser::RangeContext::comparablevalue() {
  return getRuleContexts<QueryParser::ComparablevalueContext>();
}

QueryParser::ComparablevalueContext* QueryParser::RangeContext::comparablevalue(size_t i) {
  return getRuleContext<QueryParser::ComparablevalueContext>(i);
}

tree::TerminalNode* QueryParser::RangeContext::DOTS() {
  return getToken(QueryParser::DOTS, 0);
}


size_t QueryParser::RangeContext::getRuleIndex() const {
  return QueryParser::RuleRange;
}

void QueryParser::RangeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRange(this);
}

void QueryParser::RangeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRange(this);
}

QueryParser::RangeContext* QueryParser::range() {
  RangeContext *_localctx = _tracker.createInstance<RangeContext>(_ctx, getState());
  enterRule(_localctx, 38, QueryParser::RuleRange);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(179);
    comparablevalue();
    setState(180);
    match(QueryParser::DOTS);
    setState(181);
    comparablevalue();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValuelistContext ------------------------------------------------------------------

QueryParser::ValuelistContext::ValuelistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<QueryParser::ValueContext *> QueryParser::ValuelistContext::value() {
  return getRuleContexts<QueryParser::ValueContext>();
}

QueryParser::ValueContext* QueryParser::ValuelistContext::value(size_t i) {
  return getRuleContext<QueryParser::ValueContext>(i);
}


size_t QueryParser::ValuelistContext::getRuleIndex() const {
  return QueryParser::RuleValuelist;
}

void QueryParser::ValuelistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValuelist(this);
}

void QueryParser::ValuelistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValuelist(this);
}

QueryParser::ValuelistContext* QueryParser::valuelist() {
  ValuelistContext *_localctx = _tracker.createInstance<ValuelistContext>(_ctx, getState());
  enterRule(_localctx, 40, QueryParser::RuleValuelist);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(183);
    value();
    setState(188);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == QueryParser::T__2) {
      setState(184);
      match(QueryParser::T__2);
      setState(185);
      value();
      setState(190);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompequalityvalueContext ------------------------------------------------------------------

QueryParser::CompequalityvalueContext::CompequalityvalueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

QueryParser::OthervalueContext* QueryParser::CompequalityvalueContext::othervalue() {
  return getRuleContext<QueryParser::OthervalueContext>(0);
}

QueryParser::ValuelistContext* QueryParser::CompequalityvalueContext::valuelist() {
  return getRuleContext<QueryParser::ValuelistContext>(0);
}

QueryParser::RangeContext* QueryParser::CompequalityvalueContext::range() {
  return getRuleContext<QueryParser::RangeContext>(0);
}

QueryParser::UriContext* QueryParser::CompequalityvalueContext::uri() {
  return getRuleContext<QueryParser::UriContext>(0);
}


size_t QueryParser::CompequalityvalueContext::getRuleIndex() const {
  return QueryParser::RuleCompequalityvalue;
}

void QueryParser::CompequalityvalueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompequalityvalue(this);
}

void QueryParser::CompequalityvalueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompequalityvalue(this);
}

QueryParser::CompequalityvalueContext* QueryParser::compequalityvalue() {
  CompequalityvalueContext *_localctx = _tracker.createInstance<CompequalityvalueContext>(_ctx, getState());
  enterRule(_localctx, 42, QueryParser::RuleCompequalityvalue);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(195);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(191);
      othervalue();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(192);
      valuelist();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(193);
      range();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(194);
      uri();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UriContext ------------------------------------------------------------------

QueryParser::UriContext::UriContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QueryParser::UriContext::URI() {
  return getToken(QueryParser::URI, 0);
}


size_t QueryParser::UriContext::getRuleIndex() const {
  return QueryParser::RuleUri;
}

void QueryParser::UriContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUri(this);
}

void QueryParser::UriContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUri(this);
}

QueryParser::UriContext* QueryParser::uri() {
  UriContext *_localctx = _tracker.createInstance<UriContext>(_ctx, getState());
  enterRule(_localctx, 44, QueryParser::RuleUri);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(197);
    match(QueryParser::URI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LogicalopContext ------------------------------------------------------------------

QueryParser::LogicalopContext::LogicalopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

QueryParser::OropContext* QueryParser::LogicalopContext::orop() {
  return getRuleContext<QueryParser::OropContext>(0);
}

QueryParser::AndopContext* QueryParser::LogicalopContext::andop() {
  return getRuleContext<QueryParser::AndopContext>(0);
}


size_t QueryParser::LogicalopContext::getRuleIndex() const {
  return QueryParser::RuleLogicalop;
}

void QueryParser::LogicalopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalop(this);
}

void QueryParser::LogicalopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalop(this);
}

QueryParser::LogicalopContext* QueryParser::logicalop() {
  LogicalopContext *_localctx = _tracker.createInstance<LogicalopContext>(_ctx, getState());
  enterRule(_localctx, 46, QueryParser::RuleLogicalop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(201);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case QueryParser::OROP: {
        enterOuterAlt(_localctx, 1);
        setState(199);
        orop();
        break;
      }

      case QueryParser::ANDOP: {
        enterOuterAlt(_localctx, 2);
        setState(200);
        andop();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OropContext ------------------------------------------------------------------

QueryParser::OropContext::OropContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QueryParser::OropContext::OROP() {
  return getToken(QueryParser::OROP, 0);
}


size_t QueryParser::OropContext::getRuleIndex() const {
  return QueryParser::RuleOrop;
}

void QueryParser::OropContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOrop(this);
}

void QueryParser::OropContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOrop(this);
}

QueryParser::OropContext* QueryParser::orop() {
  OropContext *_localctx = _tracker.createInstance<OropContext>(_ctx, getState());
  enterRule(_localctx, 48, QueryParser::RuleOrop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(203);
    match(QueryParser::OROP);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AndopContext ------------------------------------------------------------------

QueryParser::AndopContext::AndopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QueryParser::AndopContext::ANDOP() {
  return getToken(QueryParser::ANDOP, 0);
}


size_t QueryParser::AndopContext::getRuleIndex() const {
  return QueryParser::RuleAndop;
}

void QueryParser::AndopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAndop(this);
}

void QueryParser::AndopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAndop(this);
}

QueryParser::AndopContext* QueryParser::andop() {
  AndopContext *_localctx = _tracker.createInstance<AndopContext>(_ctx, getState());
  enterRule(_localctx, 50, QueryParser::RuleAndop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(205);
    match(QueryParser::ANDOP);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ComparablevalueContext ------------------------------------------------------------------

QueryParser::ComparablevalueContext::ComparablevalueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

QueryParser::NumberContext* QueryParser::ComparablevalueContext::number() {
  return getRuleContext<QueryParser::NumberContext>(0);
}

QueryParser::QuotedstrContext* QueryParser::ComparablevalueContext::quotedstr() {
  return getRuleContext<QueryParser::QuotedstrContext>(0);
}

QueryParser::DatetimeContext* QueryParser::ComparablevalueContext::datetime() {
  return getRuleContext<QueryParser::DatetimeContext>(0);
}

QueryParser::DateContext* QueryParser::ComparablevalueContext::date() {
  return getRuleContext<QueryParser::DateContext>(0);
}

QueryParser::TimeContext* QueryParser::ComparablevalueContext::time() {
  return getRuleContext<QueryParser::TimeContext>(0);
}


size_t QueryParser::ComparablevalueContext::getRuleIndex() const {
  return QueryParser::RuleComparablevalue;
}

void QueryParser::ComparablevalueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComparablevalue(this);
}

void QueryParser::ComparablevalueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComparablevalue(this);
}

QueryParser::ComparablevalueContext* QueryParser::comparablevalue() {
  ComparablevalueContext *_localctx = _tracker.createInstance<ComparablevalueContext>(_ctx, getState());
  enterRule(_localctx, 52, QueryParser::RuleComparablevalue);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(212);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case QueryParser::ZERO:
      case QueryParser::NONZERODIGIT:
      case QueryParser::MINUS: {
        enterOuterAlt(_localctx, 1);
        setState(207);
        number();
        break;
      }

      case QueryParser::QUOTE: {
        enterOuterAlt(_localctx, 2);
        setState(208);
        quotedstr();
        break;
      }

      case QueryParser::DATETIME: {
        enterOuterAlt(_localctx, 3);
        setState(209);
        datetime();
        break;
      }

      case QueryParser::DATE: {
        enterOuterAlt(_localctx, 4);
        setState(210);
        date();
        break;
      }

      case QueryParser::TIME: {
        enterOuterAlt(_localctx, 5);
        setState(211);
        time();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuotedstrContext ------------------------------------------------------------------

QueryParser::QuotedstrContext::QuotedstrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> QueryParser::QuotedstrContext::QUOTE() {
  return getTokens(QueryParser::QUOTE);
}

tree::TerminalNode* QueryParser::QuotedstrContext::QUOTE(size_t i) {
  return getToken(QueryParser::QUOTE, i);
}

std::vector<QueryParser::QuotedstringcharContext *> QueryParser::QuotedstrContext::quotedstringchar() {
  return getRuleContexts<QueryParser::QuotedstringcharContext>();
}

QueryParser::QuotedstringcharContext* QueryParser::QuotedstrContext::quotedstringchar(size_t i) {
  return getRuleContext<QueryParser::QuotedstringcharContext>(i);
}


size_t QueryParser::QuotedstrContext::getRuleIndex() const {
  return QueryParser::RuleQuotedstr;
}

void QueryParser::QuotedstrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQuotedstr(this);
}

void QueryParser::QuotedstrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQuotedstr(this);
}

QueryParser::QuotedstrContext* QueryParser::quotedstr() {
  QuotedstrContext *_localctx = _tracker.createInstance<QuotedstrContext>(_ctx, getState());
  enterRule(_localctx, 54, QueryParser::RuleQuotedstr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(214);
    match(QueryParser::QUOTE);
    setState(216); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(215);
      quotedstringchar();
      setState(218); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << QueryParser::T__0)
      | (1ULL << QueryParser::T__1)
      | (1ULL << QueryParser::T__2)
      | (1ULL << QueryParser::T__3)
      | (1ULL << QueryParser::DOTS)
      | (1ULL << QueryParser::DOT)
      | (1ULL << QueryParser::FALSE)
      | (1ULL << QueryParser::TRUE)
      | (1ULL << QueryParser::EQUAL)
      | (1ULL << QueryParser::UNEQUAL)
      | (1ULL << QueryParser::GREATEREQ)
      | (1ULL << QueryParser::GREATER)
      | (1ULL << QueryParser::LESSEQ)
      | (1ULL << QueryParser::LESS)
      | (1ULL << QueryParser::EXP)
      | (1ULL << QueryParser::DOTTEDATTRNAME)
      | (1ULL << QueryParser::ATTRNAME)
      | (1ULL << QueryParser::ZERO)
      | (1ULL << QueryParser::NONZERODIGIT)
      | (1ULL << QueryParser::PLUS)
      | (1ULL << QueryParser::MINUS)
      | (1ULL << QueryParser::OROP)
      | (1ULL << QueryParser::ANDOP)
      | (1ULL << QueryParser::DATE)
      | (1ULL << QueryParser::TIME)
      | (1ULL << QueryParser::DATETIME)
      | (1ULL << QueryParser::URI)
      | (1ULL << QueryParser::SCHEME)
      | (1ULL << QueryParser::URICHAR)
      | (1ULL << QueryParser::PATTERNOP)
      | (1ULL << QueryParser::PATTERNNOOP)
      | (1ULL << QueryParser::OPENINGPAR)
      | (1ULL << QueryParser::CLOSINGPAR)
      | (1ULL << QueryParser::ESCAPEDBACKSLASH)
      | (1ULL << QueryParser::BACKSLASH)
      | (1ULL << QueryParser::OTHERLEXEDCHAR)
      | (1ULL << QueryParser::UNICODE))) != 0));
    setState(220);
    match(QueryParser::QUOTE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NotaquoteContext ------------------------------------------------------------------

QueryParser::NotaquoteContext::NotaquoteContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QueryParser::NotaquoteContext::QUOTE() {
  return getToken(QueryParser::QUOTE, 0);
}


size_t QueryParser::NotaquoteContext::getRuleIndex() const {
  return QueryParser::RuleNotaquote;
}

void QueryParser::NotaquoteContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNotaquote(this);
}

void QueryParser::NotaquoteContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNotaquote(this);
}

QueryParser::NotaquoteContext* QueryParser::notaquote() {
  NotaquoteContext *_localctx = _tracker.createInstance<NotaquoteContext>(_ctx, getState());
  enterRule(_localctx, 56, QueryParser::RuleNotaquote);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(222);
    _la = _input->LA(1);
    if (_la == 0 || _la == Token::EOF || (_la == QueryParser::QUOTE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuotedstringcharContext ------------------------------------------------------------------

QueryParser::QuotedstringcharContext::QuotedstringcharContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

QueryParser::NotaquoteContext* QueryParser::QuotedstringcharContext::notaquote() {
  return getRuleContext<QueryParser::NotaquoteContext>(0);
}

tree::TerminalNode* QueryParser::QuotedstringcharContext::ESCAPEDBACKSLASH() {
  return getToken(QueryParser::ESCAPEDBACKSLASH, 0);
}

tree::TerminalNode* QueryParser::QuotedstringcharContext::BACKSLASH() {
  return getToken(QueryParser::BACKSLASH, 0);
}

tree::TerminalNode* QueryParser::QuotedstringcharContext::QUOTE() {
  return getToken(QueryParser::QUOTE, 0);
}


size_t QueryParser::QuotedstringcharContext::getRuleIndex() const {
  return QueryParser::RuleQuotedstringchar;
}

void QueryParser::QuotedstringcharContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQuotedstringchar(this);
}

void QueryParser::QuotedstringcharContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQuotedstringchar(this);
}

QueryParser::QuotedstringcharContext* QueryParser::quotedstringchar() {
  QuotedstringcharContext *_localctx = _tracker.createInstance<QuotedstringcharContext>(_ctx, getState());
  enterRule(_localctx, 58, QueryParser::RuleQuotedstringchar);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(228);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(224);
      notaquote();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(225);
      match(QueryParser::ESCAPEDBACKSLASH);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(226);
      match(QueryParser::BACKSLASH);
      setState(227);
      match(QueryParser::QUOTE);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RegexContext ------------------------------------------------------------------

QueryParser::RegexContext::RegexContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QueryParser::RegexContext::CLOSINGPAR() {
  return getToken(QueryParser::CLOSINGPAR, 0);
}

std::vector<QueryParser::RegexcharContext *> QueryParser::RegexContext::regexchar() {
  return getRuleContexts<QueryParser::RegexcharContext>();
}

QueryParser::RegexcharContext* QueryParser::RegexContext::regexchar(size_t i) {
  return getRuleContext<QueryParser::RegexcharContext>(i);
}


size_t QueryParser::RegexContext::getRuleIndex() const {
  return QueryParser::RuleRegex;
}

void QueryParser::RegexContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRegex(this);
}

void QueryParser::RegexContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRegex(this);
}

QueryParser::RegexContext* QueryParser::regex() {
  RegexContext *_localctx = _tracker.createInstance<RegexContext>(_ctx, getState());
  enterRule(_localctx, 60, QueryParser::RuleRegex);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(230);
    match(QueryParser::T__3);
    setState(232); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(231);
      regexchar();
      setState(234); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << QueryParser::T__0)
      | (1ULL << QueryParser::T__1)
      | (1ULL << QueryParser::T__2)
      | (1ULL << QueryParser::T__3)
      | (1ULL << QueryParser::DOTS)
      | (1ULL << QueryParser::DOT)
      | (1ULL << QueryParser::FALSE)
      | (1ULL << QueryParser::TRUE)
      | (1ULL << QueryParser::EQUAL)
      | (1ULL << QueryParser::UNEQUAL)
      | (1ULL << QueryParser::GREATEREQ)
      | (1ULL << QueryParser::GREATER)
      | (1ULL << QueryParser::LESSEQ)
      | (1ULL << QueryParser::LESS)
      | (1ULL << QueryParser::EXP)
      | (1ULL << QueryParser::DOTTEDATTRNAME)
      | (1ULL << QueryParser::ATTRNAME)
      | (1ULL << QueryParser::QUOTE)
      | (1ULL << QueryParser::ZERO)
      | (1ULL << QueryParser::NONZERODIGIT)
      | (1ULL << QueryParser::PLUS)
      | (1ULL << QueryParser::MINUS)
      | (1ULL << QueryParser::OROP)
      | (1ULL << QueryParser::ANDOP)
      | (1ULL << QueryParser::DATE)
      | (1ULL << QueryParser::TIME)
      | (1ULL << QueryParser::DATETIME)
      | (1ULL << QueryParser::URI)
      | (1ULL << QueryParser::SCHEME)
      | (1ULL << QueryParser::URICHAR)
      | (1ULL << QueryParser::PATTERNOP)
      | (1ULL << QueryParser::PATTERNNOOP)
      | (1ULL << QueryParser::ESCAPEDBACKSLASH)
      | (1ULL << QueryParser::BACKSLASH)
      | (1ULL << QueryParser::OTHERLEXEDCHAR)
      | (1ULL << QueryParser::UNICODE))) != 0));
    setState(236);
    match(QueryParser::CLOSINGPAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RegexcharContext ------------------------------------------------------------------

QueryParser::RegexcharContext::RegexcharContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

QueryParser::NotaparenthesisContext* QueryParser::RegexcharContext::notaparenthesis() {
  return getRuleContext<QueryParser::NotaparenthesisContext>(0);
}

tree::TerminalNode* QueryParser::RegexcharContext::BACKSLASH() {
  return getToken(QueryParser::BACKSLASH, 0);
}

tree::TerminalNode* QueryParser::RegexcharContext::OPENINGPAR() {
  return getToken(QueryParser::OPENINGPAR, 0);
}

tree::TerminalNode* QueryParser::RegexcharContext::CLOSINGPAR() {
  return getToken(QueryParser::CLOSINGPAR, 0);
}

tree::TerminalNode* QueryParser::RegexcharContext::ESCAPEDBACKSLASH() {
  return getToken(QueryParser::ESCAPEDBACKSLASH, 0);
}


size_t QueryParser::RegexcharContext::getRuleIndex() const {
  return QueryParser::RuleRegexchar;
}

void QueryParser::RegexcharContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRegexchar(this);
}

void QueryParser::RegexcharContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRegexchar(this);
}

QueryParser::RegexcharContext* QueryParser::regexchar() {
  RegexcharContext *_localctx = _tracker.createInstance<RegexcharContext>(_ctx, getState());
  enterRule(_localctx, 62, QueryParser::RuleRegexchar);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(244);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(238);
      notaparenthesis();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(239);
      match(QueryParser::BACKSLASH);
      setState(240);
      match(QueryParser::OPENINGPAR);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(241);
      match(QueryParser::BACKSLASH);
      setState(242);
      match(QueryParser::CLOSINGPAR);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(243);
      match(QueryParser::ESCAPEDBACKSLASH);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NotaparenthesisContext ------------------------------------------------------------------

QueryParser::NotaparenthesisContext::NotaparenthesisContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QueryParser::NotaparenthesisContext::OPENINGPAR() {
  return getToken(QueryParser::OPENINGPAR, 0);
}

tree::TerminalNode* QueryParser::NotaparenthesisContext::CLOSINGPAR() {
  return getToken(QueryParser::CLOSINGPAR, 0);
}


size_t QueryParser::NotaparenthesisContext::getRuleIndex() const {
  return QueryParser::RuleNotaparenthesis;
}

void QueryParser::NotaparenthesisContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNotaparenthesis(this);
}

void QueryParser::NotaparenthesisContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNotaparenthesis(this);
}

QueryParser::NotaparenthesisContext* QueryParser::notaparenthesis() {
  NotaparenthesisContext *_localctx = _tracker.createInstance<NotaparenthesisContext>(_ctx, getState());
  enterRule(_localctx, 64, QueryParser::RuleNotaparenthesis);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(246);
    _la = _input->LA(1);
    if (_la == 0 || _la == Token::EOF || (_la == QueryParser::OPENINGPAR

    || _la == QueryParser::CLOSINGPAR)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DatetimeContext ------------------------------------------------------------------

QueryParser::DatetimeContext::DatetimeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QueryParser::DatetimeContext::DATETIME() {
  return getToken(QueryParser::DATETIME, 0);
}


size_t QueryParser::DatetimeContext::getRuleIndex() const {
  return QueryParser::RuleDatetime;
}

void QueryParser::DatetimeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDatetime(this);
}

void QueryParser::DatetimeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDatetime(this);
}

QueryParser::DatetimeContext* QueryParser::datetime() {
  DatetimeContext *_localctx = _tracker.createInstance<DatetimeContext>(_ctx, getState());
  enterRule(_localctx, 66, QueryParser::RuleDatetime);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(248);
    match(QueryParser::DATETIME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DateContext ------------------------------------------------------------------

QueryParser::DateContext::DateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QueryParser::DateContext::DATE() {
  return getToken(QueryParser::DATE, 0);
}


size_t QueryParser::DateContext::getRuleIndex() const {
  return QueryParser::RuleDate;
}

void QueryParser::DateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDate(this);
}

void QueryParser::DateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDate(this);
}

QueryParser::DateContext* QueryParser::date() {
  DateContext *_localctx = _tracker.createInstance<DateContext>(_ctx, getState());
  enterRule(_localctx, 68, QueryParser::RuleDate);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(250);
    match(QueryParser::DATE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TimeContext ------------------------------------------------------------------

QueryParser::TimeContext::TimeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QueryParser::TimeContext::TIME() {
  return getToken(QueryParser::TIME, 0);
}


size_t QueryParser::TimeContext::getRuleIndex() const {
  return QueryParser::RuleTime;
}

void QueryParser::TimeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTime(this);
}

void QueryParser::TimeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTime(this);
}

QueryParser::TimeContext* QueryParser::time() {
  TimeContext *_localctx = _tracker.createInstance<TimeContext>(_ctx, getState());
  enterRule(_localctx, 70, QueryParser::RuleTime);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(252);
    match(QueryParser::TIME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberContext ------------------------------------------------------------------

QueryParser::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

QueryParser::QintContext* QueryParser::NumberContext::qint() {
  return getRuleContext<QueryParser::QintContext>(0);
}

tree::TerminalNode* QueryParser::NumberContext::MINUS() {
  return getToken(QueryParser::MINUS, 0);
}

QueryParser::FracContext* QueryParser::NumberContext::frac() {
  return getRuleContext<QueryParser::FracContext>(0);
}

tree::TerminalNode* QueryParser::NumberContext::EXP() {
  return getToken(QueryParser::EXP, 0);
}


size_t QueryParser::NumberContext::getRuleIndex() const {
  return QueryParser::RuleNumber;
}

void QueryParser::NumberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumber(this);
}

void QueryParser::NumberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumber(this);
}

QueryParser::NumberContext* QueryParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 72, QueryParser::RuleNumber);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(255);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == QueryParser::MINUS) {
      setState(254);
      match(QueryParser::MINUS);
    }
    setState(257);
    qint();
    setState(259);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == QueryParser::DOT) {
      setState(258);
      frac();
    }
    setState(262);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == QueryParser::EXP) {
      setState(261);
      match(QueryParser::EXP);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FracContext ------------------------------------------------------------------

QueryParser::FracContext::FracContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QueryParser::FracContext::DOT() {
  return getToken(QueryParser::DOT, 0);
}

std::vector<QueryParser::AnydigitContext *> QueryParser::FracContext::anydigit() {
  return getRuleContexts<QueryParser::AnydigitContext>();
}

QueryParser::AnydigitContext* QueryParser::FracContext::anydigit(size_t i) {
  return getRuleContext<QueryParser::AnydigitContext>(i);
}


size_t QueryParser::FracContext::getRuleIndex() const {
  return QueryParser::RuleFrac;
}

void QueryParser::FracContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFrac(this);
}

void QueryParser::FracContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFrac(this);
}

QueryParser::FracContext* QueryParser::frac() {
  FracContext *_localctx = _tracker.createInstance<FracContext>(_ctx, getState());
  enterRule(_localctx, 74, QueryParser::RuleFrac);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(264);
    match(QueryParser::DOT);
    setState(266); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(265);
      anydigit();
      setState(268); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == QueryParser::ZERO

    || _la == QueryParser::NONZERODIGIT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QintContext ------------------------------------------------------------------

QueryParser::QintContext::QintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QueryParser::QintContext::ZERO() {
  return getToken(QueryParser::ZERO, 0);
}

tree::TerminalNode* QueryParser::QintContext::NONZERODIGIT() {
  return getToken(QueryParser::NONZERODIGIT, 0);
}

std::vector<QueryParser::AnydigitContext *> QueryParser::QintContext::anydigit() {
  return getRuleContexts<QueryParser::AnydigitContext>();
}

QueryParser::AnydigitContext* QueryParser::QintContext::anydigit(size_t i) {
  return getRuleContext<QueryParser::AnydigitContext>(i);
}


size_t QueryParser::QintContext::getRuleIndex() const {
  return QueryParser::RuleQint;
}

void QueryParser::QintContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQint(this);
}

void QueryParser::QintContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQint(this);
}

QueryParser::QintContext* QueryParser::qint() {
  QintContext *_localctx = _tracker.createInstance<QintContext>(_ctx, getState());
  enterRule(_localctx, 76, QueryParser::RuleQint);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(278);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case QueryParser::ZERO: {
        enterOuterAlt(_localctx, 1);
        setState(270);
        match(QueryParser::ZERO);
        break;
      }

      case QueryParser::NONZERODIGIT: {
        enterOuterAlt(_localctx, 2);
        setState(271);
        match(QueryParser::NONZERODIGIT);
        setState(275);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == QueryParser::ZERO

        || _la == QueryParser::NONZERODIGIT) {
          setState(272);
          anydigit();
          setState(277);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AnydigitContext ------------------------------------------------------------------

QueryParser::AnydigitContext::AnydigitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> QueryParser::AnydigitContext::ZERO() {
  return getTokens(QueryParser::ZERO);
}

tree::TerminalNode* QueryParser::AnydigitContext::ZERO(size_t i) {
  return getToken(QueryParser::ZERO, i);
}

std::vector<tree::TerminalNode *> QueryParser::AnydigitContext::NONZERODIGIT() {
  return getTokens(QueryParser::NONZERODIGIT);
}

tree::TerminalNode* QueryParser::AnydigitContext::NONZERODIGIT(size_t i) {
  return getToken(QueryParser::NONZERODIGIT, i);
}


size_t QueryParser::AnydigitContext::getRuleIndex() const {
  return QueryParser::RuleAnydigit;
}

void QueryParser::AnydigitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnydigit(this);
}

void QueryParser::AnydigitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnydigit(this);
}

QueryParser::AnydigitContext* QueryParser::anydigit() {
  AnydigitContext *_localctx = _tracker.createInstance<AnydigitContext>(_ctx, getState());
  enterRule(_localctx, 78, QueryParser::RuleAnydigit);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(281); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(280);
              _la = _input->LA(1);
              if (!(_la == QueryParser::ZERO

              || _la == QueryParser::NONZERODIGIT)) {
              _errHandler->recoverInline(this);
              }
              else {
                _errHandler->reportMatch(this);
                consume();
              }
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(283); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OpeningparContext ------------------------------------------------------------------

QueryParser::OpeningparContext::OpeningparContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QueryParser::OpeningparContext::OPENINGPAR() {
  return getToken(QueryParser::OPENINGPAR, 0);
}


size_t QueryParser::OpeningparContext::getRuleIndex() const {
  return QueryParser::RuleOpeningpar;
}

void QueryParser::OpeningparContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOpeningpar(this);
}

void QueryParser::OpeningparContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOpeningpar(this);
}

QueryParser::OpeningparContext* QueryParser::openingpar() {
  OpeningparContext *_localctx = _tracker.createInstance<OpeningparContext>(_ctx, getState());
  enterRule(_localctx, 80, QueryParser::RuleOpeningpar);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(285);
    match(QueryParser::OPENINGPAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClosingparContext ------------------------------------------------------------------

QueryParser::ClosingparContext::ClosingparContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QueryParser::ClosingparContext::CLOSINGPAR() {
  return getToken(QueryParser::CLOSINGPAR, 0);
}


size_t QueryParser::ClosingparContext::getRuleIndex() const {
  return QueryParser::RuleClosingpar;
}

void QueryParser::ClosingparContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClosingpar(this);
}

void QueryParser::ClosingparContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<QueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClosingpar(this);
}

QueryParser::ClosingparContext* QueryParser::closingpar() {
  ClosingparContext *_localctx = _tracker.createInstance<ClosingparContext>(_ctx, getState());
  enterRule(_localctx, 82, QueryParser::RuleClosingpar);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(287);
    match(QueryParser::CLOSINGPAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> QueryParser::_decisionToDFA;
atn::PredictionContextCache QueryParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN QueryParser::_atn;
std::vector<uint16_t> QueryParser::_serializedATN;

std::vector<std::string> QueryParser::_ruleNames = {
  "query", "querytermortermassoc", "querytermassoc", "queryterm", "dottedpath", 
  "attribute", "qoperator", "patternop", "patternnoop", "greatereq", "greater", 
  "less", "lesseq", "equal", "unequal", "othervalue", "qtrue", "qfalse", 
  "value", "range", "valuelist", "compequalityvalue", "uri", "logicalop", 
  "orop", "andop", "comparablevalue", "quotedstr", "notaquote", "quotedstringchar", 
  "regex", "regexchar", "notaparenthesis", "datetime", "date", "time", "number", 
  "frac", "qint", "anydigit", "openingpar", "closingpar"
};

std::vector<std::string> QueryParser::_literalNames = {
  "", "'['", "']'", "','", "'RE('", "'..'", "'.'", "'false'", "'true'", 
  "'=='", "'!='", "'>='", "'>'", "'<='", "'<'", "", "", "", "'\"'", "'0'", 
  "", "'+'", "'-'", "'|'", "';'", "", "", "", "", "", "", "'~='", "'!~='", 
  "'('", "')'", "", "'\\'"
};

std::vector<std::string> QueryParser::_symbolicNames = {
  "", "", "", "", "", "DOTS", "DOT", "FALSE", "TRUE", "EQUAL", "UNEQUAL", 
  "GREATEREQ", "GREATER", "LESSEQ", "LESS", "EXP", "DOTTEDATTRNAME", "ATTRNAME", 
  "QUOTE", "ZERO", "NONZERODIGIT", "PLUS", "MINUS", "OROP", "ANDOP", "DATE", 
  "TIME", "DATETIME", "URI", "SCHEME", "URICHAR", "PATTERNOP", "PATTERNNOOP", 
  "OPENINGPAR", "CLOSINGPAR", "ESCAPEDBACKSLASH", "BACKSLASH", "OTHERLEXEDCHAR", 
  "UNICODE"
};

dfa::Vocabulary QueryParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> QueryParser::_tokenNames;

QueryParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0x28, 0x124, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 
       0xe, 0x9, 0xe, 0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 
       0x9, 0x11, 0x4, 0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 
       0x9, 0x14, 0x4, 0x15, 0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 
       0x9, 0x17, 0x4, 0x18, 0x9, 0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 
       0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 
       0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 0x1f, 0x9, 0x1f, 0x4, 0x20, 
       0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 0x9, 0x22, 0x4, 0x23, 
       0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 0x25, 0x4, 0x26, 
       0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 0x4, 0x29, 
       0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x3, 0x2, 
       0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x5b, 0xa, 0x2, 0xc, 0x2, 
       0xe, 0x2, 0x5e, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 
       0x5, 0x3, 0x64, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
       0x3, 0x4, 0x7, 0x4, 0x6b, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x6e, 0xb, 
       0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
       0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
       0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
       0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x87, 0xa, 0x5, 
       0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
       0x7, 0x5, 0x7, 0x90, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
       0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x98, 0xa, 0x8, 0x3, 0x9, 0x3, 
       0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 
       0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 
       0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0xac, 0xa, 0x11, 
       0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 
       0x5, 0x14, 0xb4, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 
       0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x7, 0x16, 0xbd, 0xa, 0x16, 
       0xc, 0x16, 0xe, 0x16, 0xc0, 0xb, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 
       0x17, 0x3, 0x17, 0x5, 0x17, 0xc6, 0xa, 0x17, 0x3, 0x18, 0x3, 0x18, 
       0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 0xcc, 0xa, 0x19, 0x3, 0x1a, 0x3, 
       0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 
       0x1c, 0x3, 0x1c, 0x5, 0x1c, 0xd7, 0xa, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 
       0x6, 0x1d, 0xdb, 0xa, 0x1d, 0xd, 0x1d, 0xe, 0x1d, 0xdc, 0x3, 0x1d, 
       0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 
       0x3, 0x1f, 0x5, 0x1f, 0xe7, 0xa, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x6, 
       0x20, 0xeb, 0xa, 0x20, 0xd, 0x20, 0xe, 0x20, 0xec, 0x3, 0x20, 0x3, 
       0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 
       0x21, 0x5, 0x21, 0xf7, 0xa, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 
       0x3, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x25, 0x3, 0x25, 0x3, 0x26, 
       0x5, 0x26, 0x102, 0xa, 0x26, 0x3, 0x26, 0x3, 0x26, 0x5, 0x26, 0x106, 
       0xa, 0x26, 0x3, 0x26, 0x5, 0x26, 0x109, 0xa, 0x26, 0x3, 0x27, 0x3, 
       0x27, 0x6, 0x27, 0x10d, 0xa, 0x27, 0xd, 0x27, 0xe, 0x27, 0x10e, 0x3, 
       0x28, 0x3, 0x28, 0x3, 0x28, 0x7, 0x28, 0x114, 0xa, 0x28, 0xc, 0x28, 
       0xe, 0x28, 0x117, 0xb, 0x28, 0x5, 0x28, 0x119, 0xa, 0x28, 0x3, 0x29, 
       0x6, 0x29, 0x11c, 0xa, 0x29, 0xd, 0x29, 0xe, 0x29, 0x11d, 0x3, 0x2a, 
       0x3, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x2, 0x2, 0x2c, 0x2, 
       0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 
       0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 
       0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 
       0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x2, 0x5, 0x3, 0x2, 0x14, 
       0x14, 0x3, 0x2, 0x23, 0x24, 0x3, 0x2, 0x15, 0x16, 0x2, 0x120, 0x2, 
       0x56, 0x3, 0x2, 0x2, 0x2, 0x4, 0x63, 0x3, 0x2, 0x2, 0x2, 0x6, 0x65, 
       0x3, 0x2, 0x2, 0x2, 0x8, 0x86, 0x3, 0x2, 0x2, 0x2, 0xa, 0x88, 0x3, 
       0x2, 0x2, 0x2, 0xc, 0x8a, 0x3, 0x2, 0x2, 0x2, 0xe, 0x97, 0x3, 0x2, 
       0x2, 0x2, 0x10, 0x99, 0x3, 0x2, 0x2, 0x2, 0x12, 0x9b, 0x3, 0x2, 0x2, 
       0x2, 0x14, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x16, 0x9f, 0x3, 0x2, 0x2, 0x2, 
       0x18, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xa3, 0x3, 0x2, 0x2, 0x2, 0x1c, 
       0xa5, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xa7, 0x3, 0x2, 0x2, 0x2, 0x20, 0xab, 
       0x3, 0x2, 0x2, 0x2, 0x22, 0xad, 0x3, 0x2, 0x2, 0x2, 0x24, 0xaf, 0x3, 
       0x2, 0x2, 0x2, 0x26, 0xb3, 0x3, 0x2, 0x2, 0x2, 0x28, 0xb5, 0x3, 0x2, 
       0x2, 0x2, 0x2a, 0xb9, 0x3, 0x2, 0x2, 0x2, 0x2c, 0xc5, 0x3, 0x2, 0x2, 
       0x2, 0x2e, 0xc7, 0x3, 0x2, 0x2, 0x2, 0x30, 0xcb, 0x3, 0x2, 0x2, 0x2, 
       0x32, 0xcd, 0x3, 0x2, 0x2, 0x2, 0x34, 0xcf, 0x3, 0x2, 0x2, 0x2, 0x36, 
       0xd6, 0x3, 0x2, 0x2, 0x2, 0x38, 0xd8, 0x3, 0x2, 0x2, 0x2, 0x3a, 0xe0, 
       0x3, 0x2, 0x2, 0x2, 0x3c, 0xe6, 0x3, 0x2, 0x2, 0x2, 0x3e, 0xe8, 0x3, 
       0x2, 0x2, 0x2, 0x40, 0xf6, 0x3, 0x2, 0x2, 0x2, 0x42, 0xf8, 0x3, 0x2, 
       0x2, 0x2, 0x44, 0xfa, 0x3, 0x2, 0x2, 0x2, 0x46, 0xfc, 0x3, 0x2, 0x2, 
       0x2, 0x48, 0xfe, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x101, 0x3, 0x2, 0x2, 
       0x2, 0x4c, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x118, 0x3, 0x2, 0x2, 
       0x2, 0x50, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x52, 0x11f, 0x3, 0x2, 0x2, 
       0x2, 0x54, 0x121, 0x3, 0x2, 0x2, 0x2, 0x56, 0x5c, 0x5, 0x4, 0x3, 
       0x2, 0x57, 0x58, 0x5, 0x30, 0x19, 0x2, 0x58, 0x59, 0x5, 0x4, 0x3, 
       0x2, 0x59, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x57, 0x3, 0x2, 0x2, 0x2, 
       0x5b, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x5c, 
       0x5d, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5c, 
       0x3, 0x2, 0x2, 0x2, 0x5f, 0x60, 0x7, 0x2, 0x2, 0x3, 0x60, 0x3, 0x3, 
       0x2, 0x2, 0x2, 0x61, 0x64, 0x5, 0x8, 0x5, 0x2, 0x62, 0x64, 0x5, 0x6, 
       0x4, 0x2, 0x63, 0x61, 0x3, 0x2, 0x2, 0x2, 0x63, 0x62, 0x3, 0x2, 0x2, 
       0x2, 0x64, 0x5, 0x3, 0x2, 0x2, 0x2, 0x65, 0x66, 0x5, 0x52, 0x2a, 
       0x2, 0x66, 0x6c, 0x5, 0x8, 0x5, 0x2, 0x67, 0x68, 0x5, 0x30, 0x19, 
       0x2, 0x68, 0x69, 0x5, 0x8, 0x5, 0x2, 0x69, 0x6b, 0x3, 0x2, 0x2, 0x2, 
       0x6a, 0x67, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x6c, 
       0x6a, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6f, 
       0x3, 0x2, 0x2, 0x2, 0x6e, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x70, 0x5, 
       0x54, 0x2b, 0x2, 0x70, 0x7, 0x3, 0x2, 0x2, 0x2, 0x71, 0x87, 0x5, 
       0xc, 0x7, 0x2, 0x72, 0x73, 0x5, 0xc, 0x7, 0x2, 0x73, 0x74, 0x5, 0xe, 
       0x8, 0x2, 0x74, 0x75, 0x5, 0x36, 0x1c, 0x2, 0x75, 0x87, 0x3, 0x2, 
       0x2, 0x2, 0x76, 0x77, 0x5, 0xc, 0x7, 0x2, 0x77, 0x78, 0x5, 0x1c, 
       0xf, 0x2, 0x78, 0x79, 0x5, 0x2c, 0x17, 0x2, 0x79, 0x87, 0x3, 0x2, 
       0x2, 0x2, 0x7a, 0x7b, 0x5, 0xc, 0x7, 0x2, 0x7b, 0x7c, 0x5, 0x1e, 
       0x10, 0x2, 0x7c, 0x7d, 0x5, 0x2c, 0x17, 0x2, 0x7d, 0x87, 0x3, 0x2, 
       0x2, 0x2, 0x7e, 0x7f, 0x5, 0xc, 0x7, 0x2, 0x7f, 0x80, 0x5, 0x10, 
       0x9, 0x2, 0x80, 0x81, 0x5, 0x3e, 0x20, 0x2, 0x81, 0x87, 0x3, 0x2, 
       0x2, 0x2, 0x82, 0x83, 0x5, 0xc, 0x7, 0x2, 0x83, 0x84, 0x5, 0x12, 
       0xa, 0x2, 0x84, 0x85, 0x5, 0x3e, 0x20, 0x2, 0x85, 0x87, 0x3, 0x2, 
       0x2, 0x2, 0x86, 0x71, 0x3, 0x2, 0x2, 0x2, 0x86, 0x72, 0x3, 0x2, 0x2, 
       0x2, 0x86, 0x76, 0x3, 0x2, 0x2, 0x2, 0x86, 0x7a, 0x3, 0x2, 0x2, 0x2, 
       0x86, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x86, 0x82, 0x3, 0x2, 0x2, 0x2, 0x87, 
       0x9, 0x3, 0x2, 0x2, 0x2, 0x88, 0x89, 0x7, 0x12, 0x2, 0x2, 0x89, 0xb, 
       0x3, 0x2, 0x2, 0x2, 0x8a, 0x8f, 0x5, 0xa, 0x6, 0x2, 0x8b, 0x8c, 0x7, 
       0x3, 0x2, 0x2, 0x8c, 0x8d, 0x5, 0xa, 0x6, 0x2, 0x8d, 0x8e, 0x7, 0x4, 
       0x2, 0x2, 0x8e, 0x90, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x8b, 0x3, 0x2, 0x2, 
       0x2, 0x8f, 0x90, 0x3, 0x2, 0x2, 0x2, 0x90, 0xd, 0x3, 0x2, 0x2, 0x2, 
       0x91, 0x98, 0x5, 0x1c, 0xf, 0x2, 0x92, 0x98, 0x5, 0x1e, 0x10, 0x2, 
       0x93, 0x98, 0x5, 0x14, 0xb, 0x2, 0x94, 0x98, 0x5, 0x16, 0xc, 0x2, 
       0x95, 0x98, 0x5, 0x18, 0xd, 0x2, 0x96, 0x98, 0x5, 0x1a, 0xe, 0x2, 
       0x97, 0x91, 0x3, 0x2, 0x2, 0x2, 0x97, 0x92, 0x3, 0x2, 0x2, 0x2, 0x97, 
       0x93, 0x3, 0x2, 0x2, 0x2, 0x97, 0x94, 0x3, 0x2, 0x2, 0x2, 0x97, 0x95, 
       0x3, 0x2, 0x2, 0x2, 0x97, 0x96, 0x3, 0x2, 0x2, 0x2, 0x98, 0xf, 0x3, 
       0x2, 0x2, 0x2, 0x99, 0x9a, 0x7, 0x21, 0x2, 0x2, 0x9a, 0x11, 0x3, 
       0x2, 0x2, 0x2, 0x9b, 0x9c, 0x7, 0x22, 0x2, 0x2, 0x9c, 0x13, 0x3, 
       0x2, 0x2, 0x2, 0x9d, 0x9e, 0x7, 0xd, 0x2, 0x2, 0x9e, 0x15, 0x3, 0x2, 
       0x2, 0x2, 0x9f, 0xa0, 0x7, 0xe, 0x2, 0x2, 0xa0, 0x17, 0x3, 0x2, 0x2, 
       0x2, 0xa1, 0xa2, 0x7, 0x10, 0x2, 0x2, 0xa2, 0x19, 0x3, 0x2, 0x2, 
       0x2, 0xa3, 0xa4, 0x7, 0xf, 0x2, 0x2, 0xa4, 0x1b, 0x3, 0x2, 0x2, 0x2, 
       0xa5, 0xa6, 0x7, 0xb, 0x2, 0x2, 0xa6, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xa7, 
       0xa8, 0x7, 0xc, 0x2, 0x2, 0xa8, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xac, 
       0x5, 0x24, 0x13, 0x2, 0xaa, 0xac, 0x5, 0x22, 0x12, 0x2, 0xab, 0xa9, 
       0x3, 0x2, 0x2, 0x2, 0xab, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xac, 0x21, 0x3, 
       0x2, 0x2, 0x2, 0xad, 0xae, 0x7, 0xa, 0x2, 0x2, 0xae, 0x23, 0x3, 0x2, 
       0x2, 0x2, 0xaf, 0xb0, 0x7, 0x9, 0x2, 0x2, 0xb0, 0x25, 0x3, 0x2, 0x2, 
       0x2, 0xb1, 0xb4, 0x5, 0x36, 0x1c, 0x2, 0xb2, 0xb4, 0x5, 0x20, 0x11, 
       0x2, 0xb3, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb2, 0x3, 0x2, 0x2, 0x2, 
       0xb4, 0x27, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb6, 0x5, 0x36, 0x1c, 0x2, 
       0xb6, 0xb7, 0x7, 0x7, 0x2, 0x2, 0xb7, 0xb8, 0x5, 0x36, 0x1c, 0x2, 
       0xb8, 0x29, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xbe, 0x5, 0x26, 0x14, 0x2, 
       0xba, 0xbb, 0x7, 0x5, 0x2, 0x2, 0xbb, 0xbd, 0x5, 0x26, 0x14, 0x2, 
       0xbc, 0xba, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xbe, 
       0xbc, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xbf, 0x2b, 
       0x3, 0x2, 0x2, 0x2, 0xc0, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc6, 0x5, 
       0x20, 0x11, 0x2, 0xc2, 0xc6, 0x5, 0x2a, 0x16, 0x2, 0xc3, 0xc6, 0x5, 
       0x28, 0x15, 0x2, 0xc4, 0xc6, 0x5, 0x2e, 0x18, 0x2, 0xc5, 0xc1, 0x3, 
       0x2, 0x2, 0x2, 0xc5, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc3, 0x3, 0x2, 
       0x2, 0x2, 0xc5, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc6, 0x2d, 0x3, 0x2, 0x2, 
       0x2, 0xc7, 0xc8, 0x7, 0x1e, 0x2, 0x2, 0xc8, 0x2f, 0x3, 0x2, 0x2, 
       0x2, 0xc9, 0xcc, 0x5, 0x32, 0x1a, 0x2, 0xca, 0xcc, 0x5, 0x34, 0x1b, 
       0x2, 0xcb, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xca, 0x3, 0x2, 0x2, 0x2, 
       0xcc, 0x31, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xce, 0x7, 0x19, 0x2, 0x2, 
       0xce, 0x33, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xd0, 0x7, 0x1a, 0x2, 0x2, 
       0xd0, 0x35, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd7, 0x5, 0x4a, 0x26, 0x2, 
       0xd2, 0xd7, 0x5, 0x38, 0x1d, 0x2, 0xd3, 0xd7, 0x5, 0x44, 0x23, 0x2, 
       0xd4, 0xd7, 0x5, 0x46, 0x24, 0x2, 0xd5, 0xd7, 0x5, 0x48, 0x25, 0x2, 
       0xd6, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd6, 
       0xd3, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd5, 
       0x3, 0x2, 0x2, 0x2, 0xd7, 0x37, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xda, 0x7, 
       0x14, 0x2, 0x2, 0xd9, 0xdb, 0x5, 0x3c, 0x1f, 0x2, 0xda, 0xd9, 0x3, 
       0x2, 0x2, 0x2, 0xdb, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xda, 0x3, 0x2, 
       0x2, 0x2, 0xdc, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xde, 0x3, 0x2, 0x2, 
       0x2, 0xde, 0xdf, 0x7, 0x14, 0x2, 0x2, 0xdf, 0x39, 0x3, 0x2, 0x2, 
       0x2, 0xe0, 0xe1, 0xa, 0x2, 0x2, 0x2, 0xe1, 0x3b, 0x3, 0x2, 0x2, 0x2, 
       0xe2, 0xe7, 0x5, 0x3a, 0x1e, 0x2, 0xe3, 0xe7, 0x7, 0x25, 0x2, 0x2, 
       0xe4, 0xe5, 0x7, 0x26, 0x2, 0x2, 0xe5, 0xe7, 0x7, 0x14, 0x2, 0x2, 
       0xe6, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xe6, 
       0xe4, 0x3, 0x2, 0x2, 0x2, 0xe7, 0x3d, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xea, 
       0x7, 0x6, 0x2, 0x2, 0xe9, 0xeb, 0x5, 0x40, 0x21, 0x2, 0xea, 0xe9, 
       0x3, 0x2, 0x2, 0x2, 0xeb, 0xec, 0x3, 0x2, 0x2, 0x2, 0xec, 0xea, 0x3, 
       0x2, 0x2, 0x2, 0xec, 0xed, 0x3, 0x2, 0x2, 0x2, 0xed, 0xee, 0x3, 0x2, 
       0x2, 0x2, 0xee, 0xef, 0x7, 0x24, 0x2, 0x2, 0xef, 0x3f, 0x3, 0x2, 
       0x2, 0x2, 0xf0, 0xf7, 0x5, 0x42, 0x22, 0x2, 0xf1, 0xf2, 0x7, 0x26, 
       0x2, 0x2, 0xf2, 0xf7, 0x7, 0x23, 0x2, 0x2, 0xf3, 0xf4, 0x7, 0x26, 
       0x2, 0x2, 0xf4, 0xf7, 0x7, 0x24, 0x2, 0x2, 0xf5, 0xf7, 0x7, 0x25, 
       0x2, 0x2, 0xf6, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf1, 0x3, 0x2, 0x2, 
       0x2, 0xf6, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf5, 0x3, 0x2, 0x2, 0x2, 
       0xf7, 0x41, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf9, 0xa, 0x3, 0x2, 0x2, 0xf9, 
       0x43, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xfb, 0x7, 0x1d, 0x2, 0x2, 0xfb, 
       0x45, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xfd, 0x7, 0x1b, 0x2, 0x2, 0xfd, 
       0x47, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xff, 0x7, 0x1c, 0x2, 0x2, 0xff, 
       0x49, 0x3, 0x2, 0x2, 0x2, 0x100, 0x102, 0x7, 0x18, 0x2, 0x2, 0x101, 
       0x100, 0x3, 0x2, 0x2, 0x2, 0x101, 0x102, 0x3, 0x2, 0x2, 0x2, 0x102, 
       0x103, 0x3, 0x2, 0x2, 0x2, 0x103, 0x105, 0x5, 0x4e, 0x28, 0x2, 0x104, 
       0x106, 0x5, 0x4c, 0x27, 0x2, 0x105, 0x104, 0x3, 0x2, 0x2, 0x2, 0x105, 
       0x106, 0x3, 0x2, 0x2, 0x2, 0x106, 0x108, 0x3, 0x2, 0x2, 0x2, 0x107, 
       0x109, 0x7, 0x11, 0x2, 0x2, 0x108, 0x107, 0x3, 0x2, 0x2, 0x2, 0x108, 
       0x109, 0x3, 0x2, 0x2, 0x2, 0x109, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x10a, 
       0x10c, 0x7, 0x8, 0x2, 0x2, 0x10b, 0x10d, 0x5, 0x50, 0x29, 0x2, 0x10c, 
       0x10b, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x10e, 
       0x10c, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x10f, 
       0x4d, 0x3, 0x2, 0x2, 0x2, 0x110, 0x119, 0x7, 0x15, 0x2, 0x2, 0x111, 
       0x115, 0x7, 0x16, 0x2, 0x2, 0x112, 0x114, 0x5, 0x50, 0x29, 0x2, 0x113, 
       0x112, 0x3, 0x2, 0x2, 0x2, 0x114, 0x117, 0x3, 0x2, 0x2, 0x2, 0x115, 
       0x113, 0x3, 0x2, 0x2, 0x2, 0x115, 0x116, 0x3, 0x2, 0x2, 0x2, 0x116, 
       0x119, 0x3, 0x2, 0x2, 0x2, 0x117, 0x115, 0x3, 0x2, 0x2, 0x2, 0x118, 
       0x110, 0x3, 0x2, 0x2, 0x2, 0x118, 0x111, 0x3, 0x2, 0x2, 0x2, 0x119, 
       0x4f, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x11c, 0x9, 0x4, 0x2, 0x2, 0x11b, 
       0x11a, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x11d, 
       0x11b, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x11e, 
       0x51, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x120, 0x7, 0x23, 0x2, 0x2, 0x120, 
       0x53, 0x3, 0x2, 0x2, 0x2, 0x121, 0x122, 0x7, 0x24, 0x2, 0x2, 0x122, 
       0x55, 0x3, 0x2, 0x2, 0x2, 0x19, 0x5c, 0x63, 0x6c, 0x86, 0x8f, 0x97, 
       0xab, 0xb3, 0xbe, 0xc5, 0xcb, 0xd6, 0xdc, 0xe6, 0xec, 0xf6, 0x101, 
       0x105, 0x108, 0x10e, 0x115, 0x118, 0x11d, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

QueryParser::Initializer QueryParser::_init;
