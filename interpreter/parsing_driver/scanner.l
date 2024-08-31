%{
#include <string>
#include <filesystem>
#include "parsing_driver.h"
#include "grammar.tab.hh"
%}

%option noyywrap nounput noinput debug

id [a-zA-Z_][a-zA-Z_0-9]*
signed_number [0-9]+
unsigned_number [0-9]+u
simple_type signed|unsigned|Cell
ws [ \t]
call_token call({ws}+)
direction top|ntop|right|nright|down|ndown|left|nleft

%{
    #define YY_USER_ACTION drv.MoveLocationColumn(yyleng);
%}

%%
%{
    drv.LocationStep();
    const yy::location& loc = drv.GetLocation();
%}
{ws}+ drv.LocationStep();
\n drv.MoveLocationLine(); drv.LocationStep();
"-" return yy::parser::make_MINUS(loc);
"+" return yy::parser::make_PLUS(loc);
"*" return yy::parser::make_STAR(loc);
"/" return yy::parser::make_SLASH(loc);
"(" return yy::parser::make_LPAREN(loc);
")" return yy::parser::make_RPAREN(loc);
"<-" return yy::parser::make_ASSIGN(loc);
"%" return yy::parser::make_PERCENT(loc);
"<" return yy::parser::make_LESS(loc);
">" return yy::parser::make_GREATER(loc);
"=" return yy::parser::make_EQUAL(loc);
"," return yy::parser::make_COMMA(loc);
"#" return yy::parser::make_HASH(loc);
"print" return yy::parser::make_PRINT(loc);
"move_top" return yy::parser::make_MOVE_OPERATOR(MoveDirection::top, loc);
"move_bottom" return yy::parser::make_MOVE_OPERATOR(MoveDirection::bottom, loc);
"move_left" return yy::parser::make_MOVE_OPERATOR(MoveDirection::left, loc);
"move_right" return yy::parser::make_MOVE_OPERATOR(MoveDirection::right, loc);
"const" return yy::parser::make_CONST(loc);
"matrix" return yy::parser::make_MATRIX(loc);
"xray" return yy::parser::make_XRAY(loc);
{direction} return yy::parser::make_DIRECTION(CellLiteralNode::StringToWall(yytext), loc);
{simple_type} return yy::parser::make_SIMPLE_TYPE(std::string(yytext), loc);
"testrep" return yy::parser::make_TESTREP(loc);
"testonce" return yy::parser::make_TESTONCE(loc);
"func" return yy::parser::make_FUNC(loc);
{call_token} return yy::parser::make_CALL(loc);
{id} return yy::parser::make_IDENTIFIER(yytext, loc);
{signed_number} return yy::parser::make_SIGNED_NUM(std::stol(std::string(yytext)), loc);
{unsigned_number} return yy::parser::make_UNSIGNED_NUM(std::stol(std::string(yytext)), loc);
";" return yy::parser::make_SEMICOLON(loc);
. {
    drv.DetectError();
    throw yy::parser::syntax_error(loc, "invalid Symbol:" + std::string(yytext));
}
<<EOF>> return yy::parser::make_YYEOF(loc);
%%

bool ParsingDriver::ScanBegin() {
    yy_flex_debug = trace_scanning;
    auto path_to_file = std::filesystem::current_path();
    path_to_file /= file;
    std::cout << path_to_file.c_str() << '\n';
    if(std::filesystem::exists(path_to_file)){
        yyin = fopen(path_to_file.c_str(), "r");
        if(!yyin)
            return false;
        return true;
    }
    return false;
}

void ParsingDriver::ScanEnd(){
    fclose(yyin);
}