#pragma once

#include <string>

class WrongAnimal
{
public:
	WrongAnimal();
	WrongAnimal(const std::string& type);
	WrongAnimal(const WrongAnimal& other);
	WrongAnimal& operator=(const WrongAnimal& other);
	virtual ~WrongAnimal();

	const std::string getType() const;
	void makeSound() const;

protected:
	std::string _type;
};
