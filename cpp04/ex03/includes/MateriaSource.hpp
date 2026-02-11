#pragma once

#include "IMateriaSource.hpp"
#include <string>

class AMateria;

/**
 * @class MateriaSource
 * @brief Stores learned AMateria and can create copies on demand.
 *
 * Implements learning new Materia and creating them by type.
 */
class MateriaSource : public IMateriaSource
{
public:
	enum { MAX_SLOTS = 4};

	MateriaSource();
	MateriaSource(const MateriaSource& other);
	MateriaSource& operator=(const MateriaSource& other);
	~MateriaSource();

	void learnMateria(AMateria*);
	AMateria* createMateria(const std::string& type);

private:
	AMateria* _spellbook[MAX_SLOTS];
};
