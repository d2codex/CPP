#include "Cat.hpp"
#include "Logger.hpp"
#include "colors.hpp"
#include <iostream>

Cat::Cat() : Animal("cat"), _brain(new Brain())
{
	LOG_INFO() << "Cat default constructor called";
	LOG_DEBUG() << "Animal type: " << _type;
	LOG_DEBUG() << "Address: " << _brain;
}

Cat::Cat(const Cat& other) : Animal(other), _brain(new Brain(*other._brain))
{
	LOG_INFO() << "Cat copy constructor called";
	LOG_DEBUG() << "Animal type: " << _type;
	LOG_DEBUG() << "Address: " << _brain;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other); // update derived class
		*_brain = *other._brain;
	}
	else
		LOG_WARNING() << "Cat self-assignment ignored";
	LOG_INFO() << "Cat assignment constructor called";
	LOG_DEBUG() << "Animal type: " << _type;
	LOG_DEBUG() << "Address: " << _brain;
	return (*this);
}

std::string Cat::getIdeaAtIndex(size_t index) const
{
	return (_brain->getIdeaAtIndex(index));
}

void Cat::setIdeaAtIndex(const std::string& idea, size_t index)
{
	_brain->setIdeaAtIndex(idea, index);
}

void Cat::makeSound() const
{
	std::cout << "meow meow purr purr\n";
	LOG_DEBUG() << "Animal type: " << _type;
}

Cat::~Cat()
{
	LOG_DEBUG() << "Deleting brain at " << _brain;
	delete _brain;
	LOG_INFO() << "Cat destructor called";
}
