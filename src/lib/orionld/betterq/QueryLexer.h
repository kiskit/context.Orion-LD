
// Generated from Query.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  QueryLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, NUMBER = 5, FRAC = 6, QINT = 7, 
    ANYDIGIT = 8, DOTS = 9, DOT = 10, FALSE = 11, TRUE = 12, EQUAL = 13, 
    UNEQUAL = 14, GREATEREQ = 15, GREATER = 16, LESSEQ = 17, LESS = 18, 
    EXP = 19, DOTTEDATTRNAME = 20, ATTRNAME = 21, QUOTE = 22, ZERO = 23, 
    NONZERODIGIT = 24, PLUS = 25, MINUS = 26, OROP = 27, ANDOP = 28, DATE = 29, 
    TIME = 30, DATETIME = 31, URI = 32, SCHEME = 33, URICHAR = 34, PATTERNOP = 35, 
    PATTERNNOOP = 36, OPENINGPAR = 37, CLOSINGPAR = 38, ESCAPEDBACKSLASH = 39, 
    BACKSLASH = 40, OTHERLEXEDCHAR = 41, UNICODE = 42
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

