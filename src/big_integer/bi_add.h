#ifndef BI_ADD
#define BI_ADD

big_integer big_integer::operator+(const big_integer& b)const//二元加(big_integer+big_integer)
{
	if(this->s&&!b.s)//负正
		return b-(-*this);
	if(!this->s&&b.s)//正负
		return *this-(-b);
	int i,j,t,c=0;
	big_integer r;
	r.n.clear();
	for(i=this->n.size()-1,j=b.n.size()-1;i>=0||j>=0;i--,j--)
	{
		t=(i<0?0:this->n[i])+(j<0?0:b.n[j])+c;
		//std::cout<<"c="<<c<<"|t="<<t<<"\n";//调试用
		c=t/10;
		t%=10;
		r.n.push_front(t);
	}
	if(this->s&&b.s)
		r.s=true;
	if(c==1)
		r.n.push_front(1);
	return r;
}


big_integer big_integer::operator+(const long long& b)const//二元加(big_integer+v)
{
	big_integer b_big_integer(b);
	return *this+b_big_integer;
}


big_integer operator+(const long long& a,const big_integer& b)//二元加(v+big_integer)
{
	big_integer a_big_integer(a);
	return a_big_integer+b;
}

#endif