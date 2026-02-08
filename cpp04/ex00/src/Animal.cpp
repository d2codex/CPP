#include "Animal.hpp"
#include "Logger.hpp"
#include "colors.hpp"

Animal::Animal() : _type("unspecified")
{
	LOG_INFO() << "Animal default constructor called";
	LOG_DEBUG() << "Animal type: " << _type;
}

Animal::Animal(const std::string& type) : _type(type)
{
	LOG_INFO() << "Animal type constructor called";
	LOG_DEBUG() << "Animal type: " << _type;
}

Animal::Animal(const Animal& other) : _type(other._type)
{
	LOG_INFO() << "Animal copy constructor called";
	LOG_DEBUG() << "Animal type: " << _type;
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	else
		LOG_WARNING() << "Animal self-assignment ignored";
	LOG_INFO() << "Animal assignment constructor called";
	LOG_DEBUG() << "Assignment type: " << _type; 
	return (*this);
}

Animal::~Animal()
{
	LOG_INFO() << "Animal destructor called";
}

const std::string Animal::getType() const
{
	return (_type);
}

void Animal::makeSound() const
{
	std::cout << "!#$akd\n";
}
