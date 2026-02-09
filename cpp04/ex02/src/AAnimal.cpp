#include "AAnimal.hpp"
#include "Logger.hpp"
#include "colors.hpp"

AAnimal::AAnimal() : _type("AAnimal")
{
	LOG_INFO() << "AAnimal default constructor called";
	LOG_DEBUG() << "AAnimal type: " << _type;
}

AAnimal::AAnimal(const std::string& type) : _type(type)
{
	LOG_INFO() << "AAnimal type constructor called";
	LOG_DEBUG() << "AAnimal type: " << _type;
}

AAnimal::AAnimal(const AAnimal& other) : _type(other._type)
{
	LOG_INFO() << "AAnimal copy constructor called";
	LOG_DEBUG() << "AAnimal type: " << _type;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	else
		LOG_WARNING() << "AAnimal self-assignment ignored";
	LOG_INFO() << "AAnimal assignment constructor called";
	LOG_DEBUG() << "Assignment type: " << _type; 
	return (*this);
}

AAnimal::~AAnimal()
{
	LOG_INFO() << "AAnimal destructor called";
}

const std::string AAnimal::getType() const
{
	return (_type);
}

void AAnimal::makeSound() const
{
	std::cout << "!#$akd\n";
	LOG_DEBUG() << "AAnimal type: " << _type;
}
