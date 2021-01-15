#pragma once

uniT::uniT()
{
	isBi=1;
}

uniT::uniT(long long n)
{
	isBi=1;
	bi=big_integer(n);
}

uniT::uniT(const Bi& n)
{
	isBi=1;
	bi=n;
}

uniT::uniT(const opr& op_in)
{
	isBi=0;
	op=&op_in;
}

uniT::uniT(const uniT& n)
{
	isBi=n.isBi;
	para=n.para;
	bi=n.bi;
	op=n.op;
}