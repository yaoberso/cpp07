#ifndef FCT_TEMPLATE_HPP
#define FCT_TEMPLATE_HPP
#include <iostream>
template<typename T>
void swap(T& value1, T& value2)
{
	T temp = value1;
	value1 = value2;
	value2 = temp;
}

template<typename T>
T min(const T& value1, const T& value2)
{
	if (value1 < value2)
		return(value1);
	else
		return(value2);
}

template<typename T>
T max(const T& value1, const T& value2)
{
	if (value1 > value2)
		return(value1);
	else
		return(value2);
}

#endif