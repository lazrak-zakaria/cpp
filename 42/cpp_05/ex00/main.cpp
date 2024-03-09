#include "Bureaucrat.hpp"


int main(void)
{
    try
    {
        Bureaucrat a("laz", 150);
        a.gradeDecrement();
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << "\n\n";
    }    

    try
    {
        Bureaucrat a("laz", 1);
        a.gradeIncrement();
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << "\n\n";
    }

    try
    {
        Bureaucrat a("laz", 0);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << "\n\n";
    }

    try
    {
        Bureaucrat a("laz", 151);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << "\n\n";
    }

    try
    {
        Bureaucrat a("laz", 149);
        a.gradeDecrement();
        std::cout << a << "\n";
        a.gradeIncrement();
        std::cout << a << "\n";

        Bureaucrat b(a);
        std::cout << b << "\n";
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << "\n";
    }
    return 0;
}