#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include <stdexcept>

template<class T> class Array{
	public:
		Array()
		{
			_array = NULL;
			_n = 0;
		}
		~Array()
		{
			if (_array != NULL)
			{
				delete[] _array;
			}
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
		T &operator[](unsigned int n)
		{
			if (n >= _n)
			{
				throw std::out_of_range("n is out of range!");
			}
			return (_array[n]);
		}
		unsigned int size() const
		{
			return (_n);
		}
	private:
		T* _array;
		unsigned int _n;
};

#endif