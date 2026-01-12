#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#ifdef DEBUG
#define DBUG(x) x
#else
#define DBUG(x)
#endif

#include <string>

class Zombie
{
public:
	//constructor/destructor
	Zombie(std::string name);
	~Zombie();

	void	announce(void);

private:
	std::string _name;
};

// free functions
Zombie* newZombie(std::string name);
void	randomChump(std::string name);

#endif
