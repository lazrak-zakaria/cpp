#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) 
			:  weapon(weapon) , name(name)
{}

// HumanA::HumanA(std::string name, Weapon &weapon)  compilation error
// {			this->weapon = (weapon);
// 			 this->name =(name);
// }


void	HumanA::attack(void)
{
	std::cout << this->name;
	std::cout << " attacks with their ";
	std::cout << this->weapon.getType() << "\n";
}

HumanA::~HumanA()
{
	//std::cout << "humanA destructor\n";
	
}