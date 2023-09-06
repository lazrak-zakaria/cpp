#include <iostream>
#include "Harl.hpp"

int main()
{
	Harl h;
	std::string s;
	while ('~')
	{
		getline(std::cin, s);
		if(std::cin.eof() || s.empty())
			return (0);
		h.complain(s);
	}
	// void (Harl::*funptr)(void);
	// funptr = &Harl::debug;
	// (h.*funptr)();
	return (0);
}