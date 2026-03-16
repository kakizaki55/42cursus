#include "PmergeMe.hpp"
#include <algorithm>
#include <stdexcept>
#include <sstream>
#include <iostream>
#include <ctime>
#include <climits>

PmergeMe::PmergeMe() : _displayLimit(21), _vecTime(0.0), _deqTime(0.0) {}
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other) {
		this->_vec = other._vec;
		this->_deq = other._deq;
		this->_original = other._original;
		this->_vecTime = other._vecTime;
		this->_deqTime = other._deqTime;
		this->_displayLimit = other._displayLimit;
	}
	return *this;
}

void PmergeMe::parseArgs(int argc, char **argv)
{
	for (int i = 1; i < argc; i++) {
		std::string token(argv[i]);
		if (token.empty())
			throw std::runtime_error("Error");
		for (std::size_t j = 0; j < token.size(); j++)
		{
			if (!std::isdigit(static_cast<unsigned char>(token[j])))
				throw std::runtime_error("Error");
		}
		std::istringstream iss(token);
		long val;
		iss >> val;
		if (val <= 0 || val > INT_MAX)
			throw std::runtime_error("Error: Number out of range");
		_vec.push_back(static_cast<int>(val));
		_deq.push_back(static_cast<int>(val));
		_original.push_back(static_cast<int>(val));
	}
	if (_vec.empty())
		throw std::runtime_error("Error: No valid numbers provided");
}

void PmergeMe::sort()
{
	// Time vector sort
	{
		g_comp = 0; // reset comparison count
		std::clock_t start = std::clock();
		fordJohnsonVec(_vec);
		std::clock_t end = std::clock();
		std::cout << "Comparisons: " << g_comp << std::endl;
		_vecTime = (double)(end - start) * 1000000.0 / CLOCKS_PER_SEC;
	}
	// // Time deque sort
	// {
	// 	std::clock_t start = std::clock();
	// 	fordJohnsonDeq(_deq);
	// 	std::clock_t end = std::clock();
	// 	_deqTime = (double)(end - start) * 1000000.0 / CLOCKS_PER_SEC;
	// }
}

void PmergeMe::printBefore() const	
{
	std::cout << "Before: ";
	if (_displayLimit < (int)_original.size())
	{
		for (std::size_t i = 0; i < (std::size_t)_displayLimit; i++)
		{
			if (i) std::cout << ' ';
			std::cout << _original[i];
		}
		std::cout << " [...]";
	}
	else
	{
		for (std::size_t i = 0; i < _original.size(); i++)
		{
			if (i) std::cout << ' ';
			std::cout << _original[i];
		}
	}
	std::cout << '\n';
}

void PmergeMe::printAfter() const
{
	std::cout << "After:  ";
	if (_displayLimit < (int)_vec.size())
	{
		for (std::size_t i = 0; i < (std::size_t)_displayLimit; i++)
		{
			if (i) std::cout << ' ';
			std::cout << _vec[i];
		}
		std::cout << " [...]";
	}
	else
	{
		for (std::size_t i = 0; i < _vec.size(); i++)
		{
			if (i) std::cout << ' ';
			std::cout << _vec[i];
		}
	}
	std::cout << '\n';
}

double PmergeMe::timeVec() const
{
	return _vecTime;
}
double PmergeMe::timeDeq() const  
{
	 return _deqTime; 
}
std::size_t PmergeMe::size() const { return _vec.size(); }
