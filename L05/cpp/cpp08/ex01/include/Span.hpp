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
	// Orthodox Canonical Form
	Span();
	Span(unsigned int n);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	// Member functions
	void	addNumber(int number);
	int		shortestSpan() const;
	int		longestSpan() const;

	// Template function to add range of iterators
	template <typename Iterator>
	void addRange(Iterator begin, Iterator end) {
		unsigned int distance = std::distance(begin, end);
		if (_numbers.size() + distance > _maxSize) {
			throw SpanFullException();
		}
		_numbers.insert(_numbers.end(), begin, end);
	}

	// Exceptions
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
