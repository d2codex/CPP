#pragma once

#include <string>

// colors
#define RED		"\033[31m"
#define YEL		"\033[33m"
#define RESET	"\033[0m"

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
