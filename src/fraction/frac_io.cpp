#pragma once

string frac_out(const uniT& a)
{
	stringstream ss;
	ss<<"("<<a.para[0]->out()<<"/"<<a.para[1]->out()<<")";
	return ss.str();
}