#ifndef FORM_HPP__
#define FORM_HPP__

#include <iostream>
#include <string>
#include <exception>


class Form;
#include "./Bureaucrat.hpp"

class Form
{
    private:
        const std::string   name;
        const int           gradeToSign;
        const int           gradeToExec;
        bool                isSigned;
    public:
        Form();
        ~Form();
        Form(const Form& f);
        Form& operator=(const Form& f);


        Form(const std::string name, const int gradeToSign, const int gradeToExec);
        std::string getName() const;
        int         getGradeToSign() const;
        int         getGradeToExec() const;
        bool        getIsSigned() const;

        void    beSigned(const Bureaucrat& b);

        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

std::ostream&    operator <<(std::ostream &os, const Form &b);
#endif