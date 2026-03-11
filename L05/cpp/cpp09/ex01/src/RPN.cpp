#include "RPN.hpp"
#include <sstream>
#include <cctype>
#include <stdexcept>
#include <iostream>

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other) {
		this->_stack = other._stack;
	}
	return *this;
}

long pop_top(std::stack<long> &s)
{
	long val = s.top();
	s.pop();
	return val;
}

long RPN::evaluate(const std::string &expression) {
	std::stringstream ss(expression);
	std::string token;
	
	// Clear stack for fresh evaluation
	while (!_stack.empty())
		_stack.pop();
	
	while (ss >> token) 
	{
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (_stack.size() < 2)
			{
				throw std::runtime_error("Error: not enough operands");
			}
			
			long b = pop_top(_stack);
			long a = pop_top(_stack);
			long result;
			
			if (token == "+") {
				result = a + b;
			} else if (token == "-") {
				result = a - b;
			} else if (token == "*") {
				result = a * b;
			} else if (token == "/") {
				if (b == 0)
				{
					throw std::runtime_error("Error: division by zero");
				}
				result = a / b;
			}
			_stack.push(result);
		}
		else if (token.length() == 1 && std::isdigit(token[0]))
		{
			int num = token[0] - '0';
			_stack.push(num);
		}
		else
		{
			throw std::runtime_error("Error: Not a number or operator => " + token);
		}
	}
	
	if (_stack.size() != 1)
	{
		throw std::runtime_error("Error: Invalid expression");
	}
	
	long result = _stack.top();
	_stack.pop();
	return result;
}
