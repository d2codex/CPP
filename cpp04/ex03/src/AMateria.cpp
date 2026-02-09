#include "AMateria.hpp"
#include "Logger.hpp"
#include "colors.hpp"

AMateria::AMateria(const std::string& type) : _type(type)
{
	LOG_INFO() << "AMateria constructor called";
	LOG_DEBUG() << "Type: " << _type;
}

AMateria::AMateria(const AMateria& other) : _type(other._type)
{
	LOG_INFO() << "AMateria copy constructor called";
	LOG_DEBUG() << "Type: " << _type;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	if (this != &other)
		_type = other._type;
	else
		LOG_WARNING() << "AMateria self-assignment ignored";
	LOG_INFO() << "AMateria assignment operator called";
	LOG_DEBUG() << "Type: " << _type;
	return (*this);	
}

AMateria::~AMateria()
{
	LOG_INFO() << "AMateria destructor called";
}

const std::string& AMateria::getType() const
{
	return (_type);
}
