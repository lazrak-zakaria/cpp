#include "./Bureaucrat.hpp"
#include "./AForm.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./PresidentialPardonForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./Intern.hpp"



int main(void)
{
    Intern i;
    AForm* f = i.makeForm("ShrubberyCreationForm", "[S]");
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


    f = i.makeForm("RobotomyRequestForm", "[R]");
    if (!f) return 0;
    try
    {
        Bureaucrat a("[F]" , 77);
        a.signForm(*f);
        a.executeForm(*f); 
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << "\n";
    }
    delete f;
    std::cout << "\n";


    f = i.makeForm("PresidentialPardonForm", "[P]");
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
    std::cout << "\n";

    f = i.makeForm("PresidentialPardonFormKK", "[P]");
    if (!f) {std::cout << "Ok\n";}
    f = i.makeForm("bla", "[P]");
    if (!f) {std::cout << "Ok\n";}
    //system("leaks ex03");
    return 0;
}
