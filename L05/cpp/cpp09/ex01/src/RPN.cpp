#include "RPN.hpp"
#include <sstream>
#include <cctype>
#include <stdexcept>
#include <iostream>

RPN::RPN() {
}

RPN::~RPN() {
}

long RPN::evaluate(const std::string &expression) {
	std::stringstream ss(expression);
	std::string token;
	
	// Clear stack for fresh evaluation
	while (!_stack.empty())
		_stack.pop();
	
	while (ss >> token) {
		// Check if token is an operator
		if (token == "+" || token == "-" || token == "*" || token == "/") {
			if (_stack.size() < 2) {
				throw std::runtime_error("Error");
			}
			
			long b = _stack.top(); _stack.pop();
			long a = _stack.top(); _stack.pop();
			long result;
			
			if (token == "+") {
				result = a + b;
			} else if (token == "-") {
				result = a - b;
			} else if (token == "*") {
				result = a * b;
			} else if (token == "/") {
				if (b == 0) {
					throw std::runtime_error("Error");
				}
				result = a / b;
			}
			_stack.push(result);
		}
		// Check if token is a number
		else if (token.length() == 1 && std::isdigit(token[0])) {
			int num = token[0] - '0';
			_stack.push(num);
		}
		else {
			throw std::runtime_error("Error");
		}
	}
	
	if (_stack.size() != 1) {
		throw std::runtime_error("Error");
	}
	
	long result = _stack.top();
	_stack.pop();
	return result;
}
