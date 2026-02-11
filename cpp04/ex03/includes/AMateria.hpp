#pragma once

#include <string>

class ICharacter;

/**
 * @class AMateria
 * @brief Abstract base class representing a magical materia.
 *
 * Stores a type and provides interface for cloning and usage on a character.
 */
class AMateria
{
public:
	AMateria(const std::string& type);
	AMateria(const AMateria& other);
	AMateria& operator=(const AMateria& other);
	virtual ~AMateria();

	const std::string& getType() const;

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

protected:
	std::string _type;
};
