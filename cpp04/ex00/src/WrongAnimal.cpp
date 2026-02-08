#include "WrongAnimal.hpp"
#include "Logger.hpp"
#include "colors.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	LOG_INFO() << "WrongAnimal default constructor called";
	LOG_DEBUG() << "Animal type " << _type;
}

WrongAnimal::WrongAnimal(const std::string& type) : _type(type)
{
	LOG_INFO() << "WrongAnimal type constructor called";
	LOG_DEBUG() << "Animal type " << _type;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type)
{
	LOG_INFO() << "WrongAnimal copy constructor called";
	LOG_DEBUG() << "Animal type " << _type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	else
		LOG_WARNING() << "WrongAnimal self-assignment ignored";
	LOG_INFO() << "WrongAnimal assignment constructor called";
	LOG_DEBUG() << "Animal type " << _type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	LOG_INFO() << "WrongAnimal destructor called";
}

const std::string WrongAnimal::getType() const
{
	return (_type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "baaaaaaaa\n";
}
