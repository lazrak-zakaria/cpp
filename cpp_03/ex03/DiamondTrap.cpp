#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout<< "DiamondTrap default constructor\n";
	this->name = "[NAME ?]";
	ClapTrap::name = this->name + "_clap_name";
	//ScavTrap::name = name + "_clap_name";
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 30;

	// std::cout << "FragTrap::energyPoints = " << FragTrap::energyPoints<< "\n";
	// std::cout << "ScavTrap::energyPoints = " << ScavTrap::energyPoints<< "\n";
}

DiamondTrap::DiamondTrap(std::string name)
{
	std::cout << "DiamondTrap parameter constructor\n";
	this->name = name;
	ClapTrap::name = name + "_clap_name";
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 30;
}

DiamondTrap::DiamondTrap( const DiamondTrap& newDiamondTrap)
{
	std::cout << "DiamondTrap copy constructor\n";
	*this = newDiamondTrap;	
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << name << " destructor\n";	
}

DiamondTrap& DiamondTrap::operator =( const DiamondTrap& newDiamondTrap)
{
	std::cout << "DiamondTrap copy assignment operator\n";
	this->name = newDiamondTrap.name;
	ClapTrap::name = newDiamondTrap.ClapTrap::name;
	hitPoints = newDiamondTrap.hitPoints;
	energyPoints = newDiamondTrap.energyPoints;
	attackDamage = newDiamondTrap.attackDamage;
	return (*this);
}

void	DiamondTrap::whoAmI()
{
	if (!hitPoints || !energyPoints)
	{
		std::cout << "DiamondTrap "<< name << " can’t do anything\n";
		return ;
	}
	std::cout << "ClapTrap name: " << ClapTrap::name
				<< " | DiamondTrap name: " << name << "\n";
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}
