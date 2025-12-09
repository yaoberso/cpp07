#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>

template<class T> class Array{
	public:
		Array()
		{
			_array = NULL;
			_n = 0;
		}
		Array(unsigned int n)
		{
			_array = new T[n]();
			_n = n;
		}
		Array(const Array &other)
		{
			_n = other._n;
			if (_n == 0)
				_array = NULL;
			else
			{
				_array = new T[_n]();
				for (unsigned int i = 0; i < _n; i++)
					_array[i] = other._array[i];
			}
		}
		Array &operator=(const Array &other)
		{
			if (this != &other)
			{
				if (_n != 0)
				{
					delete[] _array;
				}
				_n = other._n;
				if (_n == 0)
				{
					_array = NULL;
					return (*this);
				}
				else
				{
					_array = new T[_n]();
					for (unsigned int i = 0; i < _n; i++)
						_array[i] = other._array[i];
				}
				return (*this);
			}
			return (*this);
		}
		T &operator[](const Array &content);
		const int size();
	private:
		T* _array;
		unsigned int _n;
};

#endif