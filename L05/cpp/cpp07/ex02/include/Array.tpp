#include "../include/Array.hpp"

// Default constructor: empty array
template <typename Type>
Array<Type>::Array() : _data(NULL), _size(0) {}

// Parameterized constructor: array of n elements initialized by default
template <typename Type>
Array<Type>::Array(unsigned int n) : _data(NULL), _size(n)
{
	if (n > 0)
		_data = new Type[n]();
}

// Copy constructor: deep copy
template <typename Type>
Array<Type>::Array(const Array &other) : _data(NULL), _size(other._size)
{
	if (_size > 0)
	{
		_data = new Type[_size]();
		for (unsigned int i = 0; i < _size; i++)
			_data[i] = other._data[i];
	}
}

// Assignment operator: deep copy
template <typename Type>
Array<Type> &Array<Type>::operator=(const Array &other)
{
	if (this != &other)
	{
		delete[] _data;
		_data = NULL;
		_size = other._size;
		if (_size > 0)
		{
			_data = new Type[_size]();
			for (unsigned int i = 0; i < _size; i++)
				_data[i] = other._data[i];
		}
	}
	return *this;
}

// Destructor
template <typename Type>
Array<Type>::~Array()
{
	delete[] _data;
}

// Subscript operator (non-const)
template <typename Type>
Type &Array<Type>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::exception();
	return _data[index];
}

// Subscript operator (const)
template <typename Type>
const Type &Array<Type>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw std::exception();
	return _data[index];
}

// Size getter
template <typename Type>
unsigned int Array<Type>::size() const
{
	return _size;
}
