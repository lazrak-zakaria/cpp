#include "find_replace.hpp"

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "The program takes three arguments\n";
		return (0);
	}
	if (!find_replace(av[1], av[2], av[3]))
		return (1);
	return (0);
}