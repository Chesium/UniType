#ifndef BI_MULTIPLY
#define BI_MULTIPLY

big_integer big_integer::operator*(const big_integer& b)const//二元乘(big_integer*big_integer)
{
	if(this->n.size()==1||b.n.size()==1)
	{
		if(*this==big_integer(0)||b==big_integer(0))
			return big_integer(0);
		if(*this==big_integer(1))
			return b;
		if(b==big_integer(1))
			return *this;
		if(*this==big_integer(-1))
			return -b;
		if(b==big_integer(-1))
			return -*this;
	}
	int i,j;
	big_integer r;
	std::deque<unsigned int>init(this->n.size()+b.n.size(),0);
	r.n=init;
	for(i=b.n.size()-1;i>=0;i--)
	{
		if(b.n[i]==0)
			continue;
		for(j=this->n.size()-1;j>=0;j--)
		{
			r.n[i+j+1]+=this->n[j]*b.n[i];
			//std::cout<<"  i="<<i<<"  |  j="<<j<<"  |  r.n["<<i+j<<"]="<<r.n[i+j+1]<<"\n";//调试用
		}
	}
	for(i=r.n.size()-1;i>0;i--)
	{
		r.n[i-1]+=r.n[i]/10;
		r.n[i]%=10;
		//std::cout<<"r.n["<<i+1<<"]+="<<r.n[i]/10<<"="<<r.n[i-1]<<"\n";//调试用
		//std::cout<<"r.n["<<i<<"]="<<r.n[i]<<"\n";//调试用
	}
	if(r.n.front()==0)
		r.n.pop_front();
	r.s=this->s^b.s;
	return r;
}


big_integer big_integer::operator*(const long long& b)const//二元乘(big_integer*v)
{
	big_integer b_big_integer(b);
	return *this*b_big_integer;
}


big_integer operator*(const long long& a,const big_integer& b)//二元乘(v*big_integer)
{
	big_integer a_big_integer(a);
	return a_big_integer*b;
}

#endif