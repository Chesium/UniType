#ifndef BI_COMPARE
#define BI_COMPARE

bool big_integer::operator==(const big_integer& b)const//等于
{
	unsigned int i;
	if(this->n.size()!=b.n.size()||this->s^b.s)
		return false;
	for(i=0;i<b.n.size();i++)
	{
		if(this->n[i]!=b.n[i])
			return false;
	}
	return true;
}


bool big_integer::operator>(const big_integer& b)const//大于
{
	unsigned int i;
	if(!this->s&&b.s)
		return true;
	if(this->s&&!b.s)
		return false;
	if(this->n.size()>b.n.size())
		return true;
	if(this->n.size()<b.n.size())
		return false;
	for(i=0;i<b.n.size();i++)
	{
		if(this->n[i]>b.n[i])
			return true;
		if(this->n[i]<b.n[i])
			return false;
	}
	return false;
}


bool big_integer::operator<(const big_integer& b)const//小于
{
	unsigned int i;
	if(this->s&&!b.s)
		return true;
	if(!this->s&&b.s)
		return false;
	if(this->n.size()<b.n.size())
		return true;
	if(this->n.size()>b.n.size())
		return false;
	for(i=0;i<b.n.size();i++)
	{
		if(this->n[i]<b.n[i])
			return true;
		if(this->n[i]>b.n[i])
			return false;
	}
	return false;
}


bool big_integer::operator<=(const big_integer& b)const//小于等于
{
	return !(*this>b);
}


bool big_integer::operator>=(const big_integer& b)const//大于等于
{
	return !(*this<b);
}


bool big_integer::operator>(const long long& b)const
{
	big_integer big_integer_b(b);
	return *this>big_integer_b;
}


bool big_integer::operator<(const long long& b)const
{
	big_integer big_integer_b(b);
	return *this<big_integer_b;
}


bool big_integer::operator>=(const long long& b)const
{
	big_integer big_integer_b(b);
	return *this>=big_integer_b;
}


bool big_integer::operator<=(const long long& b)const
{
	big_integer big_integer_b(b);
	return *this<=big_integer_b;
}


bool big_integer::operator!=(const big_integer& b)const
{
	return !(*this==b);
}


bool big_integer::operator!=(const long long& b)const
{
	big_integer big_integer_b(b);
	return !(*this==big_integer_b);
}


bool big_integer::operator==(const long long& b)const
{
	big_integer big_integer_b(b);
	return *this==big_integer_b;
}
#endif