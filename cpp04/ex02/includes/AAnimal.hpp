#pragma once

#include <string>

class AAnimal
{
public:
	AAnimal(); // dont need
	AAnimal(const std::string& type); // cat and dog need this
	AAnimal(const AAnimal& other);
	AAnimal& operator=(const AAnimal& other);
	virtual ~AAnimal();

	const std::string getType() const;
	// to make animal uninstantiable make at least one function virtual
	// add '= 0'
	virtual void makeSound() const = 0;

protected:
	std::string	_type;
};
