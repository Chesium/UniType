#pragma once

#include <string>
#include <iostream>
#include <deque>

#include "unitype_struct.cpp"

#include "unitype_constructors.cpp"

uniT bi_add(const Bi& a,const uniT& b);
uniT bi_minus(const Bi& a,const uniT& b);
uniT bi_multiply(const Bi& a,const uniT& b);
uniT bi_devide(const Bi& a,const uniT& b);
#include "bi_addon.cpp"

#include "unitype_operators.cpp"

ostream& operator<<(ostream& out,uniT a);
#include "unitype_output.cpp"