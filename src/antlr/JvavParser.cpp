
// Generated from ./JvavParser.g4 by ANTLR 4.13.2


#include "JvavParserVisitor.h"

#include "JvavParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct JvavParserStaticData final {
  JvavParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  JvavParserStaticData(const JvavParserStaticData&) = delete;
  JvavParserStaticData(JvavParserStaticData&&) = delete;
  JvavParserStaticData& operator=(const JvavParserStaticData&) = delete;
  JvavParserStaticData& operator=(JvavParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag jvavparserParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<JvavParserStaticData> jvavparserParserStaticData = nullptr;

void jvavparserParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (jvavparserParserStaticData != nullptr) {
    return;
  }
#else
  assert(jvavparserParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<JvavParserStaticData>(
    std::vector<std::string>{
      "program", "func_def", "typedargslist", "argslist", "class_def", "class_suite", 
      "construct_stmt", "var_def", "var_stmt", "suite", "stmt", "branch_stmt", 
      "loop_stmt", "while_stmt", "for_stmt", "flow_stmt", "return_stmt", 
      "break_stmt", "continue_stmt", "expr_stmt", "expression", "const_expr", 
      "func_expr", "new_expr", "newerror_expr", "newvar_expr", "typename", 
      "basic_type"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "'('", "')'", "'['", "']'", "'{'", "'}'", 
      "'.'", "','", "';'", "'\\u003F'", "':'", "'++'", "'--'", "'!'", "'~'", 
      "'*'", "'/'", "'%'", "'+'", "'-'", "'<<'", "'>>'", "'<'", "'>'", "'<='", 
      "'>='", "'=='", "'!='", "'&'", "'^'", "'|'", "'&&'", "'||'", "'='", 
      "'class'", "'if'", "'else'", "'while'", "'for'", "'return'", "'break'", 
      "'continue'", "'this'", "'true'", "'false'", "'null'", "'new'", "'bool'", 
      "'int'", "'void'", "'string'"
    },
    std::vector<std::string>{
      "", "Annotation", "BlockAnnotation", "LineAnnotation", "Newline", 
      "Whitespace", "Lparenthesis", "Rparenthesis", "Lbracket", "Rbracket", 
      "Lbrace", "Rbrace", "Dot", "Comma", "Semicolon", "Question", "Colon", 
      "Increment", "Decrement", "Not", "Inv", "Mul", "Div", "Mod", "Add", 
      "Sub", "Lshift", "Rshift", "Lessthan", "Greaterthan", "Lessthanequal", 
      "Greaterthanequal", "Equal", "Notequal", "Bitand", "Bitxor", "Bitor", 
      "And", "Or", "Assign", "Class", "If", "Else", "While", "For", "Return", 
      "Break", "Continue", "This", "True", "False", "Null", "New", "Bool", 
      "Int", "Void", "String", "Number", "Identifier", "Str"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,59,375,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,1,0,1,
  	0,1,0,5,0,60,8,0,10,0,12,0,63,9,0,1,0,1,0,1,1,1,1,3,1,69,8,1,1,1,1,1,
  	1,1,3,1,74,8,1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,2,5,2,85,8,2,10,2,12,
  	2,88,9,2,1,3,1,3,1,3,5,3,93,8,3,10,3,12,3,96,9,3,1,4,1,4,1,4,1,4,1,4,
  	1,5,1,5,1,5,1,5,5,5,107,8,5,10,5,12,5,110,9,5,1,5,1,5,1,6,1,6,1,6,1,6,
  	1,6,1,7,1,7,1,7,1,7,5,7,123,8,7,10,7,12,7,126,9,7,1,7,1,7,1,8,1,8,1,8,
  	3,8,133,8,8,1,9,1,9,5,9,137,8,9,10,9,12,9,140,9,9,1,9,1,9,1,10,1,10,1,
  	10,1,10,1,10,1,10,3,10,150,8,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,
  	11,1,11,1,11,1,11,1,11,5,11,164,8,11,10,11,12,11,167,9,11,1,11,1,11,3,
  	11,171,8,11,1,12,1,12,3,12,175,8,12,1,13,1,13,1,13,1,13,1,13,1,13,1,14,
  	1,14,1,14,3,14,186,8,14,1,14,1,14,3,14,190,8,14,1,14,3,14,193,8,14,1,
  	14,1,14,3,14,197,8,14,1,14,1,14,1,14,1,15,1,15,1,15,3,15,205,8,15,1,16,
  	1,16,3,16,209,8,16,1,16,1,16,1,17,1,17,1,17,1,18,1,18,1,18,1,19,1,19,
  	1,19,5,19,222,8,19,10,19,12,19,225,9,19,3,19,227,8,19,1,19,1,19,1,20,
  	1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,3,20,
  	245,8,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,
  	1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,
  	1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,
  	1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,5,20,296,8,20,10,20,12,20,
  	299,9,20,1,21,1,21,1,22,1,22,1,22,3,22,306,8,22,1,22,1,22,1,23,1,23,3,
  	23,312,8,23,1,24,1,24,1,24,1,24,1,24,1,24,5,24,320,8,24,10,24,12,24,323,
  	9,24,1,24,1,24,4,24,327,8,24,11,24,12,24,328,1,24,1,24,1,24,1,24,4,24,
  	335,8,24,11,24,12,24,336,1,24,1,24,3,24,341,8,24,1,25,1,25,1,25,1,25,
  	1,25,1,25,5,25,349,8,25,10,25,12,25,352,9,25,1,25,1,25,5,25,356,8,25,
  	10,25,12,25,359,9,25,1,25,1,25,3,25,363,8,25,1,26,1,26,1,26,5,26,368,
  	8,26,10,26,12,26,371,9,26,1,27,1,27,1,27,0,1,40,28,0,2,4,6,8,10,12,14,
  	16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,0,9,1,0,17,
  	18,2,0,19,20,25,25,1,0,21,23,1,0,24,25,1,0,26,27,1,0,28,31,1,0,32,33,
  	3,0,49,51,57,57,59,59,3,0,53,54,56,56,58,58,408,0,61,1,0,0,0,2,68,1,0,
  	0,0,4,78,1,0,0,0,6,89,1,0,0,0,8,97,1,0,0,0,10,102,1,0,0,0,12,113,1,0,
  	0,0,14,118,1,0,0,0,16,129,1,0,0,0,18,134,1,0,0,0,20,149,1,0,0,0,22,151,
  	1,0,0,0,24,174,1,0,0,0,26,176,1,0,0,0,28,182,1,0,0,0,30,204,1,0,0,0,32,
  	206,1,0,0,0,34,212,1,0,0,0,36,215,1,0,0,0,38,226,1,0,0,0,40,244,1,0,0,
  	0,42,300,1,0,0,0,44,302,1,0,0,0,46,311,1,0,0,0,48,313,1,0,0,0,50,342,
  	1,0,0,0,52,364,1,0,0,0,54,372,1,0,0,0,56,60,3,2,1,0,57,60,3,8,4,0,58,
  	60,3,14,7,0,59,56,1,0,0,0,59,57,1,0,0,0,59,58,1,0,0,0,60,63,1,0,0,0,61,
  	59,1,0,0,0,61,62,1,0,0,0,62,64,1,0,0,0,63,61,1,0,0,0,64,65,5,0,0,1,65,
  	1,1,0,0,0,66,69,3,52,26,0,67,69,5,55,0,0,68,66,1,0,0,0,68,67,1,0,0,0,
  	69,70,1,0,0,0,70,71,5,58,0,0,71,73,5,6,0,0,72,74,3,4,2,0,73,72,1,0,0,
  	0,73,74,1,0,0,0,74,75,1,0,0,0,75,76,5,7,0,0,76,77,3,18,9,0,77,3,1,0,0,
  	0,78,79,3,52,26,0,79,86,5,58,0,0,80,81,5,13,0,0,81,82,3,52,26,0,82,83,
  	5,58,0,0,83,85,1,0,0,0,84,80,1,0,0,0,85,88,1,0,0,0,86,84,1,0,0,0,86,87,
  	1,0,0,0,87,5,1,0,0,0,88,86,1,0,0,0,89,94,3,40,20,0,90,91,5,13,0,0,91,
  	93,3,40,20,0,92,90,1,0,0,0,93,96,1,0,0,0,94,92,1,0,0,0,94,95,1,0,0,0,
  	95,7,1,0,0,0,96,94,1,0,0,0,97,98,5,40,0,0,98,99,5,58,0,0,99,100,3,10,
  	5,0,100,101,5,14,0,0,101,9,1,0,0,0,102,108,5,10,0,0,103,107,3,14,7,0,
  	104,107,3,2,1,0,105,107,3,12,6,0,106,103,1,0,0,0,106,104,1,0,0,0,106,
  	105,1,0,0,0,107,110,1,0,0,0,108,106,1,0,0,0,108,109,1,0,0,0,109,111,1,
  	0,0,0,110,108,1,0,0,0,111,112,5,11,0,0,112,11,1,0,0,0,113,114,5,58,0,
  	0,114,115,5,6,0,0,115,116,5,7,0,0,116,117,3,18,9,0,117,13,1,0,0,0,118,
  	119,3,52,26,0,119,124,3,16,8,0,120,121,5,13,0,0,121,123,3,16,8,0,122,
  	120,1,0,0,0,123,126,1,0,0,0,124,122,1,0,0,0,124,125,1,0,0,0,125,127,1,
  	0,0,0,126,124,1,0,0,0,127,128,5,14,0,0,128,15,1,0,0,0,129,132,5,58,0,
  	0,130,131,5,39,0,0,131,133,3,40,20,0,132,130,1,0,0,0,132,133,1,0,0,0,
  	133,17,1,0,0,0,134,138,5,10,0,0,135,137,3,20,10,0,136,135,1,0,0,0,137,
  	140,1,0,0,0,138,136,1,0,0,0,138,139,1,0,0,0,139,141,1,0,0,0,140,138,1,
  	0,0,0,141,142,5,11,0,0,142,19,1,0,0,0,143,150,3,18,9,0,144,150,3,14,7,
  	0,145,150,3,22,11,0,146,150,3,24,12,0,147,150,3,30,15,0,148,150,3,38,
  	19,0,149,143,1,0,0,0,149,144,1,0,0,0,149,145,1,0,0,0,149,146,1,0,0,0,
  	149,147,1,0,0,0,149,148,1,0,0,0,150,21,1,0,0,0,151,152,5,41,0,0,152,153,
  	5,6,0,0,153,154,3,40,20,0,154,155,5,7,0,0,155,165,3,20,10,0,156,157,5,
  	42,0,0,157,158,5,41,0,0,158,159,5,6,0,0,159,160,3,40,20,0,160,161,5,7,
  	0,0,161,162,3,20,10,0,162,164,1,0,0,0,163,156,1,0,0,0,164,167,1,0,0,0,
  	165,163,1,0,0,0,165,166,1,0,0,0,166,170,1,0,0,0,167,165,1,0,0,0,168,169,
  	5,42,0,0,169,171,3,20,10,0,170,168,1,0,0,0,170,171,1,0,0,0,171,23,1,0,
  	0,0,172,175,3,26,13,0,173,175,3,28,14,0,174,172,1,0,0,0,174,173,1,0,0,
  	0,175,25,1,0,0,0,176,177,5,43,0,0,177,178,5,6,0,0,178,179,3,40,20,0,179,
  	180,5,7,0,0,180,181,3,20,10,0,181,27,1,0,0,0,182,183,5,44,0,0,183,189,
  	5,6,0,0,184,186,3,40,20,0,185,184,1,0,0,0,185,186,1,0,0,0,186,187,1,0,
  	0,0,187,190,5,14,0,0,188,190,3,14,7,0,189,185,1,0,0,0,189,188,1,0,0,0,
  	190,192,1,0,0,0,191,193,3,40,20,0,192,191,1,0,0,0,192,193,1,0,0,0,193,
  	194,1,0,0,0,194,196,5,14,0,0,195,197,3,40,20,0,196,195,1,0,0,0,196,197,
  	1,0,0,0,197,198,1,0,0,0,198,199,5,7,0,0,199,200,3,20,10,0,200,29,1,0,
  	0,0,201,205,3,32,16,0,202,205,3,34,17,0,203,205,3,36,18,0,204,201,1,0,
  	0,0,204,202,1,0,0,0,204,203,1,0,0,0,205,31,1,0,0,0,206,208,5,45,0,0,207,
  	209,3,40,20,0,208,207,1,0,0,0,208,209,1,0,0,0,209,210,1,0,0,0,210,211,
  	5,14,0,0,211,33,1,0,0,0,212,213,5,46,0,0,213,214,5,14,0,0,214,35,1,0,
  	0,0,215,216,5,47,0,0,216,217,5,14,0,0,217,37,1,0,0,0,218,223,3,40,20,
  	0,219,220,5,13,0,0,220,222,3,40,20,0,221,219,1,0,0,0,222,225,1,0,0,0,
  	223,221,1,0,0,0,223,224,1,0,0,0,224,227,1,0,0,0,225,223,1,0,0,0,226,218,
  	1,0,0,0,226,227,1,0,0,0,227,228,1,0,0,0,228,229,5,14,0,0,229,39,1,0,0,
  	0,230,231,6,20,-1,0,231,232,5,6,0,0,232,233,3,40,20,0,233,234,5,7,0,0,
  	234,245,1,0,0,0,235,245,3,42,21,0,236,245,5,58,0,0,237,245,5,48,0,0,238,
  	245,3,44,22,0,239,245,3,46,23,0,240,241,7,0,0,0,241,245,3,40,20,14,242,
  	243,7,1,0,0,243,245,3,40,20,13,244,230,1,0,0,0,244,235,1,0,0,0,244,236,
  	1,0,0,0,244,237,1,0,0,0,244,238,1,0,0,0,244,239,1,0,0,0,244,240,1,0,0,
  	0,244,242,1,0,0,0,245,297,1,0,0,0,246,247,10,19,0,0,247,248,5,12,0,0,
  	248,296,3,40,20,20,249,250,10,12,0,0,250,251,7,2,0,0,251,296,3,40,20,
  	13,252,253,10,11,0,0,253,254,7,3,0,0,254,296,3,40,20,12,255,256,10,10,
  	0,0,256,257,7,4,0,0,257,296,3,40,20,11,258,259,10,9,0,0,259,260,7,5,0,
  	0,260,296,3,40,20,10,261,262,10,8,0,0,262,263,7,6,0,0,263,296,3,40,20,
  	9,264,265,10,7,0,0,265,266,5,34,0,0,266,296,3,40,20,8,267,268,10,6,0,
  	0,268,269,5,35,0,0,269,296,3,40,20,7,270,271,10,5,0,0,271,272,5,36,0,
  	0,272,296,3,40,20,6,273,274,10,4,0,0,274,275,5,37,0,0,275,296,3,40,20,
  	5,276,277,10,3,0,0,277,278,5,38,0,0,278,296,3,40,20,4,279,280,10,2,0,
  	0,280,281,5,15,0,0,281,282,3,40,20,0,282,283,5,16,0,0,283,284,3,40,20,
  	2,284,296,1,0,0,0,285,286,10,1,0,0,286,287,5,39,0,0,287,296,3,40,20,1,
  	288,289,10,17,0,0,289,290,5,8,0,0,290,291,3,40,20,0,291,292,5,9,0,0,292,
  	296,1,0,0,0,293,294,10,15,0,0,294,296,7,0,0,0,295,246,1,0,0,0,295,249,
  	1,0,0,0,295,252,1,0,0,0,295,255,1,0,0,0,295,258,1,0,0,0,295,261,1,0,0,
  	0,295,264,1,0,0,0,295,267,1,0,0,0,295,270,1,0,0,0,295,273,1,0,0,0,295,
  	276,1,0,0,0,295,279,1,0,0,0,295,285,1,0,0,0,295,288,1,0,0,0,295,293,1,
  	0,0,0,296,299,1,0,0,0,297,295,1,0,0,0,297,298,1,0,0,0,298,41,1,0,0,0,
  	299,297,1,0,0,0,300,301,7,7,0,0,301,43,1,0,0,0,302,303,5,58,0,0,303,305,
  	5,6,0,0,304,306,3,6,3,0,305,304,1,0,0,0,305,306,1,0,0,0,306,307,1,0,0,
  	0,307,308,5,7,0,0,308,45,1,0,0,0,309,312,3,48,24,0,310,312,3,50,25,0,
  	311,309,1,0,0,0,311,310,1,0,0,0,312,47,1,0,0,0,313,314,5,52,0,0,314,321,
  	3,54,27,0,315,316,5,8,0,0,316,317,3,40,20,0,317,318,5,9,0,0,318,320,1,
  	0,0,0,319,315,1,0,0,0,320,323,1,0,0,0,321,319,1,0,0,0,321,322,1,0,0,0,
  	322,326,1,0,0,0,323,321,1,0,0,0,324,325,5,8,0,0,325,327,5,9,0,0,326,324,
  	1,0,0,0,327,328,1,0,0,0,328,326,1,0,0,0,328,329,1,0,0,0,329,334,1,0,0,
  	0,330,331,5,8,0,0,331,332,3,40,20,0,332,333,5,9,0,0,333,335,1,0,0,0,334,
  	330,1,0,0,0,335,336,1,0,0,0,336,334,1,0,0,0,336,337,1,0,0,0,337,340,1,
  	0,0,0,338,339,5,6,0,0,339,341,5,7,0,0,340,338,1,0,0,0,340,341,1,0,0,0,
  	341,49,1,0,0,0,342,343,5,52,0,0,343,350,3,54,27,0,344,345,5,8,0,0,345,
  	346,3,40,20,0,346,347,5,9,0,0,347,349,1,0,0,0,348,344,1,0,0,0,349,352,
  	1,0,0,0,350,348,1,0,0,0,350,351,1,0,0,0,351,357,1,0,0,0,352,350,1,0,0,
  	0,353,354,5,8,0,0,354,356,5,9,0,0,355,353,1,0,0,0,356,359,1,0,0,0,357,
  	355,1,0,0,0,357,358,1,0,0,0,358,362,1,0,0,0,359,357,1,0,0,0,360,361,5,
  	6,0,0,361,363,5,7,0,0,362,360,1,0,0,0,362,363,1,0,0,0,363,51,1,0,0,0,
  	364,369,3,54,27,0,365,366,5,8,0,0,366,368,5,9,0,0,367,365,1,0,0,0,368,
  	371,1,0,0,0,369,367,1,0,0,0,369,370,1,0,0,0,370,53,1,0,0,0,371,369,1,
  	0,0,0,372,373,7,8,0,0,373,55,1,0,0,0,36,59,61,68,73,86,94,106,108,124,
  	132,138,149,165,170,174,185,189,192,196,204,208,223,226,244,295,297,305,
  	311,321,328,336,340,350,357,362,369
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  jvavparserParserStaticData = std::move(staticData);
}

}

JvavParser::JvavParser(TokenStream *input) : JvavParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

JvavParser::JvavParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  JvavParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *jvavparserParserStaticData->atn, jvavparserParserStaticData->decisionToDFA, jvavparserParserStaticData->sharedContextCache, options);
}

JvavParser::~JvavParser() {
  delete _interpreter;
}

const atn::ATN& JvavParser::getATN() const {
  return *jvavparserParserStaticData->atn;
}

std::string JvavParser::getGrammarFileName() const {
  return "JvavParser.g4";
}

const std::vector<std::string>& JvavParser::getRuleNames() const {
  return jvavparserParserStaticData->ruleNames;
}

const dfa::Vocabulary& JvavParser::getVocabulary() const {
  return jvavparserParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView JvavParser::getSerializedATN() const {
  return jvavparserParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

JvavParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JvavParser::ProgramContext::EOF() {
  return getToken(JvavParser::EOF, 0);
}

std::vector<JvavParser::Func_defContext *> JvavParser::ProgramContext::func_def() {
  return getRuleContexts<JvavParser::Func_defContext>();
}

JvavParser::Func_defContext* JvavParser::ProgramContext::func_def(size_t i) {
  return getRuleContext<JvavParser::Func_defContext>(i);
}

std::vector<JvavParser::Class_defContext *> JvavParser::ProgramContext::class_def() {
  return getRuleContexts<JvavParser::Class_defContext>();
}

JvavParser::Class_defContext* JvavParser::ProgramContext::class_def(size_t i) {
  return getRuleContext<JvavParser::Class_defContext>(i);
}

std::vector<JvavParser::Var_defContext *> JvavParser::ProgramContext::var_def() {
  return getRuleContexts<JvavParser::Var_defContext>();
}

JvavParser::Var_defContext* JvavParser::ProgramContext::var_def(size_t i) {
  return getRuleContext<JvavParser::Var_defContext>(i);
}


size_t JvavParser::ProgramContext::getRuleIndex() const {
  return JvavParser::RuleProgram;
}


std::any JvavParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JvavParserVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

JvavParser::ProgramContext* JvavParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, JvavParser::RuleProgram);
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
    setState(61);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 423339464484454400) != 0)) {
      setState(59);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
      case 1: {
        setState(56);
        func_def();
        break;
      }

      case 2: {
        setState(57);
        class_def();
        break;
      }

      case 3: {
        setState(58);
        var_def();
        break;
      }

      default:
        break;
      }
      setState(63);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(64);
    match(JvavParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_defContext ------------------------------------------------------------------

JvavParser::Func_defContext::Func_defContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JvavParser::Func_defContext::Identifier() {
  return getToken(JvavParser::Identifier, 0);
}

tree::TerminalNode* JvavParser::Func_defContext::Lparenthesis() {
  return getToken(JvavParser::Lparenthesis, 0);
}

tree::TerminalNode* JvavParser::Func_defContext::Rparenthesis() {
  return getToken(JvavParser::Rparenthesis, 0);
}

JvavParser::SuiteContext* JvavParser::Func_defContext::suite() {
  return getRuleContext<JvavParser::SuiteContext>(0);
}

JvavParser::TypenameContext* JvavParser::Func_defContext::typename_() {
  return getRuleContext<JvavParser::TypenameContext>(0);
}

tree::TerminalNode* JvavParser::Func_defContext::Void() {
  return getToken(JvavParser::Void, 0);
}

JvavParser::TypedargslistContext* JvavParser::Func_defContext::typedargslist() {
  return getRuleContext<JvavParser::TypedargslistContext>(0);
}


size_t JvavParser::Func_defContext::getRuleIndex() const {
  return JvavParser::RuleFunc_def;
}


std::any JvavParser::Func_defContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JvavParserVisitor*>(visitor))
    return parserVisitor->visitFunc_def(this);
  else
    return visitor->visitChildren(this);
}

JvavParser::Func_defContext* JvavParser::func_def() {
  Func_defContext *_localctx = _tracker.createInstance<Func_defContext>(_ctx, getState());
  enterRule(_localctx, 2, JvavParser::RuleFunc_def);
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
    setState(68);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case JvavParser::Bool:
      case JvavParser::Int:
      case JvavParser::String:
      case JvavParser::Identifier: {
        setState(66);
        typename_();
        break;
      }

      case JvavParser::Void: {
        setState(67);
        match(JvavParser::Void);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(70);
    match(JvavParser::Identifier);
    setState(71);
    match(JvavParser::Lparenthesis);
    setState(73);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 387309567953862656) != 0)) {
      setState(72);
      typedargslist();
    }
    setState(75);
    match(JvavParser::Rparenthesis);
    setState(76);
    suite();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypedargslistContext ------------------------------------------------------------------

JvavParser::TypedargslistContext::TypedargslistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<JvavParser::TypenameContext *> JvavParser::TypedargslistContext::typename_() {
  return getRuleContexts<JvavParser::TypenameContext>();
}

JvavParser::TypenameContext* JvavParser::TypedargslistContext::typename_(size_t i) {
  return getRuleContext<JvavParser::TypenameContext>(i);
}

std::vector<tree::TerminalNode *> JvavParser::TypedargslistContext::Identifier() {
  return getTokens(JvavParser::Identifier);
}

tree::TerminalNode* JvavParser::TypedargslistContext::Identifier(size_t i) {
  return getToken(JvavParser::Identifier, i);
}

std::vector<tree::TerminalNode *> JvavParser::TypedargslistContext::Comma() {
  return getTokens(JvavParser::Comma);
}

tree::TerminalNode* JvavParser::TypedargslistContext::Comma(size_t i) {
  return getToken(JvavParser::Comma, i);
}


size_t JvavParser::TypedargslistContext::getRuleIndex() const {
  return JvavParser::RuleTypedargslist;
}


std::any JvavParser::TypedargslistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JvavParserVisitor*>(visitor))
    return parserVisitor->visitTypedargslist(this);
  else
    return visitor->visitChildren(this);
}

JvavParser::TypedargslistContext* JvavParser::typedargslist() {
  TypedargslistContext *_localctx = _tracker.createInstance<TypedargslistContext>(_ctx, getState());
  enterRule(_localctx, 4, JvavParser::RuleTypedargslist);
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
    setState(78);
    typename_();
    setState(79);
    match(JvavParser::Identifier);
    setState(86);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == JvavParser::Comma) {
      setState(80);
      match(JvavParser::Comma);
      setState(81);
      typename_();
      setState(82);
      match(JvavParser::Identifier);
      setState(88);
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

//----------------- ArgslistContext ------------------------------------------------------------------

JvavParser::ArgslistContext::ArgslistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<JvavParser::ExpressionContext *> JvavParser::ArgslistContext::expression() {
  return getRuleContexts<JvavParser::ExpressionContext>();
}

JvavParser::ExpressionContext* JvavParser::ArgslistContext::expression(size_t i) {
  return getRuleContext<JvavParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> JvavParser::ArgslistContext::Comma() {
  return getTokens(JvavParser::Comma);
}

tree::TerminalNode* JvavParser::ArgslistContext::Comma(size_t i) {
  return getToken(JvavParser::Comma, i);
}


size_t JvavParser::ArgslistContext::getRuleIndex() const {
  return JvavParser::RuleArgslist;
}


std::any JvavParser::ArgslistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JvavParserVisitor*>(visitor))
    return parserVisitor->visitArgslist(this);
  else
    return visitor->visitChildren(this);
}

JvavParser::ArgslistContext* JvavParser::argslist() {
  ArgslistContext *_localctx = _tracker.createInstance<ArgslistContext>(_ctx, getState());
  enterRule(_localctx, 6, JvavParser::RuleArgslist);
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
    setState(89);
    expression(0);
    setState(94);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == JvavParser::Comma) {
      setState(90);
      match(JvavParser::Comma);
      setState(91);
      expression(0);
      setState(96);
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

//----------------- Class_defContext ------------------------------------------------------------------

JvavParser::Class_defContext::Class_defContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JvavParser::Class_defContext::Class() {
  return getToken(JvavParser::Class, 0);
}

tree::TerminalNode* JvavParser::Class_defContext::Identifier() {
  return getToken(JvavParser::Identifier, 0);
}

JvavParser::Class_suiteContext* JvavParser::Class_defContext::class_suite() {
  return getRuleContext<JvavParser::Class_suiteContext>(0);
}

tree::TerminalNode* JvavParser::Class_defContext::Semicolon() {
  return getToken(JvavParser::Semicolon, 0);
}


size_t JvavParser::Class_defContext::getRuleIndex() const {
  return JvavParser::RuleClass_def;
}


std::any JvavParser::Class_defContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JvavParserVisitor*>(visitor))
    return parserVisitor->visitClass_def(this);
  else
    return visitor->visitChildren(this);
}

JvavParser::Class_defContext* JvavParser::class_def() {
  Class_defContext *_localctx = _tracker.createInstance<Class_defContext>(_ctx, getState());
  enterRule(_localctx, 8, JvavParser::RuleClass_def);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(97);
    match(JvavParser::Class);
    setState(98);
    match(JvavParser::Identifier);
    setState(99);
    class_suite();
    setState(100);
    match(JvavParser::Semicolon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Class_suiteContext ------------------------------------------------------------------

JvavParser::Class_suiteContext::Class_suiteContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JvavParser::Class_suiteContext::Lbrace() {
  return getToken(JvavParser::Lbrace, 0);
}

tree::TerminalNode* JvavParser::Class_suiteContext::Rbrace() {
  return getToken(JvavParser::Rbrace, 0);
}

std::vector<JvavParser::Var_defContext *> JvavParser::Class_suiteContext::var_def() {
  return getRuleContexts<JvavParser::Var_defContext>();
}

JvavParser::Var_defContext* JvavParser::Class_suiteContext::var_def(size_t i) {
  return getRuleContext<JvavParser::Var_defContext>(i);
}

std::vector<JvavParser::Func_defContext *> JvavParser::Class_suiteContext::func_def() {
  return getRuleContexts<JvavParser::Func_defContext>();
}

JvavParser::Func_defContext* JvavParser::Class_suiteContext::func_def(size_t i) {
  return getRuleContext<JvavParser::Func_defContext>(i);
}

std::vector<JvavParser::Construct_stmtContext *> JvavParser::Class_suiteContext::construct_stmt() {
  return getRuleContexts<JvavParser::Construct_stmtContext>();
}

JvavParser::Construct_stmtContext* JvavParser::Class_suiteContext::construct_stmt(size_t i) {
  return getRuleContext<JvavParser::Construct_stmtContext>(i);
}


size_t JvavParser::Class_suiteContext::getRuleIndex() const {
  return JvavParser::RuleClass_suite;
}


std::any JvavParser::Class_suiteContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JvavParserVisitor*>(visitor))
    return parserVisitor->visitClass_suite(this);
  else
    return visitor->visitChildren(this);
}

JvavParser::Class_suiteContext* JvavParser::class_suite() {
  Class_suiteContext *_localctx = _tracker.createInstance<Class_suiteContext>(_ctx, getState());
  enterRule(_localctx, 10, JvavParser::RuleClass_suite);
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
    setState(102);
    match(JvavParser::Lbrace);
    setState(108);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 423338364972826624) != 0)) {
      setState(106);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
      case 1: {
        setState(103);
        var_def();
        break;
      }

      case 2: {
        setState(104);
        func_def();
        break;
      }

      case 3: {
        setState(105);
        construct_stmt();
        break;
      }

      default:
        break;
      }
      setState(110);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(111);
    match(JvavParser::Rbrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Construct_stmtContext ------------------------------------------------------------------

JvavParser::Construct_stmtContext::Construct_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JvavParser::Construct_stmtContext::Identifier() {
  return getToken(JvavParser::Identifier, 0);
}

tree::TerminalNode* JvavParser::Construct_stmtContext::Lparenthesis() {
  return getToken(JvavParser::Lparenthesis, 0);
}

tree::TerminalNode* JvavParser::Construct_stmtContext::Rparenthesis() {
  return getToken(JvavParser::Rparenthesis, 0);
}

JvavParser::SuiteContext* JvavParser::Construct_stmtContext::suite() {
  return getRuleContext<JvavParser::SuiteContext>(0);
}


size_t JvavParser::Construct_stmtContext::getRuleIndex() const {
  return JvavParser::RuleConstruct_stmt;
}


std::any JvavParser::Construct_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JvavParserVisitor*>(visitor))
    return parserVisitor->visitConstruct_stmt(this);
  else
    return visitor->visitChildren(this);
}

JvavParser::Construct_stmtContext* JvavParser::construct_stmt() {
  Construct_stmtContext *_localctx = _tracker.createInstance<Construct_stmtContext>(_ctx, getState());
  enterRule(_localctx, 12, JvavParser::RuleConstruct_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(113);
    match(JvavParser::Identifier);
    setState(114);
    match(JvavParser::Lparenthesis);
    setState(115);
    match(JvavParser::Rparenthesis);
    setState(116);
    suite();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Var_defContext ------------------------------------------------------------------

JvavParser::Var_defContext::Var_defContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JvavParser::TypenameContext* JvavParser::Var_defContext::typename_() {
  return getRuleContext<JvavParser::TypenameContext>(0);
}

std::vector<JvavParser::Var_stmtContext *> JvavParser::Var_defContext::var_stmt() {
  return getRuleContexts<JvavParser::Var_stmtContext>();
}

JvavParser::Var_stmtContext* JvavParser::Var_defContext::var_stmt(size_t i) {
  return getRuleContext<JvavParser::Var_stmtContext>(i);
}

tree::TerminalNode* JvavParser::Var_defContext::Semicolon() {
  return getToken(JvavParser::Semicolon, 0);
}

std::vector<tree::TerminalNode *> JvavParser::Var_defContext::Comma() {
  return getTokens(JvavParser::Comma);
}

tree::TerminalNode* JvavParser::Var_defContext::Comma(size_t i) {
  return getToken(JvavParser::Comma, i);
}


size_t JvavParser::Var_defContext::getRuleIndex() const {
  return JvavParser::RuleVar_def;
}


std::any JvavParser::Var_defContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JvavParserVisitor*>(visitor))
    return parserVisitor->visitVar_def(this);
  else
    return visitor->visitChildren(this);
}

JvavParser::Var_defContext* JvavParser::var_def() {
  Var_defContext *_localctx = _tracker.createInstance<Var_defContext>(_ctx, getState());
  enterRule(_localctx, 14, JvavParser::RuleVar_def);
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
    setState(118);
    typename_();
    setState(119);
    var_stmt();
    setState(124);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == JvavParser::Comma) {
      setState(120);
      match(JvavParser::Comma);
      setState(121);
      var_stmt();
      setState(126);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(127);
    match(JvavParser::Semicolon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Var_stmtContext ------------------------------------------------------------------

JvavParser::Var_stmtContext::Var_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JvavParser::Var_stmtContext::Identifier() {
  return getToken(JvavParser::Identifier, 0);
}

tree::TerminalNode* JvavParser::Var_stmtContext::Assign() {
  return getToken(JvavParser::Assign, 0);
}

JvavParser::ExpressionContext* JvavParser::Var_stmtContext::expression() {
  return getRuleContext<JvavParser::ExpressionContext>(0);
}


size_t JvavParser::Var_stmtContext::getRuleIndex() const {
  return JvavParser::RuleVar_stmt;
}


std::any JvavParser::Var_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JvavParserVisitor*>(visitor))
    return parserVisitor->visitVar_stmt(this);
  else
    return visitor->visitChildren(this);
}

JvavParser::Var_stmtContext* JvavParser::var_stmt() {
  Var_stmtContext *_localctx = _tracker.createInstance<Var_stmtContext>(_ctx, getState());
  enterRule(_localctx, 16, JvavParser::RuleVar_stmt);
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
    setState(129);
    match(JvavParser::Identifier);
    setState(132);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == JvavParser::Assign) {
      setState(130);
      match(JvavParser::Assign);
      setState(131);
      expression(0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SuiteContext ------------------------------------------------------------------

JvavParser::SuiteContext::SuiteContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JvavParser::SuiteContext::Lbrace() {
  return getToken(JvavParser::Lbrace, 0);
}

tree::TerminalNode* JvavParser::SuiteContext::Rbrace() {
  return getToken(JvavParser::Rbrace, 0);
}

std::vector<JvavParser::StmtContext *> JvavParser::SuiteContext::stmt() {
  return getRuleContexts<JvavParser::StmtContext>();
}

JvavParser::StmtContext* JvavParser::SuiteContext::stmt(size_t i) {
  return getRuleContext<JvavParser::StmtContext>(i);
}


size_t JvavParser::SuiteContext::getRuleIndex() const {
  return JvavParser::RuleSuite;
}


std::any JvavParser::SuiteContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JvavParserVisitor*>(visitor))
    return parserVisitor->visitSuite(this);
  else
    return visitor->visitChildren(this);
}

JvavParser::SuiteContext* JvavParser::suite() {
  SuiteContext *_localctx = _tracker.createInstance<SuiteContext>(_ctx, getState());
  enterRule(_localctx, 18, JvavParser::RuleSuite);
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
    setState(134);
    match(JvavParser::Lbrace);
    setState(138);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1116886110553654336) != 0)) {
      setState(135);
      stmt();
      setState(140);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(141);
    match(JvavParser::Rbrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

JvavParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t JvavParser::StmtContext::getRuleIndex() const {
  return JvavParser::RuleStmt;
}

void JvavParser::StmtContext::copyFrom(StmtContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- FlowStmtContext ------------------------------------------------------------------

JvavParser::Flow_stmtContext* JvavParser::FlowStmtContext::flow_stmt() {
  return getRuleContext<JvavParser::Flow_stmtContext>(0);
}

JvavParser::FlowStmtContext::FlowStmtContext(StmtContext *ctx) { copyFrom(ctx); }


std::any JvavParser::FlowStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JvavParserVisitor*>(visitor))
    return parserVisitor->visitFlowStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VarDefStmtContext ------------------------------------------------------------------

JvavParser::Var_defContext* JvavParser::VarDefStmtContext::var_def() {
  return getRuleContext<JvavParser::Var_defContext>(0);
}

JvavParser::VarDefStmtContext::VarDefStmtContext(StmtContext *ctx) { copyFrom(ctx); }


std::any JvavParser::VarDefStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JvavParserVisitor*>(visitor))
    return parserVisitor->visitVarDefStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LoopStmtContext ------------------------------------------------------------------

JvavParser::Loop_stmtContext* JvavParser::LoopStmtContext::loop_stmt() {
  return getRuleContext<JvavParser::Loop_stmtContext>(0);
}

JvavParser::LoopStmtContext::LoopStmtContext(StmtContext *ctx) { copyFrom(ctx); }


std::any JvavParser::LoopStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JvavParserVisitor*>(visitor))
    return parserVisitor->visitLoopStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprStmtContext ------------------------------------------------------------------

JvavParser::Expr_stmtContext* JvavParser::ExprStmtContext::expr_stmt() {
  return getRuleContext<JvavParser::Expr_stmtContext>(0);
}

JvavParser::ExprStmtContext::ExprStmtContext(StmtContext *ctx) { copyFrom(ctx); }


std::any JvavParser::ExprStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JvavParserVisitor*>(visitor))
    return parserVisitor->visitExprStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BlockContext ------------------------------------------------------------------

JvavParser::SuiteContext* JvavParser::BlockContext::suite() {
  return getRuleContext<JvavParser::SuiteContext>(0);
}

JvavParser::BlockContext::BlockContext(StmtContext *ctx) { copyFrom(ctx); }


std::any JvavParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JvavParserVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BranchStmtContext ------------------------------------------------------------------

JvavParser::Branch_stmtContext* JvavParser::BranchStmtContext::branch_stmt() {
  return getRuleContext<JvavParser::Branch_stmtContext>(0);
}

JvavParser::BranchStmtContext::BranchStmtContext(StmtContext *ctx) { copyFrom(ctx); }


std::any JvavParser::BranchStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JvavParserVisitor*>(visitor))
    return parserVisitor->visitBranchStmt(this);
  else
    return visitor->visitChildren(this);
}
JvavParser::StmtContext* JvavParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 20, JvavParser::RuleStmt);

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
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<JvavParser::BlockContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(143);
      suite();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<JvavParser::VarDefStmtContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(144);
      var_def();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<JvavParser::BranchStmtContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(145);
      branch_stmt();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<JvavParser::LoopStmtContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(146);
      loop_stmt();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<JvavParser::FlowStmtContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(147);
      flow_stmt();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<JvavParser::ExprStmtContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(148);
      expr_stmt();
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

//----------------- Branch_stmtContext ------------------------------------------------------------------

JvavParser::Branch_stmtContext::Branch_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> JvavParser::Branch_stmtContext::If() {
  return getTokens(JvavParser::If);
}

tree::TerminalNode* JvavParser::Branch_stmtContext::If(size_t i) {
  return getToken(JvavParser::If, i);
}

std::vector<tree::TerminalNode *> JvavParser::Branch_stmtContext::Lparenthesis() {
  return getTokens(JvavParser::Lparenthesis);
}

tree::TerminalNode* JvavParser::Branch_stmtContext::Lparenthesis(size_t i) {
  return getToken(JvavParser::Lparenthesis, i);
}

std::vector<JvavParser::ExpressionContext *> JvavParser::Branch_stmtContext::expression() {
  return getRuleContexts<JvavParser::ExpressionContext>();
}

JvavParser::ExpressionContext* JvavParser::Branch_stmtContext::expression(size_t i) {
  return getRuleContext<JvavParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> JvavParser::Branch_stmtContext::Rparenthesis() {
  return getTokens(JvavParser::Rparenthesis);
}

tree::TerminalNode* JvavParser::Branch_stmtContext::Rparenthesis(size_t i) {
  return getToken(JvavParser::Rparenthesis, i);
}

std::vector<JvavParser::StmtContext *> JvavParser::Branch_stmtContext::stmt() {
  return getRuleContexts<JvavParser::StmtContext>();
}

JvavParser::StmtContext* JvavParser::Branch_stmtContext::stmt(size_t i) {
  return getRuleContext<JvavParser::StmtContext>(i);
}

std::vector<tree::TerminalNode *> JvavParser::Branch_stmtContext::Else() {
  return getTokens(JvavParser::Else);
}

tree::TerminalNode* JvavParser::Branch_stmtContext::Else(size_t i) {
  return getToken(JvavParser::Else, i);
}


size_t JvavParser::Branch_stmtContext::getRuleIndex() const {
  return JvavParser::RuleBranch_stmt;
}


std::any JvavParser::Branch_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JvavParserVisitor*>(visitor))
    return parserVisitor->visitBranch_stmt(this);
  else
    return visitor->visitChildren(this);
}

JvavParser::Branch_stmtContext* JvavParser::branch_stmt() {
  Branch_stmtContext *_localctx = _tracker.createInstance<Branch_stmtContext>(_ctx, getState());
  enterRule(_localctx, 22, JvavParser::RuleBranch_stmt);

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
    setState(151);
    match(JvavParser::If);
    setState(152);
    match(JvavParser::Lparenthesis);
    setState(153);
    expression(0);
    setState(154);
    match(JvavParser::Rparenthesis);
    setState(155);
    stmt();
    setState(165);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(156);
        match(JvavParser::Else);
        setState(157);
        match(JvavParser::If);
        setState(158);
        match(JvavParser::Lparenthesis);
        setState(159);
        expression(0);
        setState(160);
        match(JvavParser::Rparenthesis);
        setState(161);
        stmt(); 
      }
      setState(167);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    }
    setState(170);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      setState(168);
      match(JvavParser::Else);
      setState(169);
      stmt();
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

//----------------- Loop_stmtContext ------------------------------------------------------------------

JvavParser::Loop_stmtContext::Loop_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JvavParser::While_stmtContext* JvavParser::Loop_stmtContext::while_stmt() {
  return getRuleContext<JvavParser::While_stmtContext>(0);
}

JvavParser::For_stmtContext* JvavParser::Loop_stmtContext::for_stmt() {
  return getRuleContext<JvavParser::For_stmtContext>(0);
}


size_t JvavParser::Loop_stmtContext::getRuleIndex() const {
  return JvavParser::RuleLoop_stmt;
}


std::any JvavParser::Loop_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JvavParserVisitor*>(visitor))
    return parserVisitor->visitLoop_stmt(this);
  else
    return visitor->visitChildren(this);
}

JvavParser::Loop_stmtContext* JvavParser::loop_stmt() {
  Loop_stmtContext *_localctx = _tracker.createInstance<Loop_stmtContext>(_ctx, getState());
  enterRule(_localctx, 24, JvavParser::RuleLoop_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(174);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case JvavParser::While: {
        enterOuterAlt(_localctx, 1);
        setState(172);
        while_stmt();
        break;
      }

      case JvavParser::For: {
        enterOuterAlt(_localctx, 2);
        setState(173);
        for_stmt();
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

//----------------- While_stmtContext ------------------------------------------------------------------

JvavParser::While_stmtContext::While_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JvavParser::While_stmtContext::While() {
  return getToken(JvavParser::While, 0);
}

tree::TerminalNode* JvavParser::While_stmtContext::Lparenthesis() {
  return getToken(JvavParser::Lparenthesis, 0);
}

JvavParser::ExpressionContext* JvavParser::While_stmtContext::expression() {
  return getRuleContext<JvavParser::ExpressionContext>(0);
}

tree::TerminalNode* JvavParser::While_stmtContext::Rparenthesis() {
  return getToken(JvavParser::Rparenthesis, 0);
}

JvavParser::StmtContext* JvavParser::While_stmtContext::stmt() {
  return getRuleContext<JvavParser::StmtContext>(0);
}


size_t JvavParser::While_stmtContext::getRuleIndex() const {
  return JvavParser::RuleWhile_stmt;
}


std::any JvavParser::While_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JvavParserVisitor*>(visitor))
    return parserVisitor->visitWhile_stmt(this);
  else
    return visitor->visitChildren(this);
}

JvavParser::While_stmtContext* JvavParser::while_stmt() {
  While_stmtContext *_localctx = _tracker.createInstance<While_stmtContext>(_ctx, getState());
  enterRule(_localctx, 26, JvavParser::RuleWhile_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(176);
    match(JvavParser::While);
    setState(177);
    match(JvavParser::Lparenthesis);
    setState(178);
    expression(0);
    setState(179);
    match(JvavParser::Rparenthesis);
    setState(180);
    stmt();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- For_stmtContext ------------------------------------------------------------------

JvavParser::For_stmtContext::For_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JvavParser::For_stmtContext::For() {
  return getToken(JvavParser::For, 0);
}

tree::TerminalNode* JvavParser::For_stmtContext::Lparenthesis() {
  return getToken(JvavParser::Lparenthesis, 0);
}

std::vector<tree::TerminalNode *> JvavParser::For_stmtContext::Semicolon() {
  return getTokens(JvavParser::Semicolon);
}

tree::TerminalNode* JvavParser::For_stmtContext::Semicolon(size_t i) {
  return getToken(JvavParser::Semicolon, i);
}

tree::TerminalNode* JvavParser::For_stmtContext::Rparenthesis() {
  return getToken(JvavParser::Rparenthesis, 0);
}

JvavParser::StmtContext* JvavParser::For_stmtContext::stmt() {
  return getRuleContext<JvavParser::StmtContext>(0);
}

JvavParser::Var_defContext* JvavParser::For_stmtContext::var_def() {
  return getRuleContext<JvavParser::Var_defContext>(0);
}

std::vector<JvavParser::ExpressionContext *> JvavParser::For_stmtContext::expression() {
  return getRuleContexts<JvavParser::ExpressionContext>();
}

JvavParser::ExpressionContext* JvavParser::For_stmtContext::expression(size_t i) {
  return getRuleContext<JvavParser::ExpressionContext>(i);
}


size_t JvavParser::For_stmtContext::getRuleIndex() const {
  return JvavParser::RuleFor_stmt;
}


std::any JvavParser::For_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JvavParserVisitor*>(visitor))
    return parserVisitor->visitFor_stmt(this);
  else
    return visitor->visitChildren(this);
}

JvavParser::For_stmtContext* JvavParser::for_stmt() {
  For_stmtContext *_localctx = _tracker.createInstance<For_stmtContext>(_ctx, getState());
  enterRule(_localctx, 28, JvavParser::RuleFor_stmt);
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
    setState(182);
    match(JvavParser::For);
    setState(183);
    match(JvavParser::Lparenthesis);
    setState(189);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      setState(185);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 1017532040844542016) != 0)) {
        setState(184);
        antlrcpp::downCast<For_stmtContext *>(_localctx)->init = expression(0);
      }
      setState(187);
      match(JvavParser::Semicolon);
      break;
    }

    case 2: {
      setState(188);
      var_def();
      break;
    }

    default:
      break;
    }
    setState(192);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1017532040844542016) != 0)) {
      setState(191);
      antlrcpp::downCast<For_stmtContext *>(_localctx)->cond = expression(0);
    }
    setState(194);
    match(JvavParser::Semicolon);
    setState(196);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1017532040844542016) != 0)) {
      setState(195);
      antlrcpp::downCast<For_stmtContext *>(_localctx)->step = expression(0);
    }
    setState(198);
    match(JvavParser::Rparenthesis);
    setState(199);
    stmt();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Flow_stmtContext ------------------------------------------------------------------

JvavParser::Flow_stmtContext::Flow_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JvavParser::Return_stmtContext* JvavParser::Flow_stmtContext::return_stmt() {
  return getRuleContext<JvavParser::Return_stmtContext>(0);
}

JvavParser::Break_stmtContext* JvavParser::Flow_stmtContext::break_stmt() {
  return getRuleContext<JvavParser::Break_stmtContext>(0);
}

JvavParser::Continue_stmtContext* JvavParser::Flow_stmtContext::continue_stmt() {
  return getRuleContext<JvavParser::Continue_stmtContext>(0);
}


size_t JvavParser::Flow_stmtContext::getRuleIndex() const {
  return JvavParser::RuleFlow_stmt;
}


std::any JvavParser::Flow_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JvavParserVisitor*>(visitor))
    return parserVisitor->visitFlow_stmt(this);
  else
    return visitor->visitChildren(this);
}

JvavParser::Flow_stmtContext* JvavParser::flow_stmt() {
  Flow_stmtContext *_localctx = _tracker.createInstance<Flow_stmtContext>(_ctx, getState());
  enterRule(_localctx, 30, JvavParser::RuleFlow_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(204);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case JvavParser::Return: {
        enterOuterAlt(_localctx, 1);
        setState(201);
        return_stmt();
        break;
      }

      case JvavParser::Break: {
        enterOuterAlt(_localctx, 2);
        setState(202);
        break_stmt();
        break;
      }

      case JvavParser::Continue: {
        enterOuterAlt(_localctx, 3);
        setState(203);
        continue_stmt();
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

//----------------- Return_stmtContext ------------------------------------------------------------------

JvavParser::Return_stmtContext::Return_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JvavParser::Return_stmtContext::Return() {
  return getToken(JvavParser::Return, 0);
}

tree::TerminalNode* JvavParser::Return_stmtContext::Semicolon() {
  return getToken(JvavParser::Semicolon, 0);
}

JvavParser::ExpressionContext* JvavParser::Return_stmtContext::expression() {
  return getRuleContext<JvavParser::ExpressionContext>(0);
}


size_t JvavParser::Return_stmtContext::getRuleIndex() const {
  return JvavParser::RuleReturn_stmt;
}


std::any JvavParser::Return_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JvavParserVisitor*>(visitor))
    return parserVisitor->visitReturn_stmt(this);
  else
    return visitor->visitChildren(this);
}

JvavParser::Return_stmtContext* JvavParser::return_stmt() {
  Return_stmtContext *_localctx = _tracker.createInstance<Return_stmtContext>(_ctx, getState());
  enterRule(_localctx, 32, JvavParser::RuleReturn_stmt);
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
    setState(206);
    match(JvavParser::Return);
    setState(208);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1017532040844542016) != 0)) {
      setState(207);
      expression(0);
    }
    setState(210);
    match(JvavParser::Semicolon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Break_stmtContext ------------------------------------------------------------------

JvavParser::Break_stmtContext::Break_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JvavParser::Break_stmtContext::Break() {
  return getToken(JvavParser::Break, 0);
}

tree::TerminalNode* JvavParser::Break_stmtContext::Semicolon() {
  return getToken(JvavParser::Semicolon, 0);
}


size_t JvavParser::Break_stmtContext::getRuleIndex() const {
  return JvavParser::RuleBreak_stmt;
}


std::any JvavParser::Break_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JvavParserVisitor*>(visitor))
    return parserVisitor->visitBreak_stmt(this);
  else
    return visitor->visitChildren(this);
}

JvavParser::Break_stmtContext* JvavParser::break_stmt() {
  Break_stmtContext *_localctx = _tracker.createInstance<Break_stmtContext>(_ctx, getState());
  enterRule(_localctx, 34, JvavParser::RuleBreak_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(212);
    match(JvavParser::Break);
    setState(213);
    match(JvavParser::Semicolon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Continue_stmtContext ------------------------------------------------------------------

JvavParser::Continue_stmtContext::Continue_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JvavParser::Continue_stmtContext::Continue() {
  return getToken(JvavParser::Continue, 0);
}

tree::TerminalNode* JvavParser::Continue_stmtContext::Semicolon() {
  return getToken(JvavParser::Semicolon, 0);
}


size_t JvavParser::Continue_stmtContext::getRuleIndex() const {
  return JvavParser::RuleContinue_stmt;
}


std::any JvavParser::Continue_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JvavParserVisitor*>(visitor))
    return parserVisitor->visitContinue_stmt(this);
  else
    return visitor->visitChildren(this);
}

JvavParser::Continue_stmtContext* JvavParser::continue_stmt() {
  Continue_stmtContext *_localctx = _tracker.createInstance<Continue_stmtContext>(_ctx, getState());
  enterRule(_localctx, 36, JvavParser::RuleContinue_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(215);
    match(JvavParser::Continue);
    setState(216);
    match(JvavParser::Semicolon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expr_stmtContext ------------------------------------------------------------------

JvavParser::Expr_stmtContext::Expr_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JvavParser::Expr_stmtContext::Semicolon() {
  return getToken(JvavParser::Semicolon, 0);
}

std::vector<JvavParser::ExpressionContext *> JvavParser::Expr_stmtContext::expression() {
  return getRuleContexts<JvavParser::ExpressionContext>();
}

JvavParser::ExpressionContext* JvavParser::Expr_stmtContext::expression(size_t i) {
  return getRuleContext<JvavParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> JvavParser::Expr_stmtContext::Comma() {
  return getTokens(JvavParser::Comma);
}

tree::TerminalNode* JvavParser::Expr_stmtContext::Comma(size_t i) {
  return getToken(JvavParser::Comma, i);
}


size_t JvavParser::Expr_stmtContext::getRuleIndex() const {
  return JvavParser::RuleExpr_stmt;
}


std::any JvavParser::Expr_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JvavParserVisitor*>(visitor))
    return parserVisitor->visitExpr_stmt(this);
  else
    return visitor->visitChildren(this);
}

JvavParser::Expr_stmtContext* JvavParser::expr_stmt() {
  Expr_stmtContext *_localctx = _tracker.createInstance<Expr_stmtContext>(_ctx, getState());
  enterRule(_localctx, 38, JvavParser::RuleExpr_stmt);
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
    setState(226);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1017532040844542016) != 0)) {
      setState(218);
      expression(0);
      setState(223);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == JvavParser::Comma) {
        setState(219);
        match(JvavParser::Comma);
        setState(220);
        expression(0);
        setState(225);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(228);
    match(JvavParser::Semicolon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

JvavParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t JvavParser::ExpressionContext::getRuleIndex() const {
  return JvavParser::RuleExpression;
}

void JvavParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- NewExprContext ------------------------------------------------------------------

JvavParser::New_exprContext* JvavParser::NewExprContext::new_expr() {
  return getRuleContext<JvavParser::New_exprContext>(0);
}

JvavParser::NewExprContext::NewExprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any JvavParser::NewExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JvavParserVisitor*>(visitor))
    return parserVisitor->visitNewExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ThisExprContext ------------------------------------------------------------------

tree::TerminalNode* JvavParser::ThisExprContext::This() {
  return getToken(JvavParser::This, 0);
}

JvavParser::ThisExprContext::ThisExprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any JvavParser::ThisExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JvavParserVisitor*>(visitor))
    return parserVisitor->visitThisExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FuncExprContext ------------------------------------------------------------------

JvavParser::Func_exprContext* JvavParser::FuncExprContext::func_expr() {
  return getRuleContext<JvavParser::Func_exprContext>(0);
}

JvavParser::FuncExprContext::FuncExprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any JvavParser::FuncExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JvavParserVisitor*>(visitor))
    return parserVisitor->visitFuncExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArrayExprContext ------------------------------------------------------------------

std::vector<JvavParser::ExpressionContext *> JvavParser::ArrayExprContext::expression() {
  return getRuleContexts<JvavParser::ExpressionContext>();
}

JvavParser::ExpressionContext* JvavParser::ArrayExprContext::expression(size_t i) {
  return getRuleContext<JvavParser::ExpressionContext>(i);
}

tree::TerminalNode* JvavParser::ArrayExprContext::Lbracket() {
  return getToken(JvavParser::Lbracket, 0);
}

tree::TerminalNode* JvavParser::ArrayExprContext::Rbracket() {
  return getToken(JvavParser::Rbracket, 0);
}

JvavParser::ArrayExprContext::ArrayExprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any JvavParser::ArrayExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JvavParserVisitor*>(visitor))
    return parserVisitor->visitArrayExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MemberExprContext ------------------------------------------------------------------

std::vector<JvavParser::ExpressionContext *> JvavParser::MemberExprContext::expression() {
  return getRuleContexts<JvavParser::ExpressionContext>();
}

JvavParser::ExpressionContext* JvavParser::MemberExprContext::expression(size_t i) {
  return getRuleContext<JvavParser::ExpressionContext>(i);
}

tree::TerminalNode* JvavParser::MemberExprContext::Dot() {
  return getToken(JvavParser::Dot, 0);
}

JvavParser::MemberExprContext::MemberExprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any JvavParser::MemberExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JvavParserVisitor*>(visitor))
    return parserVisitor->visitMemberExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BinaryExprContext ------------------------------------------------------------------

std::vector<JvavParser::ExpressionContext *> JvavParser::BinaryExprContext::expression() {
  return getRuleContexts<JvavParser::ExpressionContext>();
}

JvavParser::ExpressionContext* JvavParser::BinaryExprContext::expression(size_t i) {
  return getRuleContext<JvavParser::ExpressionContext>(i);
}

tree::TerminalNode* JvavParser::BinaryExprContext::Mul() {
  return getToken(JvavParser::Mul, 0);
}

tree::TerminalNode* JvavParser::BinaryExprContext::Div() {
  return getToken(JvavParser::Div, 0);
}

tree::TerminalNode* JvavParser::BinaryExprContext::Mod() {
  return getToken(JvavParser::Mod, 0);
}

tree::TerminalNode* JvavParser::BinaryExprContext::Add() {
  return getToken(JvavParser::Add, 0);
}

tree::TerminalNode* JvavParser::BinaryExprContext::Sub() {
  return getToken(JvavParser::Sub, 0);
}

tree::TerminalNode* JvavParser::BinaryExprContext::Lshift() {
  return getToken(JvavParser::Lshift, 0);
}

tree::TerminalNode* JvavParser::BinaryExprContext::Rshift() {
  return getToken(JvavParser::Rshift, 0);
}

tree::TerminalNode* JvavParser::BinaryExprContext::Lessthan() {
  return getToken(JvavParser::Lessthan, 0);
}

tree::TerminalNode* JvavParser::BinaryExprContext::Greaterthan() {
  return getToken(JvavParser::Greaterthan, 0);
}

tree::TerminalNode* JvavParser::BinaryExprContext::Lessthanequal() {
  return getToken(JvavParser::Lessthanequal, 0);
}

tree::TerminalNode* JvavParser::BinaryExprContext::Greaterthanequal() {
  return getToken(JvavParser::Greaterthanequal, 0);
}

tree::TerminalNode* JvavParser::BinaryExprContext::Equal() {
  return getToken(JvavParser::Equal, 0);
}

tree::TerminalNode* JvavParser::BinaryExprContext::Notequal() {
  return getToken(JvavParser::Notequal, 0);
}

tree::TerminalNode* JvavParser::BinaryExprContext::Bitand() {
  return getToken(JvavParser::Bitand, 0);
}

tree::TerminalNode* JvavParser::BinaryExprContext::Bitxor() {
  return getToken(JvavParser::Bitxor, 0);
}

tree::TerminalNode* JvavParser::BinaryExprContext::Bitor() {
  return getToken(JvavParser::Bitor, 0);
}

tree::TerminalNode* JvavParser::BinaryExprContext::And() {
  return getToken(JvavParser::And, 0);
}

tree::TerminalNode* JvavParser::BinaryExprContext::Or() {
  return getToken(JvavParser::Or, 0);
}

JvavParser::BinaryExprContext::BinaryExprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any JvavParser::BinaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JvavParserVisitor*>(visitor))
    return parserVisitor->visitBinaryExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PrefixUnaryExprContext ------------------------------------------------------------------

JvavParser::ExpressionContext* JvavParser::PrefixUnaryExprContext::expression() {
  return getRuleContext<JvavParser::ExpressionContext>(0);
}

tree::TerminalNode* JvavParser::PrefixUnaryExprContext::Increment() {
  return getToken(JvavParser::Increment, 0);
}

tree::TerminalNode* JvavParser::PrefixUnaryExprContext::Decrement() {
  return getToken(JvavParser::Decrement, 0);
}

tree::TerminalNode* JvavParser::PrefixUnaryExprContext::Not() {
  return getToken(JvavParser::Not, 0);
}

tree::TerminalNode* JvavParser::PrefixUnaryExprContext::Inv() {
  return getToken(JvavParser::Inv, 0);
}

tree::TerminalNode* JvavParser::PrefixUnaryExprContext::Sub() {
  return getToken(JvavParser::Sub, 0);
}

JvavParser::PrefixUnaryExprContext::PrefixUnaryExprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any JvavParser::PrefixUnaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JvavParserVisitor*>(visitor))
    return parserVisitor->visitPrefixUnaryExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VarExprContext ------------------------------------------------------------------

tree::TerminalNode* JvavParser::VarExprContext::Identifier() {
  return getToken(JvavParser::Identifier, 0);
}

JvavParser::VarExprContext::VarExprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any JvavParser::VarExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JvavParserVisitor*>(visitor))
    return parserVisitor->visitVarExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TernaryExprContext ------------------------------------------------------------------

std::vector<JvavParser::ExpressionContext *> JvavParser::TernaryExprContext::expression() {
  return getRuleContexts<JvavParser::ExpressionContext>();
}

JvavParser::ExpressionContext* JvavParser::TernaryExprContext::expression(size_t i) {
  return getRuleContext<JvavParser::ExpressionContext>(i);
}

tree::TerminalNode* JvavParser::TernaryExprContext::Question() {
  return getToken(JvavParser::Question, 0);
}

tree::TerminalNode* JvavParser::TernaryExprContext::Colon() {
  return getToken(JvavParser::Colon, 0);
}

JvavParser::TernaryExprContext::TernaryExprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any JvavParser::TernaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JvavParserVisitor*>(visitor))
    return parserVisitor->visitTernaryExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PureExprContext ------------------------------------------------------------------

tree::TerminalNode* JvavParser::PureExprContext::Lparenthesis() {
  return getToken(JvavParser::Lparenthesis, 0);
}

JvavParser::ExpressionContext* JvavParser::PureExprContext::expression() {
  return getRuleContext<JvavParser::ExpressionContext>(0);
}

tree::TerminalNode* JvavParser::PureExprContext::Rparenthesis() {
  return getToken(JvavParser::Rparenthesis, 0);
}

JvavParser::PureExprContext::PureExprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any JvavParser::PureExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JvavParserVisitor*>(visitor))
    return parserVisitor->visitPureExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignExprContext ------------------------------------------------------------------

std::vector<JvavParser::ExpressionContext *> JvavParser::AssignExprContext::expression() {
  return getRuleContexts<JvavParser::ExpressionContext>();
}

JvavParser::ExpressionContext* JvavParser::AssignExprContext::expression(size_t i) {
  return getRuleContext<JvavParser::ExpressionContext>(i);
}

tree::TerminalNode* JvavParser::AssignExprContext::Assign() {
  return getToken(JvavParser::Assign, 0);
}

JvavParser::AssignExprContext::AssignExprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any JvavParser::AssignExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JvavParserVisitor*>(visitor))
    return parserVisitor->visitAssignExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SuffixUnaryExprContext ------------------------------------------------------------------

JvavParser::ExpressionContext* JvavParser::SuffixUnaryExprContext::expression() {
  return getRuleContext<JvavParser::ExpressionContext>(0);
}

tree::TerminalNode* JvavParser::SuffixUnaryExprContext::Increment() {
  return getToken(JvavParser::Increment, 0);
}

tree::TerminalNode* JvavParser::SuffixUnaryExprContext::Decrement() {
  return getToken(JvavParser::Decrement, 0);
}

JvavParser::SuffixUnaryExprContext::SuffixUnaryExprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any JvavParser::SuffixUnaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JvavParserVisitor*>(visitor))
    return parserVisitor->visitSuffixUnaryExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ConstExprContext ------------------------------------------------------------------

JvavParser::Const_exprContext* JvavParser::ConstExprContext::const_expr() {
  return getRuleContext<JvavParser::Const_exprContext>(0);
}

JvavParser::ConstExprContext::ConstExprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any JvavParser::ConstExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JvavParserVisitor*>(visitor))
    return parserVisitor->visitConstExpr(this);
  else
    return visitor->visitChildren(this);
}

JvavParser::ExpressionContext* JvavParser::expression() {
   return expression(0);
}

JvavParser::ExpressionContext* JvavParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  JvavParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  JvavParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 40;
  enterRecursionRule(_localctx, 40, JvavParser::RuleExpression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(244);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<PureExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(231);
      match(JvavParser::Lparenthesis);
      setState(232);
      expression(0);
      setState(233);
      match(JvavParser::Rparenthesis);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ConstExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(235);
      const_expr();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<VarExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(236);
      match(JvavParser::Identifier);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<ThisExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(237);
      match(JvavParser::This);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<FuncExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(238);
      func_expr();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<NewExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(239);
      new_expr();
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<PrefixUnaryExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(240);
      antlrcpp::downCast<PrefixUnaryExprContext *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == JvavParser::Increment

      || _la == JvavParser::Decrement)) {
        antlrcpp::downCast<PrefixUnaryExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(241);
      expression(14);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<PrefixUnaryExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(242);
      antlrcpp::downCast<PrefixUnaryExprContext *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 35127296) != 0))) {
        antlrcpp::downCast<PrefixUnaryExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(243);
      expression(13);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(297);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(295);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MemberExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(246);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(247);
          match(JvavParser::Dot);
          setState(248);
          expression(20);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(249);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(250);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 14680064) != 0))) {
            antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(251);
          expression(13);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(252);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(253);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == JvavParser::Add

          || _la == JvavParser::Sub)) {
            antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(254);
          expression(12);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(255);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(256);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == JvavParser::Lshift

          || _la == JvavParser::Rshift)) {
            antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(257);
          expression(11);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(258);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(259);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 4026531840) != 0))) {
            antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(260);
          expression(10);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(261);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(262);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == JvavParser::Equal

          || _la == JvavParser::Notequal)) {
            antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(263);
          expression(9);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(264);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(265);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = match(JvavParser::Bitand);
          setState(266);
          expression(8);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(267);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(268);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = match(JvavParser::Bitxor);
          setState(269);
          expression(7);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(270);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(271);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = match(JvavParser::Bitor);
          setState(272);
          expression(6);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(273);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(274);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = match(JvavParser::And);
          setState(275);
          expression(5);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(276);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(277);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = match(JvavParser::Or);
          setState(278);
          expression(4);
          break;
        }

        case 12: {
          auto newContext = _tracker.createInstance<TernaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(279);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(280);
          match(JvavParser::Question);
          setState(281);
          expression(0);
          setState(282);
          match(JvavParser::Colon);
          setState(283);
          expression(2);
          break;
        }

        case 13: {
          auto newContext = _tracker.createInstance<AssignExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(285);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(286);
          match(JvavParser::Assign);
          setState(287);
          expression(1);
          break;
        }

        case 14: {
          auto newContext = _tracker.createInstance<ArrayExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(288);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(289);
          match(JvavParser::Lbracket);
          setState(290);
          expression(0);
          setState(291);
          match(JvavParser::Rbracket);
          break;
        }

        case 15: {
          auto newContext = _tracker.createInstance<SuffixUnaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(293);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(294);
          antlrcpp::downCast<SuffixUnaryExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == JvavParser::Increment

          || _la == JvavParser::Decrement)) {
            antlrcpp::downCast<SuffixUnaryExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          break;
        }

        default:
          break;
        } 
      }
      setState(299);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Const_exprContext ------------------------------------------------------------------

JvavParser::Const_exprContext::Const_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JvavParser::Const_exprContext::True() {
  return getToken(JvavParser::True, 0);
}

tree::TerminalNode* JvavParser::Const_exprContext::False() {
  return getToken(JvavParser::False, 0);
}

tree::TerminalNode* JvavParser::Const_exprContext::Number() {
  return getToken(JvavParser::Number, 0);
}

tree::TerminalNode* JvavParser::Const_exprContext::Str() {
  return getToken(JvavParser::Str, 0);
}

tree::TerminalNode* JvavParser::Const_exprContext::Null() {
  return getToken(JvavParser::Null, 0);
}


size_t JvavParser::Const_exprContext::getRuleIndex() const {
  return JvavParser::RuleConst_expr;
}


std::any JvavParser::Const_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JvavParserVisitor*>(visitor))
    return parserVisitor->visitConst_expr(this);
  else
    return visitor->visitChildren(this);
}

JvavParser::Const_exprContext* JvavParser::const_expr() {
  Const_exprContext *_localctx = _tracker.createInstance<Const_exprContext>(_ctx, getState());
  enterRule(_localctx, 42, JvavParser::RuleConst_expr);
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
    setState(300);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 724516590053228544) != 0))) {
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

//----------------- Func_exprContext ------------------------------------------------------------------

JvavParser::Func_exprContext::Func_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JvavParser::Func_exprContext::Identifier() {
  return getToken(JvavParser::Identifier, 0);
}

tree::TerminalNode* JvavParser::Func_exprContext::Lparenthesis() {
  return getToken(JvavParser::Lparenthesis, 0);
}

tree::TerminalNode* JvavParser::Func_exprContext::Rparenthesis() {
  return getToken(JvavParser::Rparenthesis, 0);
}

JvavParser::ArgslistContext* JvavParser::Func_exprContext::argslist() {
  return getRuleContext<JvavParser::ArgslistContext>(0);
}


size_t JvavParser::Func_exprContext::getRuleIndex() const {
  return JvavParser::RuleFunc_expr;
}


std::any JvavParser::Func_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JvavParserVisitor*>(visitor))
    return parserVisitor->visitFunc_expr(this);
  else
    return visitor->visitChildren(this);
}

JvavParser::Func_exprContext* JvavParser::func_expr() {
  Func_exprContext *_localctx = _tracker.createInstance<Func_exprContext>(_ctx, getState());
  enterRule(_localctx, 44, JvavParser::RuleFunc_expr);
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
    setState(302);
    match(JvavParser::Identifier);
    setState(303);
    match(JvavParser::Lparenthesis);
    setState(305);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1017532040844542016) != 0)) {
      setState(304);
      argslist();
    }
    setState(307);
    match(JvavParser::Rparenthesis);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- New_exprContext ------------------------------------------------------------------

JvavParser::New_exprContext::New_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JvavParser::Newerror_exprContext* JvavParser::New_exprContext::newerror_expr() {
  return getRuleContext<JvavParser::Newerror_exprContext>(0);
}

JvavParser::Newvar_exprContext* JvavParser::New_exprContext::newvar_expr() {
  return getRuleContext<JvavParser::Newvar_exprContext>(0);
}


size_t JvavParser::New_exprContext::getRuleIndex() const {
  return JvavParser::RuleNew_expr;
}


std::any JvavParser::New_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JvavParserVisitor*>(visitor))
    return parserVisitor->visitNew_expr(this);
  else
    return visitor->visitChildren(this);
}

JvavParser::New_exprContext* JvavParser::new_expr() {
  New_exprContext *_localctx = _tracker.createInstance<New_exprContext>(_ctx, getState());
  enterRule(_localctx, 46, JvavParser::RuleNew_expr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(311);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(309);
      newerror_expr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(310);
      newvar_expr();
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

//----------------- Newerror_exprContext ------------------------------------------------------------------

JvavParser::Newerror_exprContext::Newerror_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JvavParser::Newerror_exprContext::New() {
  return getToken(JvavParser::New, 0);
}

JvavParser::Basic_typeContext* JvavParser::Newerror_exprContext::basic_type() {
  return getRuleContext<JvavParser::Basic_typeContext>(0);
}

std::vector<tree::TerminalNode *> JvavParser::Newerror_exprContext::Lbracket() {
  return getTokens(JvavParser::Lbracket);
}

tree::TerminalNode* JvavParser::Newerror_exprContext::Lbracket(size_t i) {
  return getToken(JvavParser::Lbracket, i);
}

std::vector<JvavParser::ExpressionContext *> JvavParser::Newerror_exprContext::expression() {
  return getRuleContexts<JvavParser::ExpressionContext>();
}

JvavParser::ExpressionContext* JvavParser::Newerror_exprContext::expression(size_t i) {
  return getRuleContext<JvavParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> JvavParser::Newerror_exprContext::Rbracket() {
  return getTokens(JvavParser::Rbracket);
}

tree::TerminalNode* JvavParser::Newerror_exprContext::Rbracket(size_t i) {
  return getToken(JvavParser::Rbracket, i);
}

tree::TerminalNode* JvavParser::Newerror_exprContext::Lparenthesis() {
  return getToken(JvavParser::Lparenthesis, 0);
}

tree::TerminalNode* JvavParser::Newerror_exprContext::Rparenthesis() {
  return getToken(JvavParser::Rparenthesis, 0);
}


size_t JvavParser::Newerror_exprContext::getRuleIndex() const {
  return JvavParser::RuleNewerror_expr;
}


std::any JvavParser::Newerror_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JvavParserVisitor*>(visitor))
    return parserVisitor->visitNewerror_expr(this);
  else
    return visitor->visitChildren(this);
}

JvavParser::Newerror_exprContext* JvavParser::newerror_expr() {
  Newerror_exprContext *_localctx = _tracker.createInstance<Newerror_exprContext>(_ctx, getState());
  enterRule(_localctx, 48, JvavParser::RuleNewerror_expr);

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
    setState(313);
    match(JvavParser::New);
    setState(314);
    basic_type();
    setState(321);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(315);
        match(JvavParser::Lbracket);
        setState(316);
        expression(0);
        setState(317);
        match(JvavParser::Rbracket); 
      }
      setState(323);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
    }
    setState(326); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(324);
              match(JvavParser::Lbracket);
              setState(325);
              match(JvavParser::Rbracket);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(328); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
    setState(334); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(330);
              match(JvavParser::Lbracket);
              setState(331);
              expression(0);
              setState(332);
              match(JvavParser::Rbracket);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(336); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
    setState(340);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
    case 1: {
      setState(338);
      match(JvavParser::Lparenthesis);
      setState(339);
      match(JvavParser::Rparenthesis);
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

//----------------- Newvar_exprContext ------------------------------------------------------------------

JvavParser::Newvar_exprContext::Newvar_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JvavParser::Newvar_exprContext::New() {
  return getToken(JvavParser::New, 0);
}

JvavParser::Basic_typeContext* JvavParser::Newvar_exprContext::basic_type() {
  return getRuleContext<JvavParser::Basic_typeContext>(0);
}

std::vector<tree::TerminalNode *> JvavParser::Newvar_exprContext::Lbracket() {
  return getTokens(JvavParser::Lbracket);
}

tree::TerminalNode* JvavParser::Newvar_exprContext::Lbracket(size_t i) {
  return getToken(JvavParser::Lbracket, i);
}

std::vector<JvavParser::ExpressionContext *> JvavParser::Newvar_exprContext::expression() {
  return getRuleContexts<JvavParser::ExpressionContext>();
}

JvavParser::ExpressionContext* JvavParser::Newvar_exprContext::expression(size_t i) {
  return getRuleContext<JvavParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> JvavParser::Newvar_exprContext::Rbracket() {
  return getTokens(JvavParser::Rbracket);
}

tree::TerminalNode* JvavParser::Newvar_exprContext::Rbracket(size_t i) {
  return getToken(JvavParser::Rbracket, i);
}

tree::TerminalNode* JvavParser::Newvar_exprContext::Lparenthesis() {
  return getToken(JvavParser::Lparenthesis, 0);
}

tree::TerminalNode* JvavParser::Newvar_exprContext::Rparenthesis() {
  return getToken(JvavParser::Rparenthesis, 0);
}


size_t JvavParser::Newvar_exprContext::getRuleIndex() const {
  return JvavParser::RuleNewvar_expr;
}


std::any JvavParser::Newvar_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JvavParserVisitor*>(visitor))
    return parserVisitor->visitNewvar_expr(this);
  else
    return visitor->visitChildren(this);
}

JvavParser::Newvar_exprContext* JvavParser::newvar_expr() {
  Newvar_exprContext *_localctx = _tracker.createInstance<Newvar_exprContext>(_ctx, getState());
  enterRule(_localctx, 50, JvavParser::RuleNewvar_expr);

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
    setState(342);
    match(JvavParser::New);
    setState(343);
    basic_type();
    setState(350);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(344);
        match(JvavParser::Lbracket);
        setState(345);
        expression(0);
        setState(346);
        match(JvavParser::Rbracket); 
      }
      setState(352);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
    }
    setState(357);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(353);
        match(JvavParser::Lbracket);
        setState(354);
        match(JvavParser::Rbracket); 
      }
      setState(359);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    }
    setState(362);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
    case 1: {
      setState(360);
      match(JvavParser::Lparenthesis);
      setState(361);
      match(JvavParser::Rparenthesis);
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

//----------------- TypenameContext ------------------------------------------------------------------

JvavParser::TypenameContext::TypenameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JvavParser::Basic_typeContext* JvavParser::TypenameContext::basic_type() {
  return getRuleContext<JvavParser::Basic_typeContext>(0);
}

std::vector<tree::TerminalNode *> JvavParser::TypenameContext::Lbracket() {
  return getTokens(JvavParser::Lbracket);
}

tree::TerminalNode* JvavParser::TypenameContext::Lbracket(size_t i) {
  return getToken(JvavParser::Lbracket, i);
}

std::vector<tree::TerminalNode *> JvavParser::TypenameContext::Rbracket() {
  return getTokens(JvavParser::Rbracket);
}

tree::TerminalNode* JvavParser::TypenameContext::Rbracket(size_t i) {
  return getToken(JvavParser::Rbracket, i);
}


size_t JvavParser::TypenameContext::getRuleIndex() const {
  return JvavParser::RuleTypename;
}


std::any JvavParser::TypenameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JvavParserVisitor*>(visitor))
    return parserVisitor->visitTypename(this);
  else
    return visitor->visitChildren(this);
}

JvavParser::TypenameContext* JvavParser::typename_() {
  TypenameContext *_localctx = _tracker.createInstance<TypenameContext>(_ctx, getState());
  enterRule(_localctx, 52, JvavParser::RuleTypename);
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
    setState(364);
    basic_type();
    setState(369);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == JvavParser::Lbracket) {
      setState(365);
      match(JvavParser::Lbracket);
      setState(366);
      match(JvavParser::Rbracket);
      setState(371);
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

//----------------- Basic_typeContext ------------------------------------------------------------------

JvavParser::Basic_typeContext::Basic_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JvavParser::Basic_typeContext::Bool() {
  return getToken(JvavParser::Bool, 0);
}

tree::TerminalNode* JvavParser::Basic_typeContext::Int() {
  return getToken(JvavParser::Int, 0);
}

tree::TerminalNode* JvavParser::Basic_typeContext::String() {
  return getToken(JvavParser::String, 0);
}

tree::TerminalNode* JvavParser::Basic_typeContext::Identifier() {
  return getToken(JvavParser::Identifier, 0);
}


size_t JvavParser::Basic_typeContext::getRuleIndex() const {
  return JvavParser::RuleBasic_type;
}


std::any JvavParser::Basic_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JvavParserVisitor*>(visitor))
    return parserVisitor->visitBasic_type(this);
  else
    return visitor->visitChildren(this);
}

JvavParser::Basic_typeContext* JvavParser::basic_type() {
  Basic_typeContext *_localctx = _tracker.createInstance<Basic_typeContext>(_ctx, getState());
  enterRule(_localctx, 54, JvavParser::RuleBasic_type);
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
    setState(372);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 387309567953862656) != 0))) {
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

bool JvavParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 20: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool JvavParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 19);
    case 1: return precpred(_ctx, 12);
    case 2: return precpred(_ctx, 11);
    case 3: return precpred(_ctx, 10);
    case 4: return precpred(_ctx, 9);
    case 5: return precpred(_ctx, 8);
    case 6: return precpred(_ctx, 7);
    case 7: return precpred(_ctx, 6);
    case 8: return precpred(_ctx, 5);
    case 9: return precpred(_ctx, 4);
    case 10: return precpred(_ctx, 3);
    case 11: return precpred(_ctx, 2);
    case 12: return precpred(_ctx, 1);
    case 13: return precpred(_ctx, 17);
    case 14: return precpred(_ctx, 15);

  default:
    break;
  }
  return true;
}

void JvavParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  jvavparserParserInitialize();
#else
  ::antlr4::internal::call_once(jvavparserParserOnceFlag, jvavparserParserInitialize);
#endif
}
