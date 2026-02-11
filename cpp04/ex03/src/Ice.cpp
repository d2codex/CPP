#include "Ice.hpp"
#include "Logger.hpp"
#include "colors.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice")
{
	LOG_INFO()  << "Ice default constructor called";
	LOG_DEBUG() << "Materia type: " << _type << '\n'
			    << "Address: " << this;
}

Ice::Ice(const Ice& other) : AMateria(other)
{
	LOG_INFO()  << "Ice copy constructor called";
	LOG_DEBUG() << "Materia type: " << _type << '\n'
			    << "Address: " << this;
}

Ice& Ice::operator=(const Ice& other)
{
	if (this != &other)
	{
		AMateria::operator=(other);
		_type = other._type;
	}
	else
		LOG_WARNING() << "Ice self-assignment ignored";		
	LOG_INFO()  << "Ice assignment operator called";
	LOG_DEBUG() << "Materia Type: " << _type << '\n'
				<< "Address: " << this;
	return (*this);	
}

Ice::~Ice()
{
	LOG_INFO() << "Ice destructor called";
}

AMateria* Ice::clone() const
{
	Ice* clone = new Ice(*this);
	return (clone);
}

void	Ice::use(ICharacter& target)
{
	std::cout << RED << "* shoots an ice bolt at "
			  << target.getName() << " *\n" << RESET;
}
