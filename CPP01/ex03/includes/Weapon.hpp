#ifndef WEAPON_HPP
#define WEAPON_HPP

#ifdef DEBUG
#define DBUG(x) x
#else
#define DBUG(x)
#endif

#include <string>

class Weapon
{
public:
	Weapon(const std::string& type);

	//setter
	void setType(const std::string& type);

	//getter
	const std::string& getType() const;

private:
	std::string _type;
};

#endif
