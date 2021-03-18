#pragma once
#include <iostream>
#include <windows.h>

std::ostream& blue(std::ostream& s);
std::ostream& red(std::ostream& s);
std::ostream& green(std::ostream& s);
std::ostream& yellow(std::ostream& s);
std::ostream& white(std::ostream& s);

struct color {
    color(WORD attribute) :m_color(attribute) {
    };
    WORD m_color;
};
template <class _Elem, class _Traits>
std::basic_ostream<_Elem, _Traits>&
operator<<(std::basic_ostream<_Elem, _Traits>& i, color& c);