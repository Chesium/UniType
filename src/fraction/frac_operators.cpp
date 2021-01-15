#pragma once

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