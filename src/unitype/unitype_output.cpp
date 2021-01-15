#pragma once

string uniT::out()
{
	if(this->isBi)
		return this->bi.out();
	else
		return (*(this->op->out))(*this);
}

ostream& operator<<(ostream& out,uniT a)
{
	cout<<a.out();
	return out;
}