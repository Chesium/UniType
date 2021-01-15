#ifndef BI_STRUCT
#define BI_STRUCT

#include <deque>
#include <string>
#include <iostream>
#include <sstream>

class big_integer
{
public:
	//属性部分
	std::deque<unsigned int>n;
	bool s=false;//符号

	//方法声明部分
	/*
	big_integer()
	{
		n.clear();
		n.push_back(0);
	}
	*/
	big_integer(long long in=0);                                            //构造(整型输入)
	big_integer(const big_integer& in);                                     //构造(本身输入)
	big_integer(std::string in);                                            //构造(字符串输入)
	long long v();                                                          //转换为longlong
	friend inline big_integer abs(const big_integer& a);                    //绝对值
	friend big_integer gcd(big_integer x,big_integer y);                    //最大公约数
	friend big_integer lcm(const big_integer x,const big_integer y);        //最小公倍数

	//重载声明部分
	big_integer operator+(const big_integer& b)const;   					//二元加(big_integer+big_integer)*完成
	big_integer operator+(const long long& b)const;				            //二元加(big_integer+v)*完成
	friend big_integer operator+(const long long& a,const big_integer& b);  //二元加(v+big_integer)*完成

	big_integer operator-(const big_integer& b)const;   					//二元减(big_integer-big_integer)*完成
	big_integer operator-(const long long& b)const;				            //二元减(big_integer-v)*完成
	friend big_integer operator-(const long long& a,const big_integer& b);  //二元减(v-big_integer)*完成

	big_integer operator*(const big_integer& b)const;   					//二元乘(big_integer*big_integer)*完成
	big_integer operator*(const long long& b)const;				            //二元乘(big_integer*v)*完成
	friend big_integer operator*(const long long& a,const big_integer& b);  //二元乘(v*big_integer)*完成

	big_integer operator/(const big_integer& b)const;   					//二元整除(big_integer/big_integer)*完成
	big_integer operator/(const long long& b)const;				            //二元整除(big_integer/v)*完成
	friend big_integer operator/(const long long& a,const big_integer& b);  //二元整除(v/big_integer)*完成

	big_integer operator%(const big_integer& b)const;   					//二元求余(big_integer%big_integer)*完成
	big_integer operator%(const long long& b)const;				            //二元求余(big_integer%v)*完成
	friend big_integer operator%(const long long& a,const big_integer& b);  //二元求余(v%big_integer)*完成

	bool operator>(const big_integer& b)const; 					            //大于*完成
	bool operator>(const long long& b)const;

	bool operator<(const big_integer& b)const; 					            //小于*完成
	bool operator<(const long long& b)const;

	bool operator==(const big_integer& b)const;					            //等于*完成
	bool operator==(const long long& b)const;

	bool operator!=(const big_integer& b)const;					            //不等于*完成
	bool operator!=(const long long& b)const;

	bool operator<=(const big_integer& b)const;					            //小于等于*完成
	bool operator<=(const long long& b)const;

	bool operator>=(const big_integer& b)const;					            //大于等于*完成
	bool operator>=(const long long& b)const;

	big_integer operator++();             						            //前递增*完成
	big_integer operator--();             						            //前递减*完成
	big_integer operator++(int);          						            //后递增*完成
	big_integer operator--(int);          						            //后递减*完成

	big_integer operator-()const;              					            //一元减(前缀)*完成

	void operator=(const long long& a);					                    //整型赋值*完成
	void operator=(const std::string& a);					                //字符串赋值
	void operator+=(const big_integer& a);						            //加后赋值*完成
	void operator-=(const big_integer& a);						            //减后赋值*完成
	void operator*=(const big_integer& a);						            //乘后赋值*完成
	void operator/=(const big_integer& a);						            //向下整除后赋值*完成
	void operator%=(const big_integer& a);						            //求模后赋值*完成
	void operator+=(const long long& a);				                    //加整型后赋值*完成
	void operator-=(const long long& a);				                    //减整型后赋值*完成
	void operator*=(const long long& a);				                    //乘整型后赋值*完成
	void operator/=(const long long& a);				                    //向下整除整型后赋值*完成
	void operator%=(const long long& a);				                    //求模整型的余后赋值*完成

	friend std::ostream& operator<<(std::ostream& out,const big_integer in);//cout输出*完成
	std::string out();
};

#endif