#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);

		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}

	std::cout << "\n";
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		// what if does not have a weapon?
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}

	std::cout << "\n";
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		
		jim.attack();	//does not have a weapon
		
		jim.setWeapon(club);
		jim.attack();

		Weapon aa = Weapon("test club"); 
		jim.setWeapon(aa);
		jim.attack();
	}

	return 0;
}