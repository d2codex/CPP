#include "Serializer.hpp"
#include "Logger.hpp"
#include "colors.hpp"
#include <iostream>

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

void printResults(const uintptr_t raw, const Data* original, const Data* deserialized)
{
	std::cout << "serialized value of raw: " << raw << std::endl;
	std::cout << "raw value in hex: 0x" << std::hex << raw << std::endl;
	std::cout << "deserialized ptr: " << deserialized << std::endl;

	if (deserialized == original)
		std::cout << grn("Success\n");
	else
		std::cout << red("Fail\n");
}

int	main(int argc, char **argv)
{
	if (!initLogger(argc, argv))
		return (1);

	// normal non null on stack
	{
		printTestName("Normal non null on stack");
		Data	data;
		data.value = 42;

		uintptr_t raw = Serializer::serialize(&data);
		Data* ptr = Serializer::deserialize(raw);

		printResults(raw, &data, ptr);

	}
	// test null pointer
	{
		printTestName("null pointer");
		Data*	data = NULL;

		uintptr_t raw = Serializer::serialize(data);
		Data* ptr = Serializer::deserialize(raw);

		printResults(raw, data, ptr);
	}
	// test dynamic allocation
	{
		printTestName("pointer on heap");
		Data*	data = new Data;
		data->value = 42;

		uintptr_t raw = Serializer::serialize(data);
		Data* ptr = Serializer::deserialize(raw);

		printResults(raw, data, ptr);
	}
}

