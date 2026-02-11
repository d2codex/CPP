/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 11:06:19 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/11 11:06:20 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	// test deep copy (just for extra added assurance)
	{
		std::cout << cyn("=========== Test[12]: Deep Copy ==========\n");
		int	index = 5;
		Dog spot;
		spot.setIdeaAtIndex("kibbles and bits", index);
		Dog snoopy(spot);

		std::cout << "Before mutation:\n";
		std::cout << "spot[" << index << "]: "
				  << spot.getIdeaAtIndex(index) << std::endl;
		std::cout << "snoopy[" << index << "]: "
				  << snoopy.getIdeaAtIndex(index) << std::endl;

		//mutate original
		spot.setIdeaAtIndex("belly rub", index);

		std::cout << "After mutation:\n";
		std::cout << "spot[" << index << "]: "
				  << spot.getIdeaAtIndex(index) << std::endl;
		std::cout << "snoopy[" << index<< "]: "
				  << snoopy.getIdeaAtIndex(index) << std::endl;
	}
	// deep copy assignment
	{
		std::cout << cyn("===== Test[13]: Deep Copy Assignment =====\n");
		int index = 77;
		Cat felix;
		felix.setIdeaAtIndex("ball of yarn", index);

		Cat kittens;
		kittens = felix;

		std::cout << "Before mutation:\n";
		std::cout << "kittens[" << index << "]: "
				  << kittens.getIdeaAtIndex(index) << std::endl;
		std::cout << "felix[" << index<< "]: "
				  << felix.getIdeaAtIndex(index) << std::endl;

		// mutate original
		felix.setIdeaAtIndex("I love fishes cause they're so delicious", index);

		std::cout << "After mutation:\n";
		std::cout << "kittens[" << index<< "]: "
				  << kittens.getIdeaAtIndex(index) << std::endl;
		std::cout << "felix[" << index << "]: "
				  << felix.getIdeaAtIndex(index) << std::endl;
	}
}
