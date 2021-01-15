#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>
#include <type_traits>
#include "__UniType__.h"

using namespace std;
int main()
{
	uniT te=frac(frac(big_integer("18754198645124"),3),frac(4,5));
	cout<<te<<"";
}