
// Generated from ./JvavLexer.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  JvavLexer : public antlr4::Lexer {
public:
  enum {
    Annotation = 1, BlockAnnotation = 2, LineAnnotation = 3, Newline = 4, 
    Whitespace = 5, Lparenthesis = 6, Rparenthesis = 7, Lbracket = 8, Rbracket = 9, 
    Lbrace = 10, Rbrace = 11, Dot = 12, Comma = 13, Semicolon = 14, Question = 15, 
    Colon = 16, Increment = 17, Decrement = 18, Not = 19, Inv = 20, Mul = 21, 
    Div = 22, Mod = 23, Add = 24, Sub = 25, Lshift = 26, Rshift = 27, Lessthan = 28, 
    Greaterthan = 29, Lessthanequal = 30, Greaterthanequal = 31, Equal = 32, 
    Notequal = 33, Bitand = 34, Bitxor = 35, Bitor = 36, And = 37, Or = 38, 
    Assign = 39, Class = 40, If = 41, Else = 42, While = 43, For = 44, Return = 45, 
    Break = 46, Continue = 47, This = 48, True = 49, False = 50, Null = 51, 
    New = 52, Bool = 53, Int = 54, Void = 55, String = 56, Number = 57, 
    Identifier = 58, Str = 59
  };

  explicit JvavLexer(antlr4::CharStream *input);

  ~JvavLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

