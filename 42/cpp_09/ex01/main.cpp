#include "./RPN.hpp"

int main(int ac , char **av)
{
    try
    {
        if (ac != 2)
            throw std::runtime_error("Error: the program take only one argument.");
        RPN::calculate(av[1]);
    }
    catch(std::exception &e)
    {
        std::cout << "Error: "<< e.what() << "\n";
    }
    return 0;
}
