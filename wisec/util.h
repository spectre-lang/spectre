#pragma once
#include <assert.h>
#include <new>
#include "macros.h"
#include <iostream>
using std::bad_alloc;

template<typename T>
T* checked_new() noexcept {
	try {
		//std::cout << "new " << typeid(T).name() << std::endl;
		T* result = new T;
		return result;
	}
	catch (bad_alloc exc) {
		std::cerr << "Out of memory!" << std::endl;
		return nullptr;
	}
}

