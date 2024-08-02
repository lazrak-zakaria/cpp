#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	name  = "[NAME ?]";
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
	std::cout<< "default constructor called\n";
}


ClapTrap::ClapTrap(const ClapTrap &newClapTrap)
{
	std::cout << "copy constructor called\n";
	*this = newClapTrap;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& newClapTrap)
{
	std::cout << "copy assignment called\n";
	name = newClapTrap.name;
	hitPoints = newClapTrap.hitPoints;
	energyPoints = newClapTrap.energyPoints;
	attackDamage  = newClapTrap.attackDamage;

	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " destructor\n";
}

ClapTrap::ClapTrap(std::string name)
{
	this->name  = name;
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
	std::cout<< "Parameterized constructor called\n";
}

void	ClapTrap::attack(const std::string &target)
{
	if (!hitPoints || !energyPoints)
	{
		std::cout << "ClapTrap "<< name << "  can’t do anything\n";
		return ;
	}
	--energyPoints;
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing "
				<< attackDamage << " points of damage!\n";
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	
	if (!hitPoints || !energyPoints)
	{
		std::cout << "ClapTrap "<< name << " can’t do anything\n";
		return ;
	}
	hitPoints = (amount >= hitPoints) ? 0 : (hitPoints - amount);
	std::cout << "ClapTrap " << name << " take " << amount << " of damage\n";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	
	if (!hitPoints || !energyPoints)
	{
		std::cout << "ClapTrap "<< name << " can’t do anything\n";
		return ;
	}
	--energyPoints;
	hitPoints += amount;
	std::cout << "ClapTrap " << name << " repaired with " << amount << " of hit points\n";
}
