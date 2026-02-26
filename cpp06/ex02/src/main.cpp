#include "Base.hpp"
#include "Logger.hpp"
#include "colors.hpp"
#include <iostream>
#include <cassert>

bool initLogger(int argc, char **argv)
{
	if (argc == 1)
	{
		Logger::get().setThreshold(Logger::NONE);
		return (true);
	}
	if (argc == 2)
	{
		Logger::logLevel level = Logger::stringToLevel(argv[1]);
		if (level == Logger::INVALID)
		{
			std::cout << red("Error. invalid log level\n");
			std::cout << cyn("usage: ./bin/<program_name> [log level]\n");
			std::cout << cyn("log levels: debug(debug build only) info warning\n");
			return (false);
		}
		#ifndef DBUG
		if (level == Logger::DEBUG)
		{
			std::cout << mag("Warning: DEBUG messages are not enabled in this build.\n");
			Logger::get().setThreshold(Logger::INFO); // fallback threshold
			return (true);
		}
		#endif
		Logger::get().setThreshold(level);
		return (true);
	}
	std::cout << cyn("usage: ./bin/<program_name> [log level]\n");
	std::cout << cyn("log levels: debug(debug build only) info warning\n");
	return (false);
}

void printTestName(const std::string& testName)
{
	std::cout << yel("======================================================\n");
	std::cout << YEL << "Testing " << testName << RESET << '\n';
}

int	main(int argc, char **argv)
{

	if (!initLogger(argc, argv))
		return (1);

	std::srand(std::time(NULL));

	// Identify type by pointer - heap allocation
	{
		printTestName("Identify type by pointer - heap allocation");
		size_t numTests = 10;
		size_t countA = 0;
		size_t countB = 0;
		size_t countC = 0;
		for (size_t i = 0; i < numTests; i++)
		{
			Base* obj = generate();
			identify(obj);
			Type t = identifyType(obj);
			if (t == A_TYPE)
				countA++;
			if (t == B_TYPE)
				countB++;
			if (t == C_TYPE)
				countC++;
			delete obj;
		}
		std::cout << "Total A type: " << countA << std::endl;
		std::cout << "Total B type: " << countB << std::endl;
		std::cout << "Total C type: " << countC << std::endl;
	}
	// Identify type by reference - heap allocation
	{
		printTestName("Identify type by reference - heap allocation");
		size_t numTests = 10;
		size_t countA = 0;
		size_t countB = 0;
		size_t countC = 0;
		for (size_t i = 0; i < numTests; i++)
		{
			Base* obj = generate();
			identify(obj);
			Type t = identifyType(*obj);
			if (t == A_TYPE)
				countA++;
			if (t == B_TYPE)
				countB++;
			if (t == C_TYPE)
				countC++;
			delete obj;
		}
		std::cout << "Total A type: " << countA << std::endl;
		std::cout << "Total B type: " << countB << std::endl;
		std::cout << "Total C type: " << countC << std::endl;
	}
	// null pointer test (pointer only)
	{
		printTestName("null pointer");
		Base* obj = NULL;
		identify(obj);
		identifyType(obj);
	}
	// Identify type by pointer - stack
	{
		printTestName("Identify type by pointer - stack");
		A a;
		B b;
		C c;
		
		identify(&a);
		Type tA = identifyType(&a);
		assert(A_TYPE == tA);

		identify(&b);
		Type tB = identifyType(&b);
		assert(B_TYPE == tB);

		identify(&c);
		Type tC = identifyType(&c);
		assert(C_TYPE == tC);

		// Identify type by reference - stack
		printTestName("Identify type by reference - stack");

		identify(a);
		Type tA_ref = identifyType(a);
		assert(A_TYPE == tA_ref);

		identify(b);
		Type tB_ref = identifyType(b);
		assert(B_TYPE == tB_ref);

		identify(c);
		Type tC_ref = identifyType(c);
		assert(C_TYPE == tC_ref);
	}
}
