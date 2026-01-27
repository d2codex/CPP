#ifndef TESTS_HPP
#define TESTS_HPP

#include <string>

int testIntConstructor();

void printHeader(const std::string& testName);
void printSummary(const std::string& testName, int failed, int total);

bool assertEqualInt(const std::string& name, int expected, int actual);

#endif
