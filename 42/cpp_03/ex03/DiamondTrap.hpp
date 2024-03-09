#ifndef DIAMOND_TRAP
# define DIAMOND_TRAP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"


class DiamondTrap : public ScavTrap , public FragTrap
{
	private:
		std::string name;
	public:
		DiamondTrap();
		DiamondTrap(const DiamondTrap & newDiamondTrap);
		DiamondTrap& operator= (const DiamondTrap & newDiamondTrap);
		~DiamondTrap();
		DiamondTrap(std::string name);

		void	attack(const std::string &target);
		void	whoAmI();

};


#endif