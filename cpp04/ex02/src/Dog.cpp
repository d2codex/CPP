#include "Dog.hpp"
#include "Logger.hpp"
#include "colors.hpp"
#include <iostream>

Dog::Dog() : AAnimal("dog"), _brain(new Brain())
{
	LOG_INFO() << "Dog default constructor called";
	LOG_DEBUG() << "AAnimal type: " << _type;
	LOG_DEBUG() << "Address: " << _brain;
}

Dog::Dog(const Dog& other) : AAnimal(other), _brain(new Brain(*other._brain))
{
	LOG_INFO() << "Dog copy constructor called";
	LOG_DEBUG() << "AAnimal type: " << _type;
	LOG_DEBUG() << "Address: " << _brain;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		AAnimal::operator=(other);
		*_brain = *other._brain;
	}
	else
		LOG_WARNING() << "Dog self-assignment ignored";
	LOG_INFO() << "Dog assignment constructor called";
	LOG_DEBUG() << "AAnimal type: " << _type;
	LOG_DEBUG() << "Address: " << _brain;
	return (*this);
}

std::string Dog::getIdeaAtIndex(size_t index) const
{
	return (_brain->getIdeaAtIndex(index));
}

void Dog::setIdeaAtIndex(const std::string& idea, size_t index)
{
	_brain->setIdeaAtIndex(idea, index);
}

void Dog::makeSound() const
{
	std::cout << "woof woof bark bark\n";
	LOG_DEBUG() << "AAnimal type " << _type;
}

Dog::~Dog()
{
	LOG_DEBUG() << "Deleting brain at " << _brain;
	delete _brain;
	LOG_INFO() << "Dog destructor called";
}
