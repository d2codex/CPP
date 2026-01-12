/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 13:58:49 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/12 13:58:58 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
