#ifndef TESTS_HPP
#define TESTS_HPP

#include <string>

int testIntConstructor(void);
int testFloatConstructor(void);
int	testToFloat(void);

void printHeader(const std::string& testName);
void printSummary(int failed, int total);

bool assertEqualInt(const std::string& name, int expected, int actual);
bool assertEqualFloat(const std::string& testName,
					   float expected, float actual);
#endif
