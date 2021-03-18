%option yylineno

%{
/*
* Author: Chuanwise
* lastest update date: 2021 / 03 / 16
*/    
#include "codegarmmar.tab.h"
#define fileno _fileno
#define isatty _isatty

#define YY_SKIP_YYWRAP
#define unput(c) yyunput( c, yytext_ptr )

extern int yywrap();
extern int yyinput();
extern void yyunput(int c, char* buf_ptr);

void eat_long_comment() {
	char c, c1;

    while (true) {
        while ((c = yyinput()) != '*' && c != 0);
        if ((c1 = yyinput()) != '/' && c != 0) {
            unput(c1);
        }
        else {
            break;
        }
    }
}

void eat_short_comment() {
    char c;
    while ((c = yyinput()) != '\n' && c != 0);
}

%}

identify        [A-Za-z_][0-9A-Za-z_]*

bool_ival       true|false
char_ival       '.+'

byte_ival       [+-]?(((0[XxBb]?)?\d+)|(\d+[eE]\d+))[Bb]
int_ival        [+-]?(((0[XxBb]?)?\d+)|(\d+[eE]\d+))
short_ival      [+-]?(((0[XxBb]?)?\d+)|(\d+[eE]\d+))[Ss]
long_ival       [+-]?(((0[XxBb]?)?\d+)|(\d+[eE]\d+))[Ll]
float_ival      [+-]?\d+(\.\d+)?(\d+(\.\d+)?)?[Ff]
double_ival     [+-]?\d+(\.\d+)?(\d+(\.\d+)?)?

string_ival     \"[^\n]*\"

single_comment_head     \/\/
multi_comment_head      \/\*
space                   \s+

%%
{string_ival}       { yylval.string_ival = yytext; return STRING_IVAL;}

{space}                  { }
{single_comment_head}    { printf("get a comment: %s\n\n", yytext); eat_short_comment(); }
{multi_comment_head}     { printf("get a multiple comment: %s\n\n", yytext); eat_long_comment(); }

"package"       { return PACKAGE; }
"import"        { return IMPORT; }

"var"           { return VAR; }
"void"          { return VOID; }
"bool"          { return BOOL; }
"char"          { return CHAR; }
"byte"          { return BYTE; }
"short"         { return SHORT; }
"int"           { return INT; }
"long"          { return LONG; }
"float"         { return FLOAT; }
"double"        { return DOUBLE; }

"public"        { return PUBLIC; }
"private"       { return PRIVATE; }
"protected"     { return PROTECTED; }

"static"        { return STATIC; }
"const"         { return CONST; }
"abstract"      { return ABSTRACT; }

"final"         { return FINAL; }
"manual"        { return MANUAL; }

"new"           { return NEW; }

"class"         { return CLASS; }
"property"      { return PROPERTY; }

"throws"        { return THROWS; }
"throw"         { return THROW; }

"extends"       { return EXTENDS; }
"implements"    { return IMPLEMENTS; }
"instanceof"    { return INSTANCEOF; }

"..."           { return TRIPLE_DOT; }
"."             { return DOT; }
","             { return COMMA; }
";"             { return SEMI; }

"("             { return LPARENT; }
")"             { return RPARENT; }
"["             { return LBRACKET; }
"]"             { return RBRACKET; }
"{"             { return LBRACE; }
"}"             { return RBRACE; }

"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return MULTI; }
"/"             { return DIV; }
"%"             { return MOD; }

"="             { return ASSIGN; }
">"             { return BIGGER; }
"<"             { return SMALLER; }
">="            { return BIGGER_EQ; }
"<="            { return SMALLER_EQ; }
"!="            { return NOT_EQ; }
"=="            { return EQUALS; }
"=>"            { return TRANS; }

{bool_ival}     { yylval.bool_ival = strcmp(yytext, "true") == 0; return BOOL_IVAL; }

{byte_ival}     { sscanf_s(yytext, "%d", &yylval); return BYTE_IVAL; }


{identify}      { yylval.identify = yytext; return IDENTIFY; }


