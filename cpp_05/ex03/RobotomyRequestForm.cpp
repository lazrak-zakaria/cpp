#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :  AForm("RobotomyRequestForm", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &from) : AForm(from), target(from.target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &a)
{
	target = a.target;
	setIsSigned(a.getIsSigned());
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{

    if (!this->getIsSigned())
        throw AFormNotSignedException();
    if (executor.getGrade() > this->getGradeToExec())
        throw GradeTooLowException();
	std::cout << "Making some drilling noises.\n";
	srand(time(NULL));
	if (rand() % 2)
		std::cout << target << " has been robotomized successfully\n";
	else 
	std::cout << "robotomy failed.\n";
}
