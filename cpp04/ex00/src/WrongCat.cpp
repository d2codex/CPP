#include "WrongCat.hpp"
#include "Logger.hpp"
#include "colors.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	LOG_INFO() << "WrongCat default constructor called";
	LOG_DEBUG() << "Animal type " << _type;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	LOG_INFO() << "WrongCat copy constructor called";
	LOG_DEBUG() << "Animal type " << _type;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
	{
		WrongAnimal::operator=(other);
	}
	else
		LOG_WARNING() << "WrongCat self-assignment ignored";
	LOG_INFO() << "WrongCat assignment constructor called";
	LOG_DEBUG() << "Animal type " << _type;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "meeeeeh\n";
	LOG_DEBUG() << "Animal type " << _type;
}

WrongCat::~WrongCat()
{
	LOG_INFO() << "WrongCat destructor called";
}
