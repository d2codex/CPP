/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:01:58 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/25 00:32:27 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/**
 * @class Zombie
 * @brief Represents a single zombie with a name.
 *
 * The Zombie class supports announcing itself and can be used
 * as part of a dynamically allocated horde. In DEBUG mode,
 * construction and destruction are tracked with static counters.
 */
class Zombie
{
public:
	Zombie();
	~Zombie();

	void		announce(void);
	void		setZombieName(const std::string& name);
	std::string getName(void) const;

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

// free functions
int			promptSize();
std::string	promptName();
Zombie*		zombieHorde(int N, std::string name);

#endif
