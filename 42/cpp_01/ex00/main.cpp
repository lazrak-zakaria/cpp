#include "Zombie.hpp"

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

int main()
{
	Zombie	zombie("test_1");

	Zombie* newzombie = newZombie("test_2");

	randomChump("test_3");

	newzombie->announce();
	delete newzombie;
	zombie.announce();
	return (0);
}