#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name);

void	fun()
{
	Zombie *z = zombieHorde(10, "TEST");
	if (!z)
		return ;
	for (int i = 0; i < 10; ++i)
	{
		z->announce();
	}
	delete []z;
}

int main()
{
	fun();
}
