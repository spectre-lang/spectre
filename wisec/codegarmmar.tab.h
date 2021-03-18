
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     BOOL_IVAL = 258,
     CHAR_IVAL = 259,
     BYTE_IVAL = 260,
     SHORT_IVAL = 261,
     INT_IVAL = 262,
     LONG_IVAL = 263,
     FLOAT_IVAL = 264,
     DOUBLE_IVAL = 265,
     STRING_IVAL = 266,
     VAR = 267,
     VOID = 268,
     BOOL = 269,
     CHAR = 270,
     BYTE = 271,
     SHORT = 272,
     INT = 273,
     LONG = 274,
     FLOAT = 275,
     DOUBLE = 276,
     NEW = 277,
     CLASS = 278,
     EXTENDS = 279,
     IMPLEMENTS = 280,
     PROPERTY = 281,
     TRIPLE_DOT = 282,
     DOT = 283,
     COMMA = 284,
     SEMI = 285,
     LPARENT = 286,
     RPARENT = 287,
     LBRACKET = 288,
     RBRACKET = 289,
     LBRACE = 290,
     RBRACE = 291,
     PLUS = 292,
     MINUS = 293,
     MOD = 294,
     TRANS = 295,
     DIV = 296,
     MULTI = 297,
     NOT_EQ = 298,
     SMALLER_EQ = 299,
     BIGGER_EQ = 300,
     ASSIGN = 301,
     EQUALS = 302,
     INSTANCEOF = 303,
     SMALLER = 304,
     BIGGER = 305,
     THROWS = 306,
     THROW = 307,
     PACKAGE = 308,
     IMPORT = 309,
     PUBLIC = 310,
     PROTECTED = 311,
     PRIVATE = 312,
     STATIC = 313,
     CONST = 314,
     FINAL = 315,
     ABSTRACT = 316,
     MANUAL = 317,
     IDENTIFY = 318
   };
#endif

#include "classfile.h"
using namespace wisec;

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 29 "codegarmmar.y"

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

/* Line 1676 of yacc.c  */
#line 142 "codegarmmar.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


