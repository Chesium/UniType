#ifndef BI_INCREMENT_DECREMENT
#define BI_INCREMENT_DECREMENT


big_integer big_integer::operator++()//前递增
{
	*this=*this+1;
	return *this;
}


big_integer big_integer::operator--()//前递减
{
	*this=*this-1;
	return *this;
}


big_integer big_integer::operator++(int)//后递增
{
	*this=*this+1;
	return *this-1;
}


big_integer big_integer::operator--(int)//后递减
{
	*this=*this-1;
	return *this+1;
}


#endif