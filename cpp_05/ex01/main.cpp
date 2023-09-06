#include "Bureaucrat.hpp"
#include "Form.hpp"


void    test()
{
    Form a("[FORM Z]", 3, 30);
    Form b(a);
    std::cout << b << "\n";
}

int main(void)
{
    test();
    try 
    {
        Bureaucrat b("[B]", 4);
        Form a("[FORM Z]", 3, 30);
        b.signForm(a);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << "\n";
    }

    std::cout << "\n";
    try 
    {
        Bureaucrat b("[B]", 4);
        Form a("[FORM Z]", 31, 30);
        b.signForm(a);
        std::cout << a << "\n";
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << "\n";
    }

    return 0;
}