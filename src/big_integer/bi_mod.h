#ifndef BI_MOD
#define BI_MOD


big_integer big_integer::operator%(const big_integer& b)const
{
	return *this-b*(*this/b);
}


big_integer operator%(const long long& a,const big_integer& b)
{
	big_integer a_big_integer(a);
	return a_big_integer%b;
}


big_integer big_integer::operator%(const long long& b)const
{
	big_integer b_big_integer(b);
	return *this%b_big_integer;
}


#endif