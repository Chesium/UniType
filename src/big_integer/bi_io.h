#ifndef BI_IO
#define BI_IO


big_integer::big_integer(long long in)//构造函数(整型输入)
{
	if(in<0)
	{
		s=true;
		in=-in;
	}
	do
	{
		n.push_front(in%10);
		in/=10;
	}while(in!=0);
}


big_integer::big_integer(const big_integer& in)
{
	s=in.s;
	n=in.n;
}


big_integer::big_integer(std::string in)//构造函数(字符串输入)
{
	n.clear();
	s=in[0]=='-';
	for(unsigned int i=s?1:0;i<in.length();i++)
	{
		if(std::isdigit(in[i]))
			n.push_back(in[i]-'0');
		else
		{
			throw std::invalid_argument("Error:Invalid Argument!");
			return;
		}
	}
}


std::ostream& operator<<(std::ostream& out,const big_integer in)//输出
{
	unsigned int i;
	if(in.s)
		std::cout<<"-";
	for(i=0;i<in.n.size();i++)
		std::cout<<in.n[i];
	return out;
}


std::string big_integer::out()
{
	std::stringstream ss;
	unsigned int i;
	if(this->s)
		ss<<"-";
	for(i=0;i<this->n.size();i++)
		ss<<this->n[i];
	return ss.str();
}


#endif