#pragma once

#include <string>

void	printHeader(const std::string& testName);
void	printSummary(int failed, int total);

bool	assertEqual(const std::string& name, const std::string& expected,
					const std::string& actual);
bool	assertNotEqPtr(const std::string& name, const void* ptr1, const void* ptr2);

int		iceTest();

