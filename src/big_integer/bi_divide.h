#ifndef BI_DIVIDE
#define BI_DIVIDE

big_integer big_integer::operator/(const big_integer& b)const//二元整除(big_integer/big_integer)
{
	big_integer r(0);
	big_integer abs_b=abs(b);
	big_integer compare=abs_b;
	while(compare<=abs(*this))
	{
		compare+=abs_b;
		r++;
	}
	r.s=this->s^b.s;
	return r;
}


big_integer big_integer::operator/(const long long& b)const//二元整除(big_integer/v)
{
	big_integer b_big_integer(b);
	return *this/b_big_integer;
}


big_integer operator/(const long long& a,const big_integer& b)//二元乘(v/big_integer)
{
	big_integer a_big_integer(a);
	return a_big_integer/b;
}

#endif