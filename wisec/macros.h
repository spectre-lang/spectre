#pragma once

#define DEF_ALIAS(what, name)\
what name##_;                \
using name = name##_*; 

#define CLASS_ALIAS(name)	DEF_ALIAS(class, name)
#define VECTOR_ALIAS(type)	using type##List_ = vector<type##_>; using type##List = type##List_*;