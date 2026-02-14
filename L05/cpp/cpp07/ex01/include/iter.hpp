#pragma once

// For non-const arrays (can modify elements)
template <typename Type, typename Function>
void iter(Type *array, const size_t length, Function func)
{
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

// For const arrays (read-only)
template <typename Type, typename Function>
void iter(const Type *array, const size_t length, Function func)
{
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}
