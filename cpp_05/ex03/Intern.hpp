#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"


class Intern
{
	private:
	public:
		Intern();
		Intern(const Intern &c);
		~Intern();
		Intern & operator=(const Intern &a);

		AForm*	makeForm(std::string form, std::string target);
		
};

#endif