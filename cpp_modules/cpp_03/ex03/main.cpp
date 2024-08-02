#include "DiamondTrap.hpp"

int main()
{
	// {
	// 	DiamondTrap		a("___Z__");
	// 	std::cout << "\n";

	// 	 a.takeDamage(9);
	// 	for (int i = 0; i < 49; ++i)
	// 	{
	// 		std::cout << i+1 << " ";
	// 		 a.attack("__W__");
	// 	}
	// 	a.takeDamage(90);
	// 	a.beRepaired(91);

	// 	a.beRepaired(2);
	// 	a.highFivesGuys();

	// }

	{

		DiamondTrap		a("__Z__");
		DiamondTrap		aa("__AA__");
		DiamondTrap		b(aa);
		std::cout << "\n";

		a.highFivesGuys();
		a.guardGate();
		a.takeDamage(100);
		b = a;
		b.takeDamage(9);
		b.beRepaired(2);
		std::cout << "\n";
	}
return 0;
}