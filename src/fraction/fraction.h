#pragma once

#include <sstream>

uniT frac_add(const uniT& a,const uniT& b);
uniT frac_minus(const uniT& a,const uniT& b);
uniT frac_multiply(const uniT& a,const uniT& b);
uniT frac_devide(const uniT& a,const uniT& b);
string frac_out(const uniT& a);

#include "frac_struct.cpp"

#include "frac_operators.cpp"

#include "frac_io.cpp"

template<typename T1,typename T2>
uniT frac(T1 a,T2 b);
#include "frac_constructors.cpp"