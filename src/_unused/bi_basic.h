#pragma once
#include <iostream>
#include <deque>
#include "Bi_struct.h"
#define ll long long
#define ull unsigned long long

Bi::Bi(ll in)
{
	n18.clear();
	n18.push_back((ull)in);
	s = in > 0 ? 0 : 1;
}