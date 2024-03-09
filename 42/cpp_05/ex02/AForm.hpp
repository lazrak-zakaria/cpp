#ifndef AForm_HPP__
#define AForm_HPP__

#include <iostream>
#include <string>
#include <exception>
#include <fstream>

class AForm;
#include "./Bureaucrat.hpp"

class AForm
{
    private:
        const std::string   name;
        const int           gradeToSign;
        const int           gradeToExec;
        bool                isSigned;
    public:
        AForm();
        virtual ~AForm();
        AForm(const AForm& f);
        AForm& operator=(const AForm& f);


        AForm(const std::string name, const int gradeToSign, const int gradeToExec);
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


        /*  ex02    */
    
        class AFormNotSignedException: public std::exception
        {
            public:
                const char* what() const throw();
        };

        void            setIsSigned(bool s);
        virtual void    execute(Bureaucrat const & executor) const = 0;
};

std::ostream&    operator <<(std::ostream &os, const AForm &b);

#endif