#ifndef CLAP_TRAP_HPP__
# define CLAP_TRAP_HPP__


#include <iostream>
#include <string>


class ClapTrap
{
	private:
		std::string		name;
		unsigned int	hitPoints;
		unsigned int	energyPoints;
		unsigned int	attackDamage;
	public:
		ClapTrap();
		ClapTrap(const ClapTrap &newClapTrap);
		ClapTrap& operator=(const ClapTrap& newClapTrap);
		~ClapTrap();

		ClapTrap(std::string name);
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};



#endif 