#include "ClapTrap.hpp"
#include "Logger.hpp"
#include "colors.hpp"
#include <iostream>
#include <sstream>

ClapTrap::ClapTrap() : 
	_name("Default"),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0)
{
	LOG_INFO("Default Constructor called");
	
	std::ostringstream oss;
	oss << _name << '\n' 
		<< yel("Hit Points:    ") << _hitPoints << '\n'
		<< yel("Energy Points: ") << _energyPoints << '\n'
		<< yel("Attack Damage: ") << _attackDamage;

	LOG_DEBUG(oss.str());
}

ClapTrap::ClapTrap(const std::string& name) :
	_name(name),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0)
{
	LOG_INFO("Constructor called");

	std::ostringstream oss;
	oss << _name << '\n'
		<< yel("Hit Points:    ") << _hitPoints << '\n'
		<< yel("Energy Points: ") << _energyPoints << '\n'
		<< yel("Attack Damage: ") << _attackDamage;

	LOG_DEBUG(oss.str());
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	LOG_INFO("Copy constructor called");

	*this = other;

	std::ostringstream oss;
	oss << _name << '\n'
		<< yel("Hit Points:    ") << _hitPoints << '\n'
		<< yel("Energy Points: ") << _energyPoints << '\n'
		<< yel("Attack Damage: ") << _attackDamage;

	LOG_DEBUG(oss.str());
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	else
		LOG_WARNING("Self-Assignment ignored");
	return (*this);
}

ClapTrap::~ClapTrap()
{
	LOG_INFO("Destructor Called");
}

unsigned int ClapTrap::getHitPoints() const
{
	return (_hitPoints);
}

unsigned int ClapTrap::getEnergyPoints() const
{
	return (_energyPoints);
}

unsigned int ClapTrap::getAttackDamage() const
{
	return (_attackDamage);
}


//Logger::Logger(const std::string& name) : _name(name)
