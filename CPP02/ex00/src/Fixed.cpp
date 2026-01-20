#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _fixedPoint(0)
{
	LOG_INFO("Default Constructor called");
    DBG(std::cout << YEL "[DBG] " RESET
			"Default fixedPoint initialized to " << _fixedPoint << '\n';)
}

Fixed::Fixed(const Fixed& other) //: _fixedPoint(other._fixedPoint)
{
	LOG_INFO("Copy constructor called");
	DBG(std::cout << YEL "[DBG] " RESET
				  << "Copy fixedPoint initialized to " << other._fixedPoint << '\n';)
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	//allows us to use '=' to copy one object to another
	//avoid overwriting ex: (a = a)
	//instead just return the pointer
	if (this != &other)
	{
		LOG_INFO("Copy assignment operator called");
		_fixedPoint = other.getRawBits();
	}
	else
		LOG_WARNING("Self-assignment ignored");
	return (*this);
}

Fixed::~Fixed()
{
	LOG_INFO("Destructor Called");
}

int	Fixed::getRawBits(void) const
{
	LOG_INFO("getRawBits member function called");
	DBG(std::cout << YEL "[DBG] " RESET
				  << "Raw bits: " << _fixedPoint << '\n';)

	return (_fixedPoint);
}

void	Fixed::setRawBits(int const raw)
{
	_fixedPoint = raw;
}
