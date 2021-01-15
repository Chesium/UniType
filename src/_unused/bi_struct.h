#pragma once
#include <iostream>
#include <deque>
#include <string>
#include <stdexcept>
#include <cctype>
#include <cstdio>
//#include "Bi_basic.h"
#define ll long long
#define ull unsigned long long
using namespace std;

class Bi
{
public:
	bool s;
	deque<ull>n18;

	Bi();
	Bi(ll in);
	Bi(string in);

	friend ostream& operator<< (ostream& out, Bi& a);
	friend istream& operator>> (istream& in, Bi& a);

	Bi operator+(const Bi& b);
	Bi operator+(const ll& b);
	friend Bi operator+(const ll a, const Bi& b);
	void operator+=(const Bi& a);
	void operator+=(const ll& a);

	Bi operator-(const Bi& b);
	Bi operator-(const ll& b);
	friend Bi operator-(const ll a, const Bi& b);
	void operator-=(const Bi& a);
	void operator-=(const ll& a);

	Bi operator*(const Bi& b);
	Bi operator*(const ll& b);
	friend Bi operator*(const ll a, const Bi& b);
	void operator*=(const Bi& a);
	void operator*=(const ll& a);

	Bi operator/(const Bi& b);
	Bi operator/(const ll& b);
	friend Bi operator/(const ll a, const Bi& b);
	void operator/=(const Bi& a);
	void operator/=(const ll& a);

	Bi operator%(const Bi& b);
	Bi operator%(const ll& b);
	friend Bi operator%(const ll a, const Bi& b);
	void operator%=(const Bi& a);
	void operator%=(const ll& a);

	Bi operator++();
	Bi operator--();
	Bi operator++(int);
	Bi operator--(int);

	bool operator==(const Bi& b);
	bool operator==(const ll& b);
	bool operator!=(const Bi& b);
	bool operator!=(const ll& b);

	bool operator>(const Bi& b);
	bool operator>(const ll& b);
	bool operator>=(const Bi& b);
	bool operator>=(const ll& b);

	bool operator<(const Bi& b);
	bool operator<(const ll& b);
	bool operator<=(const Bi& b);
	bool operator<=(const ll& b);
};


Bi::Bi()
{
	n18.clear();
	s=0;
}


Bi::Bi(ll in)
{
	n18.clear();
	n18.push_back((ull)in);
	s = in > 0 ? 0 : 1;
}


Bi::Bi(string in)
{
	int i,p=0,stop=0;
	size_t len=in.length();//processPtr
	int n=0;
	ull tmp18=0,exp10;
	n18.clear();
	if(in[p]=='-')
	{
		s=1;
		stop=1;
	}
	else
		s=0;
	for(p=len-1;p>=stop;p--)
	{
		if(isdigit((int)in[p]))
		{
			exp10=1;
			for(i=0;i<n;i++)
				exp10*=10;
			tmp18+=((int)in[p]-48)*exp10;
			//printf("p=%d,n=%d,exp10=%lld,tmp18=%lld\n",p,n,exp10,tmp18);//D
			cout<<flush;
			n++;
			if(n>17)
			{
				n18.push_back(tmp18);
				tmp18=0;
				n=0;
			}
		}
		else
		{
			invalid_argument("Error: Your input contain non-digit characters!");
			return;
		}
	}
	if(tmp18>0)
	{
		n18.push_back(tmp18);
	}
}


ostream& operator<< (ostream& out, Bi& a)
{
	//cout<<"start: cout"<<endl;
	int i,r;
	bool notfront=0;
	ull t;
	if(a.n18.size()==0)
	{
		out<<'0';
		return out;
	}
	if(a.s)
		out<<'-';
	size_t len=a.n18.size();
	while(len--)
	{
		if(notfront)
		{
			t=a.n18[len];
			r=18;
			while(t>0)
			{
				t/=10;
				r--;
			}
			for(i=0;i<r;i++)
				out<<'0';
		}
		else
			notfront=1;
		out<<a.n18[len];
	}
	return out;
}


istream& operator>> (istream& in, Bi& a)
{
	string str_in;
	in>>str_in;
	a=Bi(str_in);
	return in;
}