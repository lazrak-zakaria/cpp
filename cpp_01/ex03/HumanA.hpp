#ifndef HUMAN_A_HPP__
#define HUMAN_A_HPP__

#include <string>
#include <iostream>

#include "Weapon.hpp"

class HumanA
{
	private:
		Weapon	&weapon;
		std::string name;
		HumanA(void);
	public:
		HumanA(std::string name, Weapon	&weapon);
		void		attack(void);
		~HumanA();
};

#endif