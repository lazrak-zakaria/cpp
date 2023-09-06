#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constuctor\n";
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& newScavTrap)
{
	std::cout << "ScavTrap copy constructor\n";
	*this = newScavTrap;
}

ScavTrap &ScavTrap::operator =(const ScavTrap& newScavTrap)
{
	std::cout << "ScavTrap copy assignement operator\n";
	name = newScavTrap.name;
	hitPoints = newScavTrap.hitPoints;
	energyPoints = newScavTrap.energyPoints;
	attackDamage = newScavTrap.attackDamage;

	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap "<< name << " destructor\n";
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap parameter constructor\n";
	this->name = name;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

void  ScavTrap::guardGate()
{

	if (!hitPoints || !energyPoints)
	{
		std::cout << "ScavTrap "<< name << " can’t do anything\n";
		return ;
	}
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode.\n";
}

void	ScavTrap::attack(const std::string &target)
{
	if (!hitPoints || !energyPoints)
	{
		std::cout << "ScavTrap "<< name << "  can’t do anything\n";
		return ;
	}
	--energyPoints;
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing "
				<< attackDamage << " points of damage!\n";
}
