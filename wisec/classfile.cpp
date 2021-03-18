#include "classfile.h"

extern void yyrestart(FILE* source);
extern int yyparse();

namespace wisec {
	static ClassFile* class_file = nullptr;
	static Expression* object_class = nullptr;

	Expression* current_object_class() noexcept {
		return object_class;
	}

	void set_object_class(Expression* exp) noexcept {
		object_class = exp;
	}

	ClassPart* package_class_part(vector<const char*>* package_name) noexcept {
		auto res = new_class_part();
		res->type = res->PACKAGE;
		res->u.import.package_name = package_name;
		return res;
	}

	ClassPart* import_class_part(vector<const char*>* package_name, bool is_all) noexcept {
		auto res = new_class_part();
		res->type = res->IMPORT;
		res->u.import.package_name = package_name;
		res->u.import.is_all = is_all;
		return res;
	}

	ClassFile* current_class_file() noexcept {
		return class_file;
	}
	
	ClassFile::ClassFile(FILE* file) noexcept {
		set_file(file);
	}

	vector<Information>& ClassFile::get_information() noexcept {
		return information;
	}

	auto ClassFile::get_file() noexcept {
		return file;
	}

	void ClassFile::set_file(FILE* file) noexcept {
		this->file = file;
	}

	vector<ClassPart*>& ClassFile::get_parts() noexcept {
		return parts;
	}

	void ClassFile::append_part(ClassPart* part) noexcept {
		parts.emplace_back(part);
	}

	void ClassFile::compile() noexcept {
		class_file = this;
		yyrestart(class_file->get_file());
		yyparse();
	}
	
	void ClassFile::append_information(Information info) noexcept {
		information.emplace_back(info);
	}
	
	void ClassFile::append_error(string name, string message) noexcept {
		append_information(new_error(name, message));
	}

	void ClassFile::append_warning(string name, string message) noexcept {
		append_information(new_warning(name, message));
	}
	
}
