#include "AForm.hpp"

AForm::AForm() : name("Default"), gradeToSign(150), gradeToExec(150), isSigned(0)
{}

AForm::AForm(const AForm &from) : name(from.name), gradeToSign(from.gradeToSign),
                            gradeToExec(from.gradeToExec),
                            isSigned(from.isSigned)
{}

AForm::~AForm()
{}

AForm& AForm::operator=(const AForm& from)
{
    isSigned = from.isSigned;
    return (*this);
}

AForm::AForm(const std::string name, const int gradeToSign,
                 const int gradeToExec) :
        name(name),
        gradeToSign(gradeToSign),
        gradeToExec(gradeToExec), isSigned(0)
{
    if (this->gradeToExec < 1 || this->gradeToSign < 1)
        throw GradeTooHighException();
    if (this->gradeToExec > 150 || this->gradeToSign > 150)
        throw GradeTooLowException();
}

std::string AForm::getName() const
{
    return (name);
}

int         AForm::getGradeToSign() const
{
    return (gradeToSign);
}

int         AForm::getGradeToExec() const
{
    return (gradeToExec);
}

bool        AForm::getIsSigned() const
{
    return (isSigned);
}

void    AForm::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}



const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade Too High";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade Too Low";
}


/*  ex02    */

const char* AForm::AFormNotSignedException::what() const throw()
{
    return "The Form is Not Signed";
}

void    AForm::setIsSigned(bool s)
{
    isSigned = s;
}

std::ostream&    operator <<(std::ostream &os, const AForm &b)
{
    os << "name:\t\t" << b.getName() << "\n";
    os << "gradeToSign:\t\t" << b.getGradeToSign() << "\n";
    os << "gradeToExec:\t\t"<< b.getGradeToExec() << "\n";
    os << "isSigned:\t\t" << b.getIsSigned()<< "\n";
    return os;
}
