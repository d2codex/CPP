#include "Dog.hpp"
#include "Logger.hpp"
#include "colors.hpp"
#include <iostream>

Dog::Dog() : Animal("dog")
{
	LOG_INFO() << "Dog default constructor called";
	LOG_DEBUG() << "Animal type: " << _type;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	LOG_INFO() << "Dog copy constructor called";
	LOG_DEBUG() << "Animal type: " << _type;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	else
		LOG_WARNING() << "Dog self-assignment ignored";
	LOG_INFO() << "Dog assignment constructor called";
	LOG_DEBUG() << "Animal type: " << _type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "woof woof bark bark\n";
	LOG_DEBUG() << "Animal type " << _type;
}

Dog::~Dog()
{
	LOG_INFO() << "Dog destructor called";
}
