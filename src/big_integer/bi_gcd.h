#ifndef BI_GCD
#define BI_GCD

big_integer gcd(big_integer x,big_integer y)
{
	big_integer z=y;
	//std::cout<<"z="<<z<<"\n";//调试用
	while(x%y!=0)
	{
		z=x%y;
		x=y;
		y=z;
		//std::cout<<"  x="<<x<<"  |  y="<<y<<"  |  x%y="<<x%y<<"\n";//调试用
	}
	return z;
}

#endif