#include "Span.hpp"

template <typename Iterator>
void Span::addRange(Iterator begin, Iterator end) {
	unsigned int distance = std::distance(begin, end);
	if (_numbers.size() + distance > _maxSize) {
		throw SpanFullException();
	}
	_numbers.insert(_numbers.end(), begin, end);
}
