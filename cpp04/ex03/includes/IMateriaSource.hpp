#pragma once

#include <string>

class AMateria;

/**
 * @class IMateriaSource
 * @brief Interface for a Materia source that can learn and create Materia.
 *
 * Provides virtual functions to learn new Materia and create copies by type.
 */
class IMateriaSource
{
public:
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(const std::string& type) = 0;
	virtual ~IMateriaSource() {}
};
