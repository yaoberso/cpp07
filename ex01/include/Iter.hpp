#ifndef Iter_HPP
#define Iter_HPP
#include <iostream>
template<typename T, typename F>
void Iter(T *array,size_t len, F fonction)
{
	for(size_t i = 0; i < len; i++)
	{
		fonction(array[i]);
	}
}

#endif