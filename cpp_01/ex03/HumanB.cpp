#include "HumanB.hpp"

HumanB::HumanB(std::string name) : weapon (NULL) , name(name)
{}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack(void)
{
	if (this->weapon == NULL)
	{
		std::cout << this->name;
		std::cout << " does not have a weapon\n";
		return ;
	}
	std::cout << this->name;
	std::cout << " attacks with their ";
	std::cout << this->weapon->getType() << "\n";
}

HumanB::~HumanB()
{
	//std::cout << "humanb destructor\n";
}