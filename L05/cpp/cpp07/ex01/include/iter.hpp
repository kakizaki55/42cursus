#pragma once

template <typename T>
void print(const T &x)
{
    std::cout << x << " ";
}

template <typename T>
void increment(T &x)
{
    x++;
}

template <typename T>
void doubleValue(T &x)
{
    x *= 2;
}

template <typename T, typename Function>
void iter(T *array, const size_t length, Function func)
{
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

// template <typename T, typename Function>
// void iter(const T *array, const size_t length, Function func)
// {
// 	for (size_t i = 0; i < length; i++)
// 		func(array[i]);
// }
