#pragma once

#include <string>

class Animal
{
public:
	Animal();
	Animal(const std::string& type);
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
	// without virtual a derived class would call parent destructor
	// and not the herited class destructor causing leaks
	virtual ~Animal();

	const std::string getType() const;
	// virtual allows for inherited classes to call the most
	// derived function instead of base class function
	virtual void makeSound() const;

protected:
	std::string	_type;
};
