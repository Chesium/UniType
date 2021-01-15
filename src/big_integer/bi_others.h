#ifndef BI_OTHERS
#define BI_OTHERS

#include <cmath>
#include <exception>
#include <stdexcept>

long long big_integer::v()//转换为long long
{
	if(this->n.size()>18)
	{
		throw std::range_error("range error");
		return 0;
	}
	int i,j;
	long long ans=0;
	for(i=this->n.size()-1,j=0;i>=0;i--,j++)
	{
		ans+=pow(10,j)*this->n[i];
	}
	ans=this->s?-ans:ans;
	return ans;
}


inline big_integer abs(const big_integer& a)
{
	big_integer r=a;
	r.s=false;
	return r;
}


big_integer big_integer::operator-()const//一元减(前缀)
{
	big_integer r=*this;
	r.s=!r.s;
	return r;
}


#endif