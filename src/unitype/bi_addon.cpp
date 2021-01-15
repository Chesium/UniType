#pragma once

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