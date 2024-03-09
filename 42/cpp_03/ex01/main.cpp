#include "ScavTrap.hpp"

int main()
{
	{
		ScavTrap	a("___Z__");
		std::cout << "\n";

		 a.takeDamage(9);
		for (int i = 0; i < 49; ++i)
		{
			std::cout << i+1 << " ";
			 a.attack("__W__");
		}
		a.takeDamage(91);
		a.beRepaired(91);

		a.beRepaired(2);
		a.guardGate();

	}

	// {
	// 	std::cout << "\n";
	// 	ScavTrap	a("__Z__");
	// 	ScavTrap	aa("__AA__");
	// 	ScavTrap	b(aa);
	// 	std::cout << "\n";

	// 	a.guardGate();
	// 	a.takeDamage(100);
	// 	b = a;
	// 	b.takeDamage(9);
	// 	b.beRepaired(2);
	// }

}