#include "RPN.hpp"
#include <string>
#include <stack>
#include <list>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <limits>

RPN::RPN() {
}

RPN::RPN(const RPN& other) {
	(void)other;
}

RPN& RPN::operator=(const RPN& other) {
	if (this != & other) {
		(void)other;
	}
	return *this;
}

RPN::~RPN() {
}

int RPN::evaluate(const std::string& expression) {
	std::stack<int, std::list<int> > stack;
	std::istringstream iss(expression);
	std::string token;
	
	while (iss >> token) {
#ifdef DEBUG
		std::cout << YEL << "[DEBUG] " << RESET << "token=" << token << std::endl;
#endif

		if (token.size() == 1 && std::isdigit(static_cast<unsigned char>(token[0]))) {
			stack.push(token[0] - '0');
		}
		else if (isOperator(token)) {
			if (stack.size() < 2)
				throw std::runtime_error("invalid expression");

			int rhs = stack.top();
			stack.pop();
			int lhs = stack.top();
			stack.pop();
			
			stack.push(applyOperator(token[0], lhs, rhs));
		}
		else {
			throw std::runtime_error("invalid token");
		}
	}
	if (stack.size() != 1)
		throw std::runtime_error("invalid expression");

	return stack.top();
}

bool RPN::isOperator(const std::string& token) const {
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

int RPN::applyOperator(char op, int lhs, int rhs) const {
	long long result;

	switch (op) {
		case '+':
			result = static_cast<long long>(lhs) + rhs;
			break;
		case '-':
			result = static_cast<long long>(lhs) - rhs;
			break;
		case '*':
			result = static_cast<long long>(lhs) * rhs;
			break;
		case '/':
			if (rhs == 0)
				throw std::runtime_error("division by zero");
			result = static_cast<long long>(lhs) / rhs;
			break;
		default:
			throw std::runtime_error("unknown operator");
	}
	if (result > std::numeric_limits<int>::max() ||
		result < std::numeric_limits<int>::min())
		throw std::runtime_error("overflow");
	return result;
}
