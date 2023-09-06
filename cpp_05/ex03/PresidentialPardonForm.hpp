#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &c);

		~PresidentialPardonForm();
		PresidentialPardonForm & operator=(const PresidentialPardonForm &a);
		


		PresidentialPardonForm(std::string target);
		void	execute(Bureaucrat const & executor) const;
		
};

#endif
