#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
	std::cout << "=== Subject Test ===" << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << "\n=== Test: Adding too many numbers ===" << std::endl;
	{
		Span sp(3);
		try {
			sp.addNumber(1);
			sp.addNumber(2);
			sp.addNumber(3);
			sp.addNumber(4); // Should throw
			std::cout << "No exception thrown!" << std::endl;
		} catch (const std::exception& e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	std::cout << "\n=== Test: No span (empty) ===" << std::endl;
	{
		Span sp(5);
		try {
			sp.shortestSpan();
		} catch (const std::exception& e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	std::cout << "\n=== Test: No span (one element) ===" << std::endl;
	{
		Span sp(5);
		sp.addNumber(42);
		try {
			sp.longestSpan();
		} catch (const std::exception& e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	std::cout << "\n=== Test: Add range with iterators ===" << std::endl;
	{
		Span sp(10);
		std::vector<int> vec;
		vec.push_back(5);
		vec.push_back(10);
		vec.push_back(15);
		vec.push_back(20);
		vec.push_back(25);

		sp.addRange(vec.begin(), vec.end());
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}

	std::cout << "\n=== Test: Add range overflow ===" << std::endl;
	{
		Span sp(3);
		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(4);
		vec.push_back(5);

		try {
			sp.addRange(vec.begin(), vec.end());
		} catch (const std::exception& e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	std::cout << "\n=== Test: 10,000 numbers ===" << std::endl;
	{
		Span sp(10000);
		std::srand(std::time(NULL));

		for (int i = 0; i < 10000; ++i) {
			sp.addNumber(std::rand());
		}

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}

	std::cout << "\n=== Test: 100,000 numbers with addRange ===" << std::endl;
	{
		Span sp(100000);
		std::vector<int> bigVec;

		for (int i = 0; i < 100000; ++i) {
			bigVec.push_back(std::rand());
		}

		sp.addRange(bigVec.begin(), bigVec.end());
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}

	std::cout << "\n=== Test: Copy constructor ===" << std::endl;
	{
		Span sp1(5);
		sp1.addNumber(1);
		sp1.addNumber(100);

		Span sp2(sp1);
		std::cout << "sp2 shortest: " << sp2.shortestSpan() << std::endl;
		std::cout << "sp2 longest: " << sp2.longestSpan() << std::endl;
	}

	std::cout << "\n=== Test: Assignment operator ===" << std::endl;
	{
		Span sp1(5);
		sp1.addNumber(10);
		sp1.addNumber(20);
		sp1.addNumber(30);

		Span sp2(10);
		sp2 = sp1;
		std::cout << "sp2 shortest: " << sp2.shortestSpan() << std::endl;
		std::cout << "sp2 longest: " << sp2.longestSpan() << std::endl;
	}

	return 0;
}
