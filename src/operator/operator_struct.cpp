#pragma once
#include <string>
class opr
{
public:
	int id;
	string name;
	opr(int id_in,
		string name_in,
		uniT (*add_in)(const uniT& a,const uniT& b),
		uniT (*minus_in)(const uniT& a,const uniT& b),
		uniT (*multiply_in)(const uniT& a,const uniT& b),
		uniT (*divide_in)(const uniT& a,const uniT& b),
		string (*out_in)(const uniT& a))
	{
		id=id_in;
		name=name_in;
		add=add_in;
		minus=minus_in;
		multiply=multiply_in;
		divide=divide_in;
		out=out_in;
	}
	uniT (*add)(const uniT& a,const uniT& b);
	uniT (*minus)(const uniT& a,const uniT& b);
	uniT (*multiply)(const uniT& a,const uniT& b);
	uniT (*divide)(const uniT& a,const uniT& b);
	string (*out)(const uniT& a);
};