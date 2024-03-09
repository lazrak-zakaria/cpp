#include <iostream>
#include <string>

void	print_(std::string a)
{
	int i = 0;
	while (a[i])
	{
		std::cout << (char)(std::toupper(a[i]));
		++i;
	}
}

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	int i = 1;
	while (i < ac)
		print_(av[i++]);
	std::cout << "\n";
	return (0);
}
