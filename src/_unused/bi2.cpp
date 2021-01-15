#pragma once
#include <iostream>
#include <cstdint>
#include <deque>
#include <string>
#include <stdexcept>
#include <cctype>

using namespace std;

class UBI2
{
public:
	deque<uint64_t>n;

	string output();

	UBI2();
	UBI2(uint64_t in);
	UBI10 to_UBI10();
	//UBI2(string in);
};


string UBI2::output()
{
	UBI10 t=this->to_UBI10();
	return t.output();
}


UBI2::UBI2()
{
	n.push_back(0);
}


UBI2::UBI2(uint64_t in)
{
	n.push_back(in);
}


UBI10 UBI2::to_UBI10()
{
	int i,m=this->n.size();
	UBI10 r,t(1),i64(UINT64_MAX),ct,mt;
	for(i=0;i<m;i++)
	{
		ct=UBI10(this->n[i]);
		mt=UBI10_mul(ct,t);
		r=UBI10_add(r,mt);
		t=UBI10_mul(t,i64);
	}
	return r;
}

UBI10 EXP2_32_n(int n)
{
	UBI10 r(1),i64(UINT64_MAX);
	n--;
	while(n--)
		r=UBI10_mul(r,i64);
	return r;
}