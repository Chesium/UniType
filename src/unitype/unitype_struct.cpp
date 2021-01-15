#pragma once

class uniT
{
public:
	
	bool isBi;
	deque<uniT*>para;
	Bi bi;
	const opr* op;

	uniT();
	uniT(long long n);
	uniT(const Bi& n);
	uniT(const opr& op_in);
	uniT(const uniT& n);

	uniT operator+(const uniT& b);
	uniT operator-(const uniT& b);
	uniT operator*(const uniT& b);
	uniT operator/(const uniT& b);

	string out();
	friend ostream& operator<<(ostream& out,uniT a);
};