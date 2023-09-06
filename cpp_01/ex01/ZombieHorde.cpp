#include "./Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie	*answer = new Zombie[N] ;
	if (!answer)
		return (NULL);
	for (int j = 0; j < N; ++j)
		answer[j].setName(name);
	return (answer);
}
