#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &c)
{
	(void) c;
}

Intern::~Intern()
{
}

Intern & Intern::operator=(const Intern &a)
{
	(void) a;
	return *this;
}

AForm	*Intern::makeForm(std::string form, std::string target)
{
	std::string a[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	int i = 0;
	AForm *answer = NULL;
	while (form != a[i] && i < 3)
		++i;
	switch (i)
	{
		case 0 :
		{
			answer = new ShrubberyCreationForm(target);
			break ;
		}
		case 1 :
		{
			answer = new RobotomyRequestForm(target);
			break ;
		}
		case 2 :
			answer = new PresidentialPardonForm(target);
	}
	std::string b = (answer) ? "Intern creates " :  "Intern failed to create ";
	std::cout << b << form << "\n";
	return answer; 
}
