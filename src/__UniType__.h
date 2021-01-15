#pragma once

#include "big_integer/__BIG_INTEGER__.h"
using namespace std;

typedef big_integer Bi;

void unierror(string n);
#include "unitype/unierror.cpp"

class uniT;
class opr;
#include "operator/operator_struct.cpp"

#include "unitype/unitype.h"

#include "fraction/fraction.h"