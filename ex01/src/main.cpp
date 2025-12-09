#include <iostream>
#include "../include/Iter.hpp"

template <typename T>
void print(const T &val)
{
    std::cout << val << std::endl;
}

template <typename T>
void incr(T &val)
{
    val++;
}

int main( void ) 
{
    char c_array[] = {'a', 'b', 'c'};
    ::Iter(c_array, 3, print<char>);
	::Iter(c_array, 3, incr<char>);
	::Iter(c_array, 3, print<char>);
    int i_array[] = {1, 2, 3};
	::Iter(i_array, 3, print<int>);
	::Iter(i_array, 3, incr<int>);
	::Iter(i_array, 3, print<int>);
	std::string s_array[] = {"salut", "yo", "au revoir"};
	::Iter(s_array, 3, print<std::string>);
    return 0;
}