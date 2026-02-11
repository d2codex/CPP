#include "Cure.hpp"
#include "Logger.hpp"
#include "colors.hpp"

/**
 * @brief Default constructor; initializes as a "cure" AMateria.
 */
Cure::Cure() : AMateria("cure")
{
	LOG_INFO()  << "Cure default constructor called";
	LOG_DEBUG() << "Materia type: " << _type << '\n'
				<< "Address: " << this;
}

/**
 * @brief Copy constructor; copies another Cure object.
 */
Cure::Cure(const Cure& other) : AMateria(other)
{
	LOG_INFO()  << "Cure copy constructor called";
	LOG_DEBUG() << "Materia type: " << _type << '\n'
				<< "Address: " << this;
}

/**
 * @brief Assignment operator; copies another Cure object.
 * @return Reference to this Cure.
 */
Cure& Cure::operator=(const Cure& other)
{
	if (this != &other)
	{
		AMateria::operator=(other);
		_type = other._type;
	}
	else
		LOG_WARNING() << "Cure self-assignment ignored";
	LOG_INFO()  << "Cure assignment operator called";
	LOG_DEBUG() << "Materia Type: " << _type << '\n'
				<< "Address: " << this;
	return (*this);	
}

/**
 * @brief Destructor; cleans up the Cure object.
 */
Cure::~Cure()
{
	LOG_INFO() << "Cure destructor called";
}

/**
 * @brief Creates a new Cure object as a clone of this one.
 * @return Pointer to the cloned Cure.
 */
AMateria* Cure::clone() const
{
	Cure* clone = new Cure(*this);
	return (clone);
}

/**
 * @brief Uses the Cure on a target Character.
 * @param target Reference to target Character.
 */
void	Cure::use(ICharacter& target)
{
	std::cout << GRN << "* heals " << target.getName()
			  << "'s wounds *\n" << RESET;
}
