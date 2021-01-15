#ifndef BI_ASSIGNMENT
#define BI_ASSIGNMENT


void big_integer::operator+=(const big_integer& a)
{
	*this=*this+a;
}


void big_integer::operator-=(const big_integer& a)
{
	*this=*this-a;
}


void big_integer::operator*=(const big_integer& a)
{
	*this=*this*a;
}


void big_integer::operator/=(const big_integer& a)
{
	*this=*this/a;
}


void big_integer::operator%=(const big_integer& a)
{
	*this=*this%a;
}


void big_integer::operator%=(const long long& a)
{
	big_integer a_big_integer(a);
	*this%=a_big_integer;
}


void big_integer::operator=(const long long& a)
{
	big_integer r(a);
	*this=r;
}


void big_integer::operator+=(const long long& a)
{
	big_integer a_big_integer(a);
	*this+=a_big_integer;
}


void big_integer::operator-=(const long long& a)
{
	big_integer a_big_integer(a);
	*this-=a_big_integer;
}


void big_integer::operator*=(const long long& a)
{
	big_integer a_big_integer(a);
	*this*=a_big_integer;
}


void big_integer::operator/=(const long long& a)
{
	big_integer a_big_integer(a);
	*this/=a_big_integer;
}


#endif