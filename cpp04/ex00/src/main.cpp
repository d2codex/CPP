#include "Logger.hpp"
#include "Animal.hpp"
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
/*
	const Animal* meta = new Animal();
	meta->makeSound();

	const Animal* j = new Dog();
	std::cout << j->getType() << " " << std::endl;
	j->makeSound();
	delete meta;
*/
	// default animal ctor / dtor
	{
		std::cout << cyn("====== Test[1]: default ctor / dtor ======\n");
		Animal animal;
	}
	// Type constructor
	{
		std::cout << cyn("======= Test[2]: type constructor ========\n");
		Animal animal("any thing you want here");
	}
	// Copy Constructor
	{
		std::cout << cyn("======= Test[3]: copy constructor ========\n");
		Animal a;
		Animal b(a);
	}
	// Assignment Constructor
	{
		std::cout << cyn("===== Test[4]: assignment constructor ====\n");
		Animal a("type a");
		Animal b("type b");

		b = a;
	}
	// cat: Declaring pointer to animal forces us to test polymorphism
	// shows that the makeSound is being called from cat and not the parent
	// and why we need to declare virtual in parent - the virtual part
	// calls the most derived member function
	{
		std::cout << cyn("== Test[5]: Animal(base) / Cat(derived) ==\n");
		const Animal* garfield = new Cat();
		garfield->makeSound();
		delete garfield;
	}
		// cat copy
	{
		std::cout << cyn("============== Test[6]: Copy ============\n");
		Cat felix;
		Cat garfield(felix);
	}
	// cat assignment
	{
		std::cout << cyn("=========== Test[6]: Assignment ==========\n");
		Cat felix;
		Cat garfield;

		garfield = felix;
		garfield.makeSound();
	}

}
