#include "FragTrap.hpp"

int main()
{
	// {
	// 	FragTrap	a("___Z__");
	// 	std::cout << "\n";

	// 	 a.takeDamage(9);
	// 	for (int i = 0; i < 99; ++i)
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
		std::cout << "\n";
		FragTrap	a("__Z__");
		FragTrap	aa("__AA__");
		FragTrap	b(aa);
		std::cout << "\n";

		a.highFivesGuys();

		a.takeDamage(100);
		b = a;
		b.takeDamage(9);
		b.beRepaired(2);
	}
return 0;
}