#include <iostream>
#include "../include/Iter.hpp"

template <typename T>
void print(const T &val)
{
    std::cout << val << " ";
}

template <typename T>
void incr(T &val)
{
    val++;
}

int main( void ) 
{
    char c_array[] = {'a', 'b', 'c'};
	std::cout << "-----char array-----" << std::endl;
	std::cout << "c_array == {"<< c_array[0] << ", " << c_array[1] << ", " << c_array[2] << "}" << std::endl;
	std::cout << "print:" << std::endl;
    ::Iter(c_array, 3, print<char>);
	std::cout << std::endl;
	std::cout << "(increment)" << std::endl;
	::Iter(c_array, 3, incr<char>);
	std::cout << "print:" << std::endl;
	::Iter(c_array, 3, print<char>);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "-----int array-----" << std::endl;
    int i_array[] = {1, 2, 3};
	std::cout << "c_array == {"<< i_array[0] << ", " << i_array[1] << ", " << i_array[2] << "}" << std::endl;
	std::cout << "print:" << std::endl;
	::Iter(i_array, 3, print<int>);
	std::cout << std::endl;
	std::cout << "(increment)" << std::endl;
	::Iter(i_array, 3, incr<int>);
	std::cout << "print:" << std::endl;
	::Iter(i_array, 3, print<int>);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "-----string array-----" << std::endl;
	std::string s_array[] = {"salut", "yo", "au revoir"};
	std::cout << "c_array == {"<< s_array[0] << ", " << s_array[1] << ", " << s_array[2] << "}" << std::endl;
	std::cout << "print:" << std::endl;
	::Iter(s_array, 3, print<std::string>);
	std::cout << std::endl;
    return 0;
}