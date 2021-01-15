#pragma once
#include <iostream>
#include <cstdint>
#include <deque>
#include <string>
#include <stdexcept>
#include <cctype>

using namespace std;

class fraction
{
public:
	void* numerator;
	void* denominator;
	fraction(){}
	fraction operator+(const fraction& b);
	fraction operator-(const fraction& b);
	fraction operator*(const fraction& b);
	fraction operator/(const fraction& b);

	friend ostream& operator<<(ostream& out,fraction& a);
};

template<typename T>
fraction frac(T& a,T& b)
{
	fraction r;
	r.numerator=&a;
	r.denominator=&b;
	return r;
}

ostream& operator<<(ostream& out,fraction& a)
{
	cout<<"("<<*(a.numerator)<<","<<*(a.denominator)<<")";
	return out;
}