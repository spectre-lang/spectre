#include "compiler.h"
#include "codegarmmar.tab.h"
#include "classfile.h"

namespace wisec {
	Compiler* p_compiler;

	Compiler::Compiler() noexcept {

	}

	void Compiler::compile_class_files() noexcept {
		for (auto& class_file : class_files) {
			class_file.compile();
		}
	}
	
	void Compiler::append_file(FILE* file) noexcept {
		class_files.emplace_back(ClassFile(file));
	}
	
	vector<ClassFile>& Compiler::get_class_files() noexcept {
		return class_files;
	}
}