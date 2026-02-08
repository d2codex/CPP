#include "Cat.hpp"
#include "Logger.hpp"
#include "colors.hpp"
#include <iostream>

Cat::Cat() : Animal("cat")
{
	LOG_INFO() << "Cat default constructor called";
	LOG_DEBUG() << "Animal type: " << _type;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	LOG_INFO() << "Cat copy constructor called";
	LOG_DEBUG() << "Animal type: " << _type;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other); // update derived class
	}
	else
		LOG_WARNING() << "Cat self-assignment ignored";
	LOG_INFO() << "Cat assignment constructor called";
	LOG_DEBUG() << "Animal type: " << _type;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "meow meow purr purr\n";
	LOG_DEBUG() << "Animal type: " << _type;
}

Cat::~Cat()
{
	LOG_INFO() << "Cat destructor called";
}
