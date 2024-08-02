#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constuctor\n";
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 20;
}

FragTrap::FragTrap(const FragTrap& newFragTrap)
{
	std::cout << "FragTrap copy constructor\n";
	*this = newFragTrap;
}

FragTrap &FragTrap::operator =(const FragTrap& newFragTrap)
{
	std::cout << "FragTrap copy assignement operator\n";
	name = newFragTrap.name;
	hitPoints = newFragTrap.hitPoints;
	energyPoints = newFragTrap.energyPoints;
	attackDamage = newFragTrap.attackDamage;

	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " destructor\n";
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "FragTrap parameter constructor\n";
	this->name = name;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

void  FragTrap::highFivesGuys(void)
{
	if (!hitPoints || !energyPoints)
	{
		std::cout << "FragTrap "<< name << " can’t do anything\n";
		return ;
	}
	std::cout << "FragTrap " << name << " high fives.\n";
}
