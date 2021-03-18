#pragma once
#include <cstdio>
#include <vector>
#include "classfile.h"
using std::vector;

namespace wisec {
	class Compiler {
	public:
		Compiler() noexcept;

		void compile_class_files() noexcept;

		void append_file(FILE* file) noexcept;

		vector<ClassFile>& get_class_files() noexcept;
	private:
		vector<ClassFile> class_files;
	};
}