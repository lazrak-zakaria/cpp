#ifndef HUMAN_B_HPP__
#define HUMAN_B_HPP__

#include <string>
#include <iostream>

#include "Weapon.hpp"

class HumanB
{
	private:
		Weapon*	weapon;
		std::string name;
		HumanB(void);
	public:
		HumanB(std::string name); // HumanB doesn’t take the Weapon in its constructor
		void		attack(void);
		void		setWeapon(Weapon	&weapon);
		~HumanB();
};

#endif