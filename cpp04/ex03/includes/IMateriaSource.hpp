#pragma once

#include <string>

class AMateria;

class IMateriaSource
{
public:
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(const std::string& type) = 0;
	virtual ~IMateriaSource() {}
};
