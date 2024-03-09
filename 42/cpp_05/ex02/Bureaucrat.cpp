#include "./Bureaucrat.hpp"


Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& from) :
    name(from.name), grade(from.grade)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& from)
{
    grade = from.grade;
    return (*this);
}


Bureaucrat::Bureaucrat(std::string name, int grade) :
    name(name), grade(grade)
{
    if (grade > 150)
        throw GradeTooLowException();
    if (grade < 1)
        throw GradeTooHighException();
}

std::string Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

void    Bureaucrat::gradeIncrement()
{
    if (grade == 1)
        throw GradeTooHighException();
    --grade;
}

void    Bureaucrat::gradeDecrement()
{ 
    if (grade == 150)
        throw GradeTooLowException();
    ++grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade Too High";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade Too Low";
}


std::ostream&    operator <<(std::ostream &os, const Bureaucrat& b)
{
    std::cout << b.getName() << ", bureaucrat grade " << b.getGrade() << "."; 
    return os;
}



/*  ex01 */
void    Bureaucrat::signForm(AForm& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << "\n";
    }
    catch (std::exception &e)
    {
        std::cout << name << " couldn’t sign " << form.getName() << " because "
        << e.what() << "\n";
    }
}


/* ex02 */

void    Bureaucrat::executeForm(AForm const &form)
{
    try
    {
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << "\n";
    }
    catch (std::exception &e)
    {
        std::cout << form.getName() << " can not be executed because " 
                        << e.what() << "\n";
    }
}
