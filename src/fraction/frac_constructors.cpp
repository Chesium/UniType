#pragma once

template<typename T1,typename T2>
uniT frac(T1 a,T2 b)
{
	uniT* rp[2]={new uniT(a),new uniT(b)};
	uniT r(_frac);
	r.para.push_back(rp[0]);
	r.para.push_back(rp[1]);
	return r;
}