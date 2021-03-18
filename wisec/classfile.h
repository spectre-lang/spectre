#pragma once
#include "util.h"
#include "grammaranalysiser.h"
#include "information.h"
#include <vector>
using std::vector;

namespace wisec {
	Expression* current_object_class() noexcept;
	
	void set_object_class(Expression* exp) noexcept;

	ClassPart* package_class_part(vector<const char*>* package_name) noexcept;

	ClassPart* import_class_part(vector<const char*>* package_name, bool is_all = false) noexcept;

	class ClassFile {
	public:
		ClassFile(FILE* file) noexcept;

		vector<Information>& get_information() noexcept;

		auto get_file() noexcept;

		void set_file(FILE* file) noexcept;

		vector<ClassPart*>& get_parts() noexcept;

		void append_part(ClassPart* part) noexcept;

		void compile() noexcept;

		void append_information(Information info) noexcept;

		void append_error(string name, string message) noexcept;

		void append_warning(string name, string message) noexcept;
	private:
		FILE* file;

		vector<ClassPart*> parts;

		vector<Information> information;
	};

	ClassFile* current_class_file() noexcept;
}
