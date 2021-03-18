%{
/*
* Author: Chuanwise
* lastest update date: 2021 / 03 / 16
*/
#include "classfile.h"
using namespace wisec;

#include "codegarmmar.tab.h"
#include <stdio.h>
#include <string>

extern int yylineno;

extern wisec::ClassFile* wisec::current_class_file() noexcept;
extern wisec::Expression* wisec::current_object_class() noexcept;

int yywrap() {
    return 1;
}
void yyerror(const char* str) {
    current_class_file()->append_error("at " + std::to_string(yylineno), str);
}

extern int yylex();
#define YYDEBUG 1
#define YY_SKIP_YYWRAP
%}

%union {
    bool bool_ival;
    wchar_t char_ival;

    char byte_ival;
    short short_ival;
    int int_ival;
    long long long_ival;
    float float_ival;
    double double_ival;

    const char* string_ival;

    vector<Expression*>* expression_list;
    vector<const char*>* package_name;

    const char* identify;

    Expression* expression;
    Modifiers* modifiers;
    Modifiers::PermissionType permission_type;
    bool has_modifier;

    vector<ClassPart*>* class_parts;
    ClassPart* class_part;

    vector<MethodParameter*>* parameter_list;

    Statement* statement;
}

%token BOOL_IVAL CHAR_IVAL BYTE_IVAL SHORT_IVAL INT_IVAL LONG_IVAL FLOAT_IVAL DOUBLE_IVAL STRING_IVAL
%token VAR VOID BOOL CHAR BYTE SHORT INT LONG FLOAT DOUBLE

%type<bool_ival> BOOL_IVAL
%type<char_ival> CHAR_IVAL
%type<byte_ival> BYTE_IVAL
%type<short_ival> SHORT_IVAL
%type<int_ival> INT_IVAL
%type<long_ival> LONG_IVAL
%type<float_ival> FLOAT_IVAL
%type<double_ival> DOUBLE_IVAL
%type<string_ival> STRING_IVAL

%token NEW CLASS EXTENDS IMPLEMENTS PROPERTY
%token TRIPLE_DOT DOT COMMA SEMI

// () [] {}
%token LPARENT RPARENT LBRACKET RBRACKET LBRACE RBRACE

// + - % =>
%token PLUS MINUS MOD TRANS
// * /
%left MULTI DIV

// > < == >= <= !=
// > < instanceof == =
// TODO: finish all operators
%right BIGGER SMALLER INSTANCEOF EQUALS ASSIGN BIGGER_EQ SMALLER_EQ NOT_EQ

%token THROWS THROW

%token PACKAGE IMPORT

%token PUBLIC PROTECTED PRIVATE
%token STATIC CONST FINAL ABSTRACT MANUAL


%token IDENTIFY
%type<identify> IDENTIFY

%start program

%type<expression_list> expression_list type_expression_list

%type<package_name> package_name

%type<expression> ival expression basic_type type_expression call_expression construct_expression simple_expression calc_expression

%type<has_modifier> static_modifier const_modifier manual_modifier
%type<permission_type> permission_modifier
%type<modifiers> modifiers

%type<class_parts> class_member_list
%type<class_part> class_member method_declaration class_declaration program_part import_propart package_statement

%type<parameter_list> parameter_list

%type<statement> statement compound_statement statement_list

%%

program: program_part           { current_class_file()->append_part($1); }
       | program program_part   { current_class_file()->append_part($2); }
       ;

program_part: import_propart        { $$ = $1; }
            | package_statement     { $$ = $1; }
            | class_declaration     { $$ = $1; }
            // | state_declaration     { $$ = $1; $$->line = yylineno; }
            ;

package_name: IDENTIFY                      { $$ = new_identify_list($1); }
            | package_name DOT IDENTIFY     { $1->emplace_back($3); $$ = $1; }
            ;

import_propart: IMPORT MULTI SEMI                   { $$ = import_class_part(nullptr, true); }
              | IMPORT package_name SEMI            { $$ = import_class_part($2, false); }
              | IMPORT package_name DOT MULTI SEMI  { $$ = import_class_part($2, true); }
              ;

package_statement: PACKAGE package_name SEMI        { $$ = package_class_part($2); }
                 ;
            
ival: BOOL_IVAL     { $$ = bool_ival_expression($1); }
    | CHAR_IVAL     { $$ = char_ival_expression($1); }
    | BYTE_IVAL     { $$ = byte_ival_expression($1); }
    | SHORT_IVAL    { $$ = short_ival_expression($1); }
    | INT_IVAL      { $$ = int_ival_expression($1); }
    | LONG_IVAL     { $$ = long_ival_expression($1); }
    | FLOAT_IVAL    { $$ = float_ival_expression($1); }
    | DOUBLE_IVAL   { $$ = double_ival_expression($1); }
    | STRING_IVAL   { $$ = string_ival_expression($1); }
    ;

basic_type: BOOL    { $$ = bool_expression(); }
          | CHAR    { $$ = char_expression(); }
          | BYTE    { $$ = byte_expression(); }
          | SHORT   { $$ = short_expression(); }
          | INT     { $$ = int_expression(); }
          | LONG    { $$ = long_expression(); }
          | FLOAT   { $$ = float_expression(); }
          | DOUBLE  { $$ = double_expression(); }
          | VOID    { $$ = void_expression(); }
          ;

type_expression: IDENTIFY                                               { $$ = identify_expression($1); }
               | basic_type                                             { $$ = $1; }
               | type_expression TRIPLE_DOT                             { $$ = to_auto_length_type_expression($1); }
               | type_expression LBRACKET RBRACKET                      { $$ = to_array_type_expression($1); }
               | type_expression LBRACKET type_expression_list RBRACKET { $$ = to_template_type_expresion($1, $3); }
               | type_expression DOT IDENTIFY                           { $$ = dot_expression($1, $3); }
               ;

type_expression_list: type_expression                               { $$ = new_expression_list($1); }
                    | type_expression_list COMMA type_expression    { $1->emplace_back();  $$ = $1; }
                    ;

construct_expression: type_expression                                       { $$ = $1; }
                    | NEW type_expression LPARENT RPARENT                   { $$ = constructor_call_expression($2, new_expression_list()); }
                    | NEW type_expression LPARENT expression_list RPARENT   { $$ = constructor_call_expression($2, $4); }
                    ;

call_expression: construct_expression                               { $$ = $1; }
               | call_expression LPARENT expression_list RPARENT    { $$ = method_call_expression($1, $3); }
               | call_expression LPARENT RPARENT                    { $$ = method_call_expression($1, new_expression_list()); }
               | call_expression DOT IDENTIFY                       { $$ = dot_expression($1, $3); }   
               | call_expression DOT CLASS                          { $$ = dot_expression($1, "class"); }  
               ;

simple_expression: call_expression      { $$ = $1; }
                 | ival                 { $$ = $1; }
                 | LPARENT type_expression RPARENT LPARENT simple_expression RPARENT    { $$ = cast_expression($2, $5); }
                 ;

calc_expression: simple_expression                              { $$ = $1; }
               | calc_expression PLUS simple_expression         { $$ = plus_expression($1, $3); }
               | calc_expression MINUS simple_expression        { $$ = minus_expression($1, $3); }
               | calc_expression MULTI simple_expression        { $$ = multi_expression($1, $3); }
               | calc_expression DIV simple_expression          { $$ = div_expression($1, $3); }
               | calc_expression MOD simple_expression          { $$ = mod_expression($1, $3); }
               | calc_expression TRANS simple_expression        { $$ = trans_expression($1, $3); }
               | calc_expression BIGGER simple_expression       { $$ = bigger_expression($1, $3); }
               | calc_expression SMALLER simple_expression      { $$ = smaller_expression($1, $3); }
               | calc_expression BIGGER_EQ simple_expression    { $$ = biggereq_expression($1, $3); }
               | calc_expression SMALLER_EQ simple_expression   { $$ = smallereq_expression($1, $3); }
               | calc_expression EQUALS simple_expression       { $$ = equals_expression($1, $3); }
               | calc_expression NOT_EQ simple_expression       { $$ = noteq_expression($1, $3); }
               | calc_expression ASSIGN simple_expression       { $$ = assign_expression($1, $3); }
               ;

expression_list: expression                         { $$ = new_expression_list($1); }
               | expression_list COMMA expression   { $1->emplace_back($3); $$ = $1; }
               ;

expression: calc_expression     { $$  = $1; }
          ;

permission_modifier: PUBLIC         { $$ = Modifiers::PermissionType::PUBLIC; }
                   | PRIVATE        { $$ = Modifiers::PermissionType::PRIVATE; }
                   | PROTECTED      { $$ = Modifiers::PermissionType::PROTECTED; }
                   | /*default*/    { $$ = Modifiers::PermissionType::DEFAULT; }
                   ;

static_modifier: STATIC         { $$ = true; }
               | /*no static*/  { $$ = false; }
               ;

const_modifier: CONST           { $$ = true; }
              | /*no const*/    { $$ = false; }
              ;

manual_modifier: MANUAL         { $$ = false; }
               | /*auto call*/  { $$ = false; }
               ;

modifiers: permission_modifier static_modifier const_modifier   { $$ = new_modifiers(); $$->permission = $1; $$->is_static = $2;  $$->is_const = $3; }
         ;

class_declaration: modifiers CLASS IDENTIFY LBRACE RBRACE                       { $$ = new_class($1, $3, new_class_parts(), current_object_class(), new_expression_list()); }
                 | modifiers CLASS IDENTIFY LBRACE class_member_list RBRACE     { $$ = new_class($1, $3, $5, current_object_class(), new_expression_list()); }
                 ;

class_member_list: class_member                     { $$ = new_class_parts($1); }
                 | class_member class_member_list   { $2->emplace_back($1); $$ = $2; }
                 ;

class_member: method_declaration                    { $$ = $1; }
            ;
            //| permission_modifier static_modifier const_modifier type_expression IDENTIFY SEMI
            //| permission_modifier static_modifier const_modifier type_expression IDENTIFY ASSIGN expression SEMI

parameter_list: type_expression IDENTIFY                        { $$ = new_method_parameters(new_method_parameter($1, $2, nullptr)); }
              | parameter_list COMMA type_expression IDENTIFY   { $$->emplace_back(new_method_parameter($3, $4, nullptr)); $$ = $1; }
              ;

throws_exceptions: THROWS type_expression_list
                 | /*no exception*/
                 ;

method_declaration: modifiers type_expression IDENTIFY LPARENT RPARENT throws_exceptions compound_statement                 { $$ = new_method($1, $2, $3, new_method_parameters(), $7); }
                  | modifiers type_expression IDENTIFY LPARENT parameter_list RPARENT throws_exceptions compound_statement  { $$ = new_method($1, $2, $3, $5, $8); }
                  ;

compound_statement: LBRACE RBRACE                   { $$ = compound_statement(); }
                  | LBRACE statement_list RBRACE    { $$ = $2; }
                  ;

statement_list: statement                   { $$ = compound_statement($1); }
              | statement_list statement    { $$ = compound_statement($1, $2); }
              ;

statement: variable_declaration_statement SEMI
         | expression SEMI
         ;

variable_declaration_statement: CONST type_expression declarator_list SEMI
                              | type_expression declarator_list SEMI
                              ;

declarator: IDENTIFY
          | IDENTIFY ASSIGN expression
          ;

declarator_list: declarator
               | declarator_list COMMA declarator
               ;

