#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
#include "AForm.hpp"
#include <stdlib.h>

class RobotomyRequestForm : public AForm
{
	private:
		std::string target;
	public:

		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &c);
		~RobotomyRequestForm();
		RobotomyRequestForm &operator=(const RobotomyRequestForm &a);

		RobotomyRequestForm(std::string target);
		void	execute(Bureaucrat const & executor) const ;
};

#endif
