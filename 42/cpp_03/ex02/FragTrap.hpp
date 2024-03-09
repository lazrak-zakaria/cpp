#ifndef FragTrap__HPP__
#define FragTrap__HPP__

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const FragTrap& newFragTrap);
		FragTrap& operator=(const FragTrap& newFragTrap);
		~FragTrap(); 	
		FragTrap(std::string name);

		void	highFivesGuys(void);
};



#endif