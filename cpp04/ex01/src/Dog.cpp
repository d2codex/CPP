#include "Dog.hpp"
#include "Logger.hpp"
#include "colors.hpp"
#include <iostream>

Dog::Dog() : Animal("dog"), _brain(new Brain())
{
	LOG_INFO() << "Dog default constructor called";
	LOG_DEBUG() << "Animal type: " << _type;
	LOG_DEBUG() << "Address: " << _brain;
}

Dog::Dog(const Dog& other) : Animal(other), _brain(new Brain(*other._brain))
{
	LOG_INFO() << "Dog copy constructor called";
	LOG_DEBUG() << "Animal type: " << _type;
	LOG_DEBUG() << "Address: " << _brain;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		*_brain = *other._brain;
	}
	else
		LOG_WARNING() << "Dog self-assignment ignored";
	LOG_INFO() << "Dog assignment constructor called";
	LOG_DEBUG() << "Animal type: " << _type;
	LOG_DEBUG() << "Address: " << _brain;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "woof woof bark bark\n";
	LOG_DEBUG() << "Animal type " << _type;
}

Dog::~Dog()
{
	LOG_DEBUG() << "Deleting brain at " << _brain;
	delete _brain;
	LOG_INFO() << "Dog destructor called";
}
