#pragma once
#include "macros.h"
#include <vector>
#include "util.h"
#include <string>
using std::vector;
using std::string;

namespace wisec {
	class Modifiers {
	public:
		enum PermissionType {
			PUBLIC,
			PRIVATE,
			PROTECTED,
			DEFAULT,
		} permission;
		bool is_static = false;
		bool is_manual = false;
		bool is_const = false;
	};

	class Expression {
	public:
		static enum Type {
			IDENTIFY,
			TYPE,
			DOT,
			IVAL,
			SINGLE_OP,
			DOUBLE_OP,
			METHOD_CALL,
		};
		int line;
		Type type;
		union U {
			struct {
				Expression* what = nullptr;
				Expression* to = nullptr;
			} trans;
			struct {
				bool is_basic_type = true;
				union {
					enum {
						BOOL,
						BYTE,
						CHAR,
						SHORT,
						INT,
						LONG,
						FLOAT,
						DOUBLE,
						VOID,
					} basic_type;
					Expression* custom_type = nullptr;
				} u;
				bool is_array = false;
				vector<Expression*>* template_arguments = nullptr;
				bool auto_length = false;
			} type;
			struct {
				const char* identify;
			} identify;
			struct {
				Expression* former = nullptr;
				const char* suffix;
			} dot;
			struct {
				enum {
					BOOL,
					BYTE,
					CHAR,
					SHORT,
					INT,
					LONG,
					FLOAT,
					DOUBLE,
					STRING,
				} type;
				union {
					bool bool_ival;
					wchar_t char_ival;

					char byte_ival;
					short short_ival;
					int int_ival;
					long long long_ival;
					float float_ival;
					double double_ival;

					const char* string_ival;
				} u;
			} ival;
			struct {
				enum {
					PLUS,
					MINUS,
					MULTI,
					DIV,
					MOD,
					BIGGER,
					SMALLER,
					BIGGER_EQ,
					SMALLER_EQ,
					NOT_EQ,
					EQUALS,
					TRANS,
					CAST,
					ASSIGN,
				} type;
				Expression* left, * right;
			} double_op;
			struct {
				enum {
					//CAST,
				} type;
				Expression* exp;
			} single_op;
			struct {
				bool is_constructor = false;
				Expression* method_name;
				vector<Expression*>* args;
			} method_call;
			U() noexcept {
			}
			~U() noexcept {
			}
		} u;
	};

	class ClassDeclaration {
	public:
		Modifiers* modifiers;
		const char* name;

	};

	class MethodParameter {
	public:
		Expression* type;
		vector<Expression*>* states;
		const char* name;
	};

	class Statement {
	public:
		static enum Type {
			ASSIGN,
			DECLARATION,
			EXPRESSION,
			COMPOUND,
		};

		int line;
		Type type;
		union U {
			Expression* expression = nullptr;
			struct {
				Statement* cur, * next = nullptr;
			} compound;

			U() noexcept { }
			~U() noexcept { }
		} u;
	};

	class ClassPart {
	public:
		Modifiers* modifiers;
		enum Type {
			METHOD,
			CLASS,
			MEMBER,
			IMPORT,
			PACKAGE,
		} type;
		union U {
			struct {
				const char* name;
				vector<MethodParameter*>* parameters;
				Statement* body;	// if body == nullptr, the method is abstract
				Expression* type;
			} method;
			struct {
				const char* name;
				Expression* super;
				vector<Expression*>* implements;
				vector<ClassPart*>* parts;
			} class_def;
			struct {
				vector<const char*>* package_name = nullptr;
				bool is_all = false;
			} import;
			struct {
				vector<const char*>* package_name;
			} package;
			U() noexcept {
			}
			~U() noexcept {
			}
		} u;
	};

	Modifiers* new_modifiers() noexcept;

	MethodParameter* new_method_parameter(Expression* type, const char* name, vector<Expression*>* states) noexcept;

	vector<MethodParameter*>* new_method_parameters() noexcept;

	vector<MethodParameter*>* new_method_parameters(MethodParameter* first_element) noexcept;


	ClassPart* new_class_part() noexcept;

	vector<const char*>* new_identify_list(const char* first_element) noexcept;

	vector<Expression*>* new_expression_list(Expression* first_exp) noexcept;

	vector<Expression*>* new_expression_list() noexcept;

	vector<ClassPart*>* new_class_parts() noexcept;

	vector<ClassPart*>* new_class_parts(ClassPart* first_element) noexcept;

	ClassPart* new_method(Modifiers* modifiers, Expression* type, const char* name, vector<MethodParameter*>* parameters, Statement* body) noexcept;

	ClassPart* new_class(Modifiers* modifiers, const char* name, vector<ClassPart*>* parts, Expression* super, vector<Expression*>* implements) noexcept;

	Expression* to_array_type_expression(Expression* type_expression) noexcept;

	Expression* new_expression() noexcept;

	Expression* method_call_expression(Expression* name, vector<Expression*>* args) noexcept;

	Expression* constructor_call_expression(Expression* name, vector<Expression*>* args) noexcept;

	Expression* plus_expression(Expression* left, Expression* right) noexcept;

	Expression* minus_expression(Expression* left, Expression* right) noexcept;

	Expression* multi_expression(Expression* left, Expression* right) noexcept;

	Expression* div_expression(Expression* left, Expression* right) noexcept;

	Expression* mod_expression(Expression* left, Expression* right) noexcept;

	Expression* cast_expression(Expression* type, Expression* exp) noexcept;

	Expression* trans_expression(Expression* what, Expression* to) noexcept;

	Expression* bigger_expression(Expression* left, Expression* right) noexcept;

	Expression* smaller_expression(Expression* left, Expression* right) noexcept;

	Expression* biggereq_expression(Expression* left, Expression* right) noexcept;

	Expression* smallereq_expression(Expression* left, Expression* right) noexcept;

	Expression* equals_expression(Expression* left, Expression* right) noexcept;

	Expression* noteq_expression(Expression* left, Expression* right) noexcept;

	Expression* assign_expression(Expression* left, Expression* right) noexcept;

	Expression* void_expression() noexcept;

	Expression* bool_expression() noexcept;

	Expression* char_expression() noexcept;

	Expression* byte_expression() noexcept;

	Expression* short_expression() noexcept;

	Expression* int_expression() noexcept;

	Expression* long_expression() noexcept;

	Expression* float_expression() noexcept;

	Expression* double_expression() noexcept;

	/*
	bool bool_ival;
    wchar_t char_ival;

    char byte_ival;
    short short_ival;
    int int_ival;
    long long long_ival;
    float float_ival;
    double double_ival;

	const char* string_ival;
	*/
	Expression* bool_ival_expression(const bool val) noexcept;

	Expression* char_ival_expression(const wchar_t val) noexcept;

	Expression* byte_ival_expression(const char val) noexcept;

	Expression* short_ival_expression(const short val) noexcept;

	Expression* int_ival_expression(const int val) noexcept;

	Expression* long_ival_expression(const long long val) noexcept;

	Expression* float_ival_expression(const float val) noexcept;

	Expression* double_ival_expression(const double val) noexcept;

	Expression* string_ival_expression(const char* val) noexcept;


	Expression* identify_expression(const char* text) noexcept;

	Expression* to_auto_length_type_expression(Expression* exp) noexcept;

	Expression* to_template_type_expresion(Expression* exp, vector<Expression*>* exp_list) noexcept;

	Expression* dot_expression(Expression* former, const char* suffix) noexcept;

	Statement* new_statement() noexcept;

	Statement* expression_statement(Expression* expression) noexcept;

	Statement* compound_statement(Statement* cur = nullptr, Statement* next = nullptr) noexcept;
}