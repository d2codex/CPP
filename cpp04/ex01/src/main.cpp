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
		std::cout << cyn("===== Test[4]: assignment constructor ====\n");
		Brain a;
		Brain b;

		b = a;
	}

/*	// default animal ctor / dtor
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
		std::cout << cyn("============== Test[5]: Copy ============\n");
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
		// compiler at schoool does not allow this
		// garfield = garfield;
	}
	// dog tests
	{
		std::cout << cyn("== Test[5]: Animal(base) / Dog(derived) ==\n");
		const Animal* snoopy = new Dog();
		snoopy->makeSound();
		delete snoopy;
	}
	// dog copy
	{
		std::cout << cyn("============== Test[7]: Copy ============\n");
		Dog spot;
		Dog snoopy(spot);
	}
	// dog assignment
	{
		std::cout << cyn("=========== Test[8]: Assignment ==========\n");
		Dog spot;
		Dog snoopy;

		snoopy = spot;
		snoopy.makeSound();
	}

	// WrongCat
	{
		std::cout << cyn("======= Test[9]: (base) /(derived) =======\n");
		const WrongAnimal* garfield = new WrongCat();
		garfield->makeSound();
		delete garfield;
	}
	// cat copy
	{
		std::cout << cyn("============== Test[10]: Copy ============\n");
		WrongCat felix;
		WrongCat garfield(felix);
		garfield.makeSound();
	}
	// cat assignment
	// Direct call on WrongCat object → static binding.
	// Non-virtual only affects calls through base-class pointers,
	// so WrongCat::makeSound() is used here.
	{
		std::cout << cyn("=========== Test[11]: Assignment ==========\n");
		WrongCat felix;
		WrongCat garfield;

		garfield = felix;
		garfield.makeSound();

		WrongAnimal dog;
		dog.makeSound();
	}
*/
}
