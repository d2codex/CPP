#include "Cure.hpp"
#include "Logger.hpp"
#include "colors.hpp"

Cure::Cure() : AMateria("cure")
{
	LOG_INFO() << "Cure default constructor called";
	LOG_DEBUG() << "Materia type: " << _type;
	LOG_DEBUG() << "Address: " << this;
}

Cure::Cure(const Cure& other) : AMateria(other)
{
	LOG_INFO() << "Cure copy constructor called";
	LOG_DEBUG() << "Materia type: " << _type;
	LOG_DEBUG() << "Address: " << this;
}

Cure& Cure::operator=(const Cure& other)
{
	if (this != &other)
	{
		AMateria::operator=(other);
		_type = other._type;
	}
	else
		LOG_WARNING() << "Cure self-assignment ignored";		
	LOG_INFO() << "Cure assignment operator called";
	LOG_DEBUG() << "Materia Type: " << _type;
	LOG_DEBUG() << "Address: " << this;
	return (*this);	
}

Cure::~Cure()
{
	LOG_INFO() << "Cure destructor called";
}

AMateria* Cure::clone() const
{
	Cure* clone = new Cure(*this);
	return (clone);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target << "'s wounds *\n";
}
