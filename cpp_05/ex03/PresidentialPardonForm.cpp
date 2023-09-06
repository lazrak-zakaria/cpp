#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm()
				:  AForm("PresidentialPardonForm", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &from)
				 : AForm(from), target(from.target)
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &a)
{
	target = a.target;
	setIsSigned(a.getIsSigned());
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
				 : AForm("PresidentialPardonForm", 25, 5), target(target)
{
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!this->getIsSigned())
        throw AFormNotSignedException();
    if (executor.getGrade() > this->getGradeToExec())
        throw GradeTooLowException();
	std::cout << target << " has been pardoned by Zaphod Beeblebrox.\n";
}

