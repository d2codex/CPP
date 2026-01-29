/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 22:14:47 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/29 22:14:49 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

int testIntConstructor(void);
int testFloatConstructor(void);
int	testToFloat(void);
int	testToInt(void);
int testOutputOperator(void);
int	testAddition(void);
int testSubtraction(void);
int	testMultiplication(void);
int testDivision(void);
int testIncrDecr(void);
int testComparisons(void);
int testMin(void);
int	testMax(void);

void printHeader(const std::string& testName);
void printSummary(int failed, int total);

bool assertEqualInt(const std::string& name, int expected, int actual);
bool assertEqualFloat(const std::string& testName,
					float expected, float actual);
bool assertEqualFloatExact(const std::string& name,
					float expected, float actual);
bool assertEqualBool(const std::string& name, bool expected, bool actual);
