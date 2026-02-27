#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN {
private:
	std::stack<long> _stack;
	
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	
public:
	RPN();
	~RPN();
	
	long evaluate(const std::string &expression);
};

#endif
