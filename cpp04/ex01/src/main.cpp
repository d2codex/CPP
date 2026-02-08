#include "Logger.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "colors.hpp"
#include <iostream>

bool initLogger(int argc, char **argv)
{
	if (argc == 1)
	{
		Logger::get().setThreshold(NONE);
		return (true);
	}
	if (argc == 2)
	{
		logLevel level = Logger::stringToLevel(argv[1]);
		if (level == INVALID)
		{
			std::cout << red("Error. invalid log level\n");
			std::cout << cyn("usage: ./bin/<program_name> [log level]\n");
			std::cout << cyn("log levels: info warning error\n");
			return (false);
		}
		#ifndef DBUG
		if (level == DEBUG)
		{
			std::cout << mag("Warning: DEBUG messages are not enabled in this build.\n");
			Logger::get().setThreshold(INFO); // fallback threshold
			return (true);
		}
		#endif
		Logger::get().setThreshold(level);
		return (true);
	}
	std::cout << cyn("usage: ./bin/<program_name> [log level]\n");
	std::cout << cyn("log levels: info warning error\n");
	return (false);
}

int	main(int argc, char **argv)
{
	if (!initLogger(argc, argv))
		return (1);
	// ctor/dtor
	{
		std::cout << cyn("====== Test[1]: default ctor / dtor ======\n");
		Brain brain;
	}
	// ctor/dtor
	{
		std::cout << cyn("======= Test[2]: copy constructor ========\n");
		Brain brain;
		Brain pinky(brain);

	}
	// Assignment Constructor
	{
		std::cout << cyn("===== Test[3]: assignment constructor ====\n");
		Brain a;
		Brain b;

		b = a;
	}
	// default cat ctor / dtor
	{
		std::cout << cyn("====== Test[4]: default ctor / dtor ======\n");
		Cat felix;
	}
	// Copy Constructor
	{
		std::cout << cyn("======= Test[5]: copy constructor ========\n");
		Cat felix;
		Cat garfield(felix);
	}
	// Assignment Constructor
	{
		std::cout << cyn("===== Test[6]: assignment constructor ====\n");
		Cat felix;
		Cat garfield;

		felix = garfield;
	}
	// cat: Declaring pointer to animal forces us to test polymorphism
	{
		std::cout << cyn("== Test[7]: Animal(base) / Cat(derived) ==\n");
		const Animal* garfield = new Cat();
		garfield->makeSound();
		delete garfield;
	}
	// dog tests
	{
		std::cout << cyn("== Test[8]: Animal(base) / Dog(derived) ==\n");
		const Animal* snoopy = new Dog();
		snoopy->makeSound();
		delete snoopy;
	}
	// dog copy
	{
		std::cout << cyn("============== Test[9]: Copy ============\n");
		Dog spot;
		Dog snoopy(spot);
	}
	// dog assignment
	{
		std::cout << cyn("=========== Test[10]: Assignment ==========\n");
		Dog spot;
		Dog snoopy;

		snoopy = spot;
		snoopy.makeSound();
	}
	// the farm
	{
		std::cout << cyn("========== Test[11]: Animal Farm =========\n");
		size_t size = 10;
		Animal** farm = new Animal*[size];
		for(size_t i = 0; i < size / 2; i++)
		{
			farm[i] = new Cat();
		}
		for(size_t i = size / 2 ; i < size; i++)
		{
			farm[i] = new Dog();
		}

		for(size_t i = 0; i < size; i++)
		{
			delete farm[i];
		}
		
		delete[] farm;
	}
}
