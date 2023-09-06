#include "Form.hpp"

Form::Form() : name("Default"), gradeToSign(150), gradeToExec(150), isSigned(0)
{}

Form::Form(const Form &from) : name(from.name), gradeToSign(from.gradeToSign),
                            gradeToExec(from.gradeToExec),
                            isSigned(from.isSigned)
{}

Form::~Form()
{}

Form& Form::operator=(const Form& from)
{
    isSigned = from.isSigned;
    return (*this);
}

Form::Form(const std::string name, const int gradeToSign,
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

std::string Form::getName() const
{
    return (name);
}

int         Form::getGradeToSign() const
{
    return (gradeToSign);
}

int         Form::getGradeToExec() const
{
    return (gradeToExec);
}

bool        Form::getIsSigned() const
{
    return (isSigned);
}

void    Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}



const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade Too High";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade Too Low";
}

std::ostream&    operator <<(std::ostream &os, const Form &b)
{
    os << "name:\t\t\t" << b.getName() << "\n";
    os << "gradeToSign:\t\t" << b.getGradeToSign() << "\n";
    os << "gradeToExec:\t\t"<< b.getGradeToExec() << "\n";
    os << "isSigned:\t\t" << b.getIsSigned()<< "\n";
    return os;
}
