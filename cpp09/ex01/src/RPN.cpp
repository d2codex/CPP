#include "RPN.hpp"
#include <string>
#include <stack>
#include <list>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <limits>

/**
 * @brief Constructs an empty RPN evaluator.
 */
RPN::RPN() {
}

/**
 * @brief Disabled copy constructor (canonical form requirement only).
 */
RPN::RPN(const RPN& other) {
	(void)other;
}

/**
 * @brief Disabled assignment operator (canonical form requirement only).
 */
RPN& RPN::operator=(const RPN& other) {
	(void)other;
	return *this;
}

/**
 * @brief Destroys the RPN evaluator.
 */
RPN::~RPN() {
}

/**
 * @brief Evaluates a Reverse Polish Notation (RPN) expression.
 *
 * Parses a space-separated expression and computes its result using
 * a stack-based evaluation algorithm. Supports single-digit operands
 * and basic arithmetic operators.
 *
 * @param expression RPN expression to evaluate.
 * @return Result of the evaluated expression.
 * @throws std::runtime_error If the expression is invalid, contains
 *         invalid tokens, or has incorrect operand/operator structure.
 */
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

/**
 * @brief Checks whether a token is a supported arithmetic operator.
 *
 * Supported operators are: +, -, *, /.
 *
 * @param token String token to check.
 * @return true if the token is an operator, false otherwise.
 */
bool RPN::isOperator(const std::string& token) const {
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

/**
 * @brief Applies an arithmetic operator to two operands.
 *
 * Performs the operation in a wider type to detect overflow safely.
 * Division by zero is not allowed.
 *
 * @param op Arithmetic operator (+, -, *, /).
 * @param lhs Left-hand operand.
 * @param rhs Right-hand operand.
 * @return Result of the operation.
 * @throws std::runtime_error If the operator is unknown, division by
 *         zero occurs, or overflow is detected.
 */
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
