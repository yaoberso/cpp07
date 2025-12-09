#include <iostream>
#include "../include/Array.hpp"

int main( void ) 
{
	try
	{
    	Array<unsigned int> a(5);
		std::cout << "size: " << a.size() << std::endl;
		for (unsigned int i = 0; i < 5; i++)
		{
			a[i] = i + 5;
		}
		for (unsigned int i = 0; i < 5; i++)
		{
			std::cout << i << ": " << a[i] << std::endl;
		}
		unsigned int i = a[6];
		std::cout << i << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "n is out of range!" << std::endl;
	}
	try
	{
    	Array<unsigned int> a();
		std::cout << "size: " << a.size() << std::endl;
		for (unsigned int i = 0; i < 5; i++)
		{
			a[i] = i + 5;
		}
		for (unsigned int i = 0; i < 5; i++)
		{
			std::cout << i << ": " << a[i] << std::endl;
		}
		unsigned int i = a[6];
		std::cout << i << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "n is out of range!" << std::endl;
	}
}