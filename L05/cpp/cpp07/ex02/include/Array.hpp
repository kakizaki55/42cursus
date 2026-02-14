#pragma once

#include <exception>
#include <cstddef>

template <typename Type>
class Array
{
private:
	Type			*_data;
	unsigned int	_size;

public:
	Array();
	Array(unsigned int n);
	Array(const Array &other);
	Array &operator=(const Array &other);
	~Array();

	// Subscript operator (non-const)
	Type &operator[](unsigned int index);

	// Subscript operator (const)
	const Type &operator[](unsigned int index) const;

	// Size getter
	unsigned int size() const;
};

#include "Array.tpp"

