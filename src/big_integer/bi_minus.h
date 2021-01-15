#ifndef BI_MINUS
#define BI_MINUS

big_integer big_integer::operator-(const big_integer& b)const//二元减(big_integer-big_integer)
{
	if(*this==b)
		return big_integer(0);
	if(*this<b)
		return -(b-*this);
	if(this->s&&!b.s)//负正
		return -(-*this+b);
	if(!this->s&&b.s)//正负
		return *this+(-b);
	int i,j,t,c=0;
	big_integer r;
	r.n.clear();
	for(i=this->n.size()-1,j=b.n.size()-1;i>=0||j>=0;i--,j--)
	{
		t=(i<0?0:this->n[i])-(j<0?0:b.n[j])-c;
		//std::cout<<"c="<<c<<"|t="<<t<<"\n";//调试用
		if(t<0)
		{
			c=1;
			t+=10;
		}
		else
			c=0;
		r.n.push_front(t);
	}
	while(r.n.front()==0)
		r.n.pop_front();
	if(c==1)
		r.s=true;
	return r;
}


big_integer big_integer::operator-(const long long& b)const//二元减(big_integer-v)
{
	big_integer b_big_integer(b);
	return *this-b_big_integer;
}


big_integer operator-(const long long& a,const big_integer& b)//二元减(v-big_integer)
{
	big_integer a_big_integer(a);
	return a_big_integer-b;
}

#endif