#pragma once

template<typename T>
inline bool isint(T a)
{
	return is_integral<T>::value;
}