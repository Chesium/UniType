#pragma once
#include <iostream>
#include <cstdint>
#include <deque>
#include <string>
#include <stdexcept>
#include <cctype>

using namespace std;

class UBI10
{
public:
	deque<uint8_t>n;
	string output();
	UBI10();
	UBI10(uint64_t in);
	friend UBI10 UBI10_add(UBI10& a,UBI10& b);
	friend UBI10 UBI10_mul(UBI10& a,UBI10& b);
};


string UBI10::output()
{
	int i=this->n.size()-1;
	string out;
	for(;i>=0;i--)
		out.append(1,this->n[i]+'0');
	return out;
}


UBI10::UBI10()
{
	n.clear();
	n.push_back(0);
}


UBI10::UBI10(uint64_t in)
{
	n.clear();
	if(in==0)
	{
		n.push_back(0);
		return;
	}
	while(in>0)
	{
		n.push_back(in%10);
		in/=10;
	}
}


UBI10 UBI10_add(UBI10& a,UBI10& b)
{
	int i,j,t,c=0,la=a.n.size(),lb=b.n.size();
	UBI10 r;
	r.n.clear();
	for(i=0,j=0;i<la||j<lb;i++,j++)
	{
		t=(i<la?a.n[i]:0)+(j<lb?b.n[j]:0)+c;
		c=t/10;
		t%=10;
		r.n.push_back(t);
	}
	if(c)
		r.n.push_back(1);
	return r;
}

UBI10 UBI10_mul(UBI10& a,UBI10& b)
{
	int i,j,c=0,la=a.n.size(),lb=b.n.size();
	UBI10 r;
	r.n.clear();
	for(i=0;i<la+lb;i++)
		r.n.push_back(0);
	for(i=0;i<la;i++)
		for(j=0;j<lb;j++)
			r.n[i+j]+=a.n[i]*b.n[j];
	for(i=0;i<la+lb;i++)
	{
		r.n[i]+=c;
		c=r.n[i]/10;
		r.n[i]%=10;
	}
	if(r.n.back()==0)
		r.n.pop_back();
	return r;
}