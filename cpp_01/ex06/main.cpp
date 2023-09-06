#include <iostream>
#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Do you know Harl?\n";
		return (0);
	}
	Harl		h;
	std::string s = av[1];
	h.complain(s);

	return (0);
}
