#include "grammaranalysiser.h"

namespace wisec {
	Modifiers* new_modifiers() noexcept {
		return checked_new<Modifiers>();
	}

	MethodParameter* new_method_parameter(Expression* type, const char* name, vector<Expression*>* states) noexcept {
		auto res = checked_new<MethodParameter>();
		res->type = type;
		res->name = name;
		res->states = states;
		return res;
	}

	vector<MethodParameter*>* new_method_parameters() noexcept {
		return checked_new<vector<MethodParameter*>>();
	}

	vector<MethodParameter*>* new_method_parameters(MethodParameter* first_element) noexcept {
		auto res = new_method_parameters();
		res->emplace_back(first_element);
		return res;
	}

	ClassPart* new_class_part() noexcept {
		return checked_new<ClassPart>();
	}

	vector<const char*>* new_identify_list(const char* first_element) noexcept {
		auto res = checked_new<vector<const char*>>();
		res->emplace_back(first_element);
		assert(first_element);
		return res;
	}

	vector<Expression*>* new_expression_list(Expression* first_exp) noexcept {
		auto res = new_expression_list();
		res->emplace_back(first_exp);
		return res;
	}

	vector<Expression*>* new_expression_list() noexcept {
		return checked_new<vector<Expression*>>();
	}

	vector<ClassPart*>* new_class_parts() noexcept {
		return checked_new<vector<ClassPart*>>();
	}

	vector<ClassPart*>* new_class_parts(ClassPart* first_element) noexcept {
		auto res = new_class_parts();
		res->emplace_back(first_element);
		return res;
	}

	ClassPart* new_method(Modifiers* modifiers, Expression* type, const char* name, vector<MethodParameter*>* parameters, Statement* body) noexcept {
		auto res = new_class_part();
		res->type = res->METHOD;
		res->modifiers = modifiers;
		res->u.method.name = name;
		res->u.method.type = type;
		res->u.method.parameters = parameters;
		res->u.method.body = body;
		return res;
	}

	ClassPart* new_class(Modifiers* modifiers, const char* name, vector<ClassPart*>* parts, Expression* super, vector<Expression*>* implements) noexcept {
		auto res = new_class_part();
		res->type = res->CLASS;
		res->modifiers = modifiers;
		res->u.class_def.name = name;
		res->u.class_def.parts = parts;
		res->u.class_def.super = super;
		res->u.class_def.implements = implements;
		return res;
	}

	Expression* to_array_type_expression(Expression* type_expression) noexcept {
		type_expression->u.type.is_array = true;
		return type_expression;
	}

	Expression* new_expression() noexcept {
		return checked_new<Expression>();
	}

	Expression* method_call_expression(Expression* name, vector<Expression*>* args) noexcept {
		auto res = new_expression();
		res->type = res->METHOD_CALL;
		res->u.method_call.method_name = name;
		res->u.method_call.args = args;
		return res;
	}

	Expression* constructor_call_expression(Expression* name, vector<Expression*>* args) noexcept {
		auto res = new_expression();
		res->type = res->METHOD_CALL;
		res->u.method_call.method_name = name;
		res->u.method_call.is_constructor = true;
		res->u.method_call.args = args;
		return res;
	}

	Expression* plus_expression(Expression* left, Expression* right) noexcept {
		auto res = new_expression();
		res->type = res->DOUBLE_OP;
		res->u.double_op.type = res->u.double_op.PLUS;
		res->u.double_op.left = left;
		res->u.double_op.right = right;
		return res;
	}

	Expression* minus_expression(Expression* left, Expression* right) noexcept {
		auto res = new_expression();
		res->type = res->DOUBLE_OP;
		res->u.double_op.type = res->u.double_op.MINUS;
		res->u.double_op.left = left;
		res->u.double_op.right = right;
		return res;
	}

	Expression* multi_expression(Expression* left, Expression* right) noexcept {
		auto res = new_expression();
		res->type = res->DOUBLE_OP;
		res->u.double_op.type = res->u.double_op.MULTI;
		res->u.double_op.left = left;
		res->u.double_op.right = right;
		return res;
	}

	Expression* div_expression(Expression* left, Expression* right) noexcept {
		auto res = new_expression();
		res->type = res->DOUBLE_OP;
		res->u.double_op.type = res->u.double_op.DIV;
		res->u.double_op.left = left;
		res->u.double_op.right = right;
		return res;
	}

	Expression* mod_expression(Expression* left, Expression* right) noexcept {
		auto res = new_expression();
		res->type = res->DOUBLE_OP;
		res->u.double_op.type = res->u.double_op.MOD;
		res->u.double_op.left = left;
		res->u.double_op.right = right;
		return res;
	}

	Expression* cast_expression(Expression* type, Expression* exp) noexcept {
		auto res = new_expression();
		res->type = res->DOUBLE_OP;
		res->u.double_op.type = res->u.double_op.CAST;
		res->u.double_op.left = type;
		res->u.double_op.right = exp;
		return res;
	}

	Expression* trans_expression(Expression* what, Expression* to) noexcept {
		auto res = new_expression();
		res->type = res->DOUBLE_OP;
		res->u.double_op.type = res->u.double_op.TRANS;
		res->u.double_op.left = what;
		res->u.double_op.right = to;
		return res;
	}

	Expression* bigger_expression(Expression* left, Expression* right) noexcept {
		auto res = new_expression();
		res->type = res->DOUBLE_OP;
		res->u.double_op.type = res->u.double_op.BIGGER;
		res->u.double_op.left = left;
		res->u.double_op.right = right;
		return res;
	}

	Expression* smaller_expression(Expression* left, Expression* right) noexcept {
		auto res = new_expression();
		res->type = res->DOUBLE_OP;
		res->u.double_op.type = res->u.double_op.SMALLER;
		res->u.double_op.left = left;
		res->u.double_op.right = right;
		return res;
	}

	Expression* biggereq_expression(Expression* left, Expression* right) noexcept {
		auto res = new_expression();
		res->type = res->DOUBLE_OP;
		res->u.double_op.type = res->u.double_op.BIGGER_EQ;
		res->u.double_op.left = left;
		res->u.double_op.right = right;
		return res;
	}

	Expression* smallereq_expression(Expression* left, Expression* right) noexcept {
		auto res = new_expression();
		res->type = res->DOUBLE_OP;
		res->u.double_op.type = res->u.double_op.SMALLER_EQ;
		res->u.double_op.left = left;
		res->u.double_op.right = right;
		return res;
	}

	Expression* equals_expression(Expression* left, Expression* right) noexcept {
		auto res = new_expression();
		res->type = res->DOUBLE_OP;
		res->u.double_op.type = res->u.double_op.EQUALS;
		res->u.double_op.left = left;
		res->u.double_op.right = right;
		return res;
	}

	Expression* noteq_expression(Expression* left, Expression* right) noexcept {
		auto res = new_expression();
		res->type = res->DOUBLE_OP;
		res->u.double_op.type = res->u.double_op.NOT_EQ;
		res->u.double_op.left = left;
		res->u.double_op.right = right;
		return res;
	}

	Expression* assign_expression(Expression* left, Expression* right) noexcept {
		auto res = new_expression();
		res->type = res->DOUBLE_OP;
		res->u.double_op.type = res->u.double_op.ASSIGN;
		res->u.double_op.left = left;
		res->u.double_op.right = right;
		return res;
	}

	Expression* void_expression() noexcept {
		auto res = new_expression();
		res->type = res->TYPE;
		res->u.type.is_basic_type = true;
		res->u.type.u.basic_type = res->u.type.u.VOID;
		return res;
	}

	Expression* bool_expression() noexcept {
		auto res = new_expression();
		res->type = res->TYPE;
		res->u.type.is_basic_type = true;
		res->u.type.u.basic_type = res->u.type.u.BOOL;
		return res;
	}

	Expression* char_expression() noexcept {
		auto res = new_expression();
		res->type = res->TYPE;
		res->u.type.is_basic_type = true;
		res->u.type.u.basic_type = res->u.type.u.CHAR;
		return res;
	}

	Expression* byte_expression() noexcept {
		auto res = new_expression();
		res->type = res->TYPE;
		res->u.type.is_basic_type = true;
		res->u.type.u.basic_type = res->u.type.u.BYTE;
		return res;
	}

	Expression* short_expression() noexcept {
		auto res = new_expression();
		res->type = res->TYPE;
		res->u.type.is_basic_type = true;
		res->u.type.u.basic_type = res->u.type.u.SHORT;
		return res;
	}

	Expression* int_expression() noexcept {
		auto res = new_expression();
		res->type = res->TYPE;
		res->u.type.is_basic_type = true;
		res->u.type.u.basic_type = res->u.type.u.INT;
		return res;
	}

	Expression* long_expression() noexcept {
		auto res = new_expression();
		res->type = res->TYPE;
		res->u.type.is_basic_type = true;
		res->u.type.u.basic_type = res->u.type.u.LONG;
		return res;
	}

	Expression* float_expression() noexcept {
		auto res = new_expression();
		res->type = res->TYPE;
		res->u.type.is_basic_type = true;
		res->u.type.u.basic_type = res->u.type.u.FLOAT;
		return res;
	}

	Expression* double_expression() noexcept {
		auto res = new_expression();
		res->type = res->TYPE;
		res->u.type.is_basic_type = true;
		res->u.type.u.basic_type = res->u.type.u.DOUBLE;
		return res;
	}

	Expression* bool_ival_expression(const bool val) noexcept {
		auto res = new_expression();
		res->type = res->IVAL;
		res->u.ival.type = res->u.ival.BOOL;
		res->u.ival.u.bool_ival = val;
		return res;
	}

	Expression* char_ival_expression(const wchar_t val) noexcept {
		auto res = new_expression();
		res->type = res->IVAL;
		res->u.ival.type = res->u.ival.CHAR;
		res->u.ival.u.char_ival = val;
		return res;
	}

	Expression* byte_ival_expression(const char val) noexcept {
		auto res = new_expression();
		res->type = res->IVAL;
		res->u.ival.type = res->u.ival.BYTE;
		res->u.ival.u.byte_ival = val;
		return res;
	}

	Expression* short_ival_expression(const short val) noexcept {
		auto res = new_expression();
		res->type = res->IVAL;
		res->u.ival.type = res->u.ival.SHORT;
		res->u.ival.u.short_ival = val;
		return res;
	}

	Expression* int_ival_expression(const int val) noexcept {
		auto res = new_expression();
		res->type = res->IVAL;
		res->u.ival.type = res->u.ival.INT;
		res->u.ival.u.int_ival = val;
		return res;
	}

	Expression* long_ival_expression(const long long val) noexcept {
		auto res = new_expression();
		res->type = res->IVAL;
		res->u.ival.type = res->u.ival.LONG;
		res->u.ival.u.long_ival = val;
		return res;
	}

	Expression* float_ival_expression(const float val) noexcept {
		auto res = new_expression();
		res->type = res->IVAL;
		res->u.ival.type = res->u.ival.FLOAT;
		res->u.ival.u.float_ival = val;
		return res;
	}

	Expression* double_ival_expression(const double val) noexcept {
		auto res = new_expression();
		res->type = res->IVAL;
		res->u.ival.type = res->u.ival.DOUBLE;
		res->u.ival.u.double_ival = val;
		return res;
	}

	Expression* string_ival_expression(const char* val) noexcept {
		auto res = new_expression();
		res->type = res->IVAL;
		res->u.ival.type = res->u.ival.STRING;
		res->u.ival.u.string_ival = val;
		return res;
	}

	Expression* identify_expression(const char* text) noexcept {
		auto res = new_expression();
		res->type = res->IDENTIFY;
		res->u.identify.identify = text;
		return res;
	}

	Expression* to_auto_length_type_expression(Expression* exp) noexcept {
		exp->u.type.auto_length = true;
		return exp;
	}

	Expression* to_template_type_expresion(Expression* exp, vector<Expression*>* exp_list) noexcept {
		exp->u.type.template_arguments = exp_list;
		return exp;
	}

	Expression* dot_expression(Expression* former, const char* suffix) noexcept {
		auto res = new_expression();
		res->type = res->DOT;
		res->u.dot.former = former;
		res->u.dot.suffix = suffix;
		return res;
	}

	Statement* new_statement() noexcept {
		return checked_new<Statement>();
	}

	Statement* expression_statement(Expression* expression) noexcept {
		auto res = new_statement();
		res->type = res->EXPRESSION;
		res->u.expression = expression;
		return res;
	}

	Statement* compound_statement(Statement* cur, Statement* next) noexcept {
		auto res = new_statement();
		res->type = res->COMPOUND;
		res->u.compound.cur = cur;
		res->u.compound.next = next;
		return res;
	}

}