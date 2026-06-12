#pragma once

#include <string>

// colors
#define RED		"\033[31m"
#define YEL		"\033[33m"
#define RESET	"\033[0m"

/**
 * @brief Evaluates Reverse Polish Notation (RPN) expressions.
 *
 * Provides functionality to parse and evaluate mathematical expressions
 * written in postfix notation using a stack-based approach.
 */
class RPN {
public:
	RPN();
	~RPN();

	int evaluate(const std::string& expression);

private:
	// canonical form
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);

	bool isOperator(const std::string& token) const;
	int applyOperator(char op, int lhs, int rhs) const;
};
