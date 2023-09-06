#ifndef __BUREAUCRAT__HPP__
#define __BUREAUCRAT__HPP__

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;
#include "Form.hpp"

class Bureaucrat
{
    private:
        const std::string   name;
        int                 grade;
    public:
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat& a);
        Bureaucrat& operator=(const Bureaucrat& from);

        Bureaucrat(const std::string name, int grade);
        std::string getName() const ;
        int         getGrade() const ;
        void        gradeIncrement();
        void        gradeDecrement();


        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw();
        };


        /*  ex01    */
        void    signForm(Form& form);
};

std::ostream&    operator <<(std::ostream &os, const Bureaucrat& b);

#endif