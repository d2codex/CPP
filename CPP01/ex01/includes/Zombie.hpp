#ifndef ZOMBIE_H
#define ZOMBIE_H

#ifdef DEBUG
#define DBUG(x) x
#else
#define DBUG(x)
#endif

#include <string>

#define MAX_HORDE_SIZE 1000000
#define DISPLAY_LIMIT 5

class Zombie
{
public:
	Zombie();
	~Zombie();

	void announce(void);
	void setZombieName(const std::string& name);

	#ifdef DEBUG
	static void resetCounters();
	#endif

private:
	std::string _name;

	#ifdef DEBUG
	static int	s_constructed;
	static int	s_destroyed;
	#endif
};

Zombie* zombieHorde(int N, std::string name);

#endif
