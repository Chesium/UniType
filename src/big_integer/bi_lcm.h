#ifndef BI_LCM
#define BI_LCM

big_integer lcm(const big_integer a,const big_integer b)
{
    if(a * b == 0)
        return 0;
    return (a*b)/gcd(a,b);//使用公式
}

#endif