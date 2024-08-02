#ifndef SCAVTRAP__HPP__
#define SCAVTRAP__HPP__

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const ScavTrap& newScavTrap);
		ScavTrap& operator=(const ScavTrap& newScavTrap);
		~ScavTrap(); 	
		ScavTrap(std::string name);

		void	attack(const std::string &target);
		void	guardGate();
};



#endif