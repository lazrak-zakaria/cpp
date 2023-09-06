#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]\n";
	std::cout <<  "love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\n" 
				<< "I really do!\n";
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]\n";

	std::cout << "I cannot believe adding extra bacon costs more money.\n" 
		<<"You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]\n";
	std::cout <<  "think I deserve to have some extra bacon for free.\n"
				<< "I’ve been coming for years whereas you started working here since last month.\n";
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]\n";
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void	Harl::complain( std::string level )
{

	void (Harl::*funptr)(void);
	std::string arr[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	while (arr[i] != level && i < 4)
			++i;
	switch (i)
	{
		case (0):
			funptr = &Harl::debug;
			break ;
		case (1):
			funptr = &Harl::info;
			break ;
		case (2):
			funptr = &Harl::warning;
			break ;
		case (3):
			funptr = &Harl::error;
			break ;
		default :
			return ;
	}
	(this->*(funptr))();
}
