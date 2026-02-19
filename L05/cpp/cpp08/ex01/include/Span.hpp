#pragma once

#include <vector>
#include <algorithm>
#include <exception>
#include <iterator>


class Span {
private:
	unsigned int		_maxSize;
	std::vector<int>	_numbers;

public:
	Span();
	Span(unsigned int n);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void	addNumber(int number);
	int		shortestSpan() const;
	int		longestSpan() const;


	template <typename Iterator>
	void addRange(Iterator begin, Iterator end);

	
	class SpanFullException : public std::exception {
	public:
		const char* what() const throw() {
			return "Cannot add number: Span is full";
		}
	};

	class NoSpanException : public std::exception {
	public:
		const char* what() const throw() {
			return "Cannot find span: not enough numbers";
		}
	};
};

#include "Span.tpp"