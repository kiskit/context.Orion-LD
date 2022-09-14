
// Generated from Query.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  QueryLexer : public antlr4::Lexer {
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

  explicit QueryLexer(antlr4::CharStream *input);
  ~QueryLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

