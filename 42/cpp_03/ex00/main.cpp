#include "ClapTrap.hpp"

int main()
{
	{
		ClapTrap	a("___Z__");
		std::cout << "\n";

		 a.takeDamage(9);
		//a.takeDamage(10);
		for (int i = 0; i < 8; ++i)
		{
			std::cout << i+1 << " ";
			 a.attack("__W__");
		}
		a.beRepaired(9);
		a.takeDamage(9);

		a.beRepaired(2);
	}

	// {
	// 	std::cout << "\n";
	// 	ClapTrap	a("__Z__");
	// 	ClapTrap	aa("__AA__");
	// 	ClapTrap	b(aa);
	// 	std::cout << "\n";

	// 	a.takeDamage(10);
	// 	b = a;
	// 	b.takeDamage(9);
	// 	b.beRepaired(2);
	// }


}