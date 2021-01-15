#pragma once

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