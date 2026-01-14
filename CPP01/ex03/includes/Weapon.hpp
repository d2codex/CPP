#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
public:
	Weapon(std::string weaponName);

	//setter
	void setType(const std::string& name);

	//getter
	const std::string& getType() const;

private:
	std::string _type;
};

#endif
