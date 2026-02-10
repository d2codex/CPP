#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Logger.hpp"
#include "colors.hpp"

MateriaSource::MateriaSource()
{
	for (size_t i = 0; i < MAX_SLOTS; i++)
	{
		_spellbook[i] = NULL;
	}
	LOG_INFO() << "MateriaSource default constructor called";
	LOG_DEBUG() << "Address: " << this;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (size_t i = 0; i < MAX_SLOTS; i++)
		_spellbook[i] = NULL;

	for (size_t i = 0; i < MAX_SLOTS; i++)
	{
		if (other._spellbook[i] != NULL)
			_spellbook[i] = other._spellbook[i]->clone();
	}
	LOG_INFO() << "MateriaSource copy constructor called";
	LOG_DEBUG() << "Address: " << this;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for (size_t i = 0; i < MAX_SLOTS; i++)
		{
			if (_spellbook[i] != NULL)
			{
				delete _spellbook[i];
				_spellbook[i] = NULL;
			}
			if (other._spellbook[i] != NULL)
				_spellbook[i] = other._spellbook[i]->clone();
		}
	}
	else
		LOG_WARNING() << "MateriaSource self-assignment ignored";
	LOG_INFO() << "MateriaSource assignment operator called";
	LOG_DEBUG() << "Address: " << this;
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < MAX_SLOTS; i++)
	{
		if (_spellbook[i] != NULL)
		{
			LOG_DEBUG() << "Deleting materia at " << _spellbook[i];
			delete _spellbook[i];
			_spellbook[i] = NULL;
		}
	}
	LOG_INFO() << "MateriaSource destructor called";
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
	{
		LOG_WARNING() << mag("[learnMateria] Materia not found");
		return ;
	}
	for (size_t i = 0; i < MAX_SLOTS; i++)
	{
		if (_spellbook[i] == NULL)
		{
			_spellbook[i] = m;
			LOG_INFO() << BLU << m->getType() << " materia learned!" << RESET;
			return ;
		}
	}
	LOG_WARNING() << mag("Spellbook full. You cannot learn anymore spells.");
	delete m;
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
	for (size_t i = 0; i < MAX_SLOTS; i++)
	{
		if (_spellbook[i] && _spellbook[i]->getType() == type)
		{
			AMateria* materia = _spellbook[i]->clone();
			LOG_INFO() << blu("A Materia has magically appeared!");
			return (materia);
		}
	}
	LOG_WARNING() << MAG << "[createMateria] Materia of type "
				  << type << " not learned!" << RESET;
	return (NULL);
}
