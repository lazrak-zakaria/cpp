#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

void    test()
{
    AForm* a = new ShrubberyCreationForm("[T]");
    if (!a) return;

    AForm* b = new RobotomyRequestForm("[T]");
    if (!b) { delete a; return ;}

    AForm* c = new PresidentialPardonForm("[T]");
    if (!c) { delete a; delete b; return ;}


    std::cout << *a << "\n";
    std::cout << *b << "\n";
    std::cout << *c << "\n";

    delete a;
    delete b;
    delete c;
}


int main(void)
{
    test();
    AForm* f = new ShrubberyCreationForm("[S]");
    if (!f) return 0;
    try
    {
        Bureaucrat a("[F]" , 1);
        a.signForm(*f);
        a.executeForm(*f); 
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << "\n";
    }
    delete f;
    std::cout << "\n";


    f = new RobotomyRequestForm("[R]");
    if (!f) return 0;
    try
    {
        Bureaucrat a("[F]" , 7);
        a.signForm(*f);
        a.executeForm(*f); 
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << "\n";
    }
    delete f;
    std::cout << "\n";


    f = new PresidentialPardonForm("[P]");
    if (!f) return 0;
    try
    {
        Bureaucrat a("[F]" , 4);
        a.signForm(*f);
        a.executeForm(*f); 
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << "\n";
    }
    delete f;
    //system("leaks ex02");
    return 0;
}
