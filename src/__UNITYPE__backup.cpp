#include <iostream>
#include <deque>
#include <string>
#include <cstdlib>
#include <sstream>
#include <typeinfo>
#include <type_traits>
#include "big_integer/_big_integer.h"
#define uint unsigned int
using namespace std;
//frac:1
typedef big_integer Bi;
class uniT;

uniT frac_add(uniT& a,uniT& b);


void unierror(string n)
{
	cout<<"[UNITYPE] [Error:"<<n<<"]!"<<endl;
	exit(0);
}


/////////////////////////////////////////////////////////////////////////


//------opr part begin
class opr
{
public:
	int id;
	string name;
	opr(int id_in,
		string name_in,
		uniT (*add_in)(const uniT& a,const uniT& b),
		uniT (*minus_in)(const uniT& a,const uniT& b),
		uniT (*multiply_in)(const uniT& a,const uniT& b),
		uniT (*divide_in)(const uniT& a,const uniT& b),
		string (*out_in)(const uniT& a))
	{
		id=id_in;
		name=name_in;
		add=add_in;
		minus=minus_in;
		multiply=multiply_in;
		divide=divide_in;
		out=out_in;
	}
	uniT (*add)(const uniT& a,const uniT& b);
	uniT (*minus)(const uniT& a,const uniT& b);
	uniT (*multiply)(const uniT& a,const uniT& b);
	uniT (*divide)(const uniT& a,const uniT& b);
	string (*out)(const uniT& a);
};
//------opr part end

//------uniT part begin

class uniT
{
public:
	bool isBi;
	deque<uniT*>para;
	Bi bi;
	const opr* op;

	uniT(const opr& op_in)
	{
		isBi=0;
		op=&op_in;
	}
	uniT()
	{
		isBi=1;
	}
	uniT(const Bi& n)
	{
		isBi=1;
		bi=n;
	}
	uniT(long long n)
	{
		isBi=1;
		bi=big_integer(n);
	}
	uniT(const uniT& n)
	{
		isBi=n.isBi;
		para=n.para;
		bi=n.bi;
		op=n.op;
	}
	//int id(){return this->op->id;}

	uniT operator+(const uniT& b);
	uniT operator-(const uniT& b);
	uniT operator*(const uniT& b);
	uniT operator/(const uniT& b);
	friend ostream& operator<<(ostream& out,uniT a);
	string out();
};


string uniT::out()
{
	if(this->isBi)
		return this->bi.out();
	else
		return (*(this->op->out))(*this);
}

//------bi op start
uniT bi_add(const Bi& a,const uniT& b)
{
	uniT r;
	if(b.isBi)
	{
		r.bi=a+b.bi;
	}
	else
	{
		switch(b.op->id)
		{
			default:
				unierror("Can't find the correct function to calculate");
				break;
		}
	}
	return r;
}
uniT bi_minus(const Bi& a,const uniT& b)
{
	uniT r;
	if(b.isBi)
	{
		r.bi=a-b.bi;
	}
	else
	{
		switch(b.op->id)
		{
			default:
				unierror("Can't find the correct function to calculate");
				break;
		}
	}
	return r;
}
uniT bi_multiply(const Bi& a,const uniT& b)
{
	uniT r;
	if(b.isBi)
	{
		r.bi=a*b.bi;
	}
	else
	{
		switch(b.op->id)
		{
			default:
				unierror("Can't find the correct function to calculate");
				break;
		}
	}
	return r;
}
uniT bi_devide(const Bi& a,const uniT& b)
{
	uniT r;
	if(b.isBi)
	{
		r.bi=a/b.bi;
	}
	else
	{
		switch(b.op->id)
		{
			default:
				unierror("Can't find the correct function to calculate");
				break;
		}
	}
	return r;
}
//------bi op end


uniT uniT::operator+(const uniT& b)
{
	if(this->isBi)
		return bi_add(this->bi,b);
	else
		return (*(this->op->add))(*this,b);
}
uniT uniT::operator-(const uniT& b)
{
	if(this->isBi)
		return bi_minus(this->bi,b);
	else
		return (*(this->op->minus))(*this,b);
}
uniT uniT::operator*(const uniT& b)
{
	if(this->isBi)
		return bi_multiply(this->bi,b);
	else
		return (*(this->op->multiply))(*this,b);
}
uniT uniT::operator/(const uniT& b)
{
	if(this->isBi)
		return bi_devide(this->bi,b);
	else
		return (*(this->op->divide))(*this,b);
}

ostream& operator<<(ostream& out,uniT a)
{
	cout<<a.out();
	return out;
}
//------uniT part end

//------fraction part begin
uniT frac_add(const uniT& a,const uniT& b);
uniT frac_minus(const uniT& a,const uniT& b);
uniT frac_multiply(const uniT& a,const uniT& b);
uniT frac_devide(const uniT& a,const uniT& b);
string frac_out(const uniT& a);

const opr _frac(1,"frac",frac_add,frac_minus,frac_multiply,frac_devide,frac_out);


uniT frac_add(const uniT& a,const uniT& b)
{
	uniT r(_frac);
	if(b.isBi)
	{
		unierror("frac and bi");
	}
	else
	{
		switch(b.op->id)
		{
			case 1:
				uniT* rp[2];
				rp[0]=new uniT((*(a.para[0]))*(*(b.para[1]))+(*(b.para[0]))*(*(a.para[1])));
				rp[1]=new uniT((*(a.para[1]))*(*(b.para[1])));
				r.para.push_back(rp[0]);
				r.para.push_back(rp[1]);
				break;
			default:
				unierror("Can't find the correct function to calculate");
				break;
		}
	}
	return r;
}
uniT frac_minus(const uniT& a,const uniT& b)
{
	uniT r(_frac);
	if(b.isBi)
	{
		unierror("frac and bi");
	}
	else
	{
		switch(b.op->id)
		{
			case 1:
				uniT* rp[2];
				rp[0]=new uniT((*(a.para[0]))*(*(b.para[1]))-(*(b.para[0]))*(*(a.para[1])));
				rp[1]=new uniT((*(a.para[1]))*(*(b.para[1])));
				r.para.push_back(rp[0]);
				r.para.push_back(rp[1]);
				break;
			default:
				unierror("Can't find the correct function to calculate");
				break;
		}
	}
	return r;
}

uniT frac_multiply(const uniT& a,const uniT& b)
{
	uniT r(_frac);
	if(b.isBi)
	{
		unierror("frac and bi");
	}
	else
	{
		switch(b.op->id)
		{
			case 1:
				uniT* rp[2];
				rp[0]=new uniT((*(a.para[0]))*(*(b.para[0])));
				rp[1]=new uniT((*(a.para[1]))*(*(b.para[1])));
				r.para.push_back(rp[0]);
				r.para.push_back(rp[1]);
				break;
			default:
				unierror("Can't find the correct function to calculate");
				break;
		}
	}
	return r;
}

uniT frac_devide(const uniT& a,const uniT& b)
{
	uniT r(_frac);
	if(b.isBi)
	{
		unierror("frac and bi");
	}
	else
	{
		switch(b.op->id)
		{
			case 1:
				uniT* rp[2];
				rp[0]=new uniT((*(a.para[0]))*(*(b.para[1])));
				rp[1]=new uniT((*(a.para[1]))*(*(b.para[0])));
				r.para.push_back(rp[0]);
				r.para.push_back(rp[1]);
				break;
			default:
				unierror("Can't find the correct function to calculate");
				break;
		}
	}
	return r;
}

string frac_out(const uniT& a)
{
	stringstream ss;
	ss<<"("<<a.para[0]->out()<<"/"<<a.para[1]->out()<<")";
	return ss.str();
}

template<typename T>
inline bool isint(T a)
{
	return is_integral<T>::value;
}

template<typename T1,typename T2>
uniT frac(T1 a,T2 b)
{
	uniT* rp[2]={new uniT(a),new uniT(b)};
	uniT r(_frac);
	r.para.push_back(rp[0]);
	r.para.push_back(rp[1]);
	return r;
}
//------fraction part end


/*
int main()
{
	cout<<"pass"<<endl;
	return 0;
}
*/