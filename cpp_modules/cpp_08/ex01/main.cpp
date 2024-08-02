#include "Span.hpp"
#include <iostream>

void test_range()
{
    try
    {
        Span sp(10);
        std::vector<int> a;
        int i = 5;
        while (i--) a.push_back(i);
        sp.addNumber(40);
        sp.addRange(a.begin(), a.end());
        sp.addNumber(40);
        sp.addNumber(40);
        sp.addNumber(40);
        sp.addNumber(40);
//    sp.addNumber(40); //throw

//    sp.addRange(a.begin(), a.end()); //throw
        std::cout << "shortestSpan\t" << sp.longestSpan() << "\n";
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << "\n";
    }
}

int main()
{
    try
    {
        Span sp(20);
        int j = 10;
        while (j--) sp.addNumber(j);
        
        sp.addNumber(100);
        std::cout << "shortestSpan\t" << sp.shortestSpan() << "\n";
        std::cout << "longestSpan\t" <<sp.longestSpan() << "\n";
    }
    catch (std::exception &e)
    {
        std::cerr << e.what();
    }
    std::cout << "\n";

    try
    {
        Span sp(2);
        int j = 10;
        while (j--) sp.addNumber(j);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << "\n";
    }

    std::cout << "\n";

    try
    {
        Span sp(1);//(20);
        int j = 1;
        while (j--) sp.addNumber(j);
        std::cout << "shortestSpan\t" << sp.shortestSpan() << "\n";
        std::cout << "longestSpan\t" <<sp.longestSpan() << "\n";
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << "\n";
    }


    std::cout << "----------\n";
    try
    {
        Span sp(20000);
        int j = 1;
        while (j--) sp.addNumber(0);

        std::vector<int> vec;
        int i = 1;
        while (i < 11000) vec.push_back(i++);
    
        sp.addRange(vec.begin(), vec.end());
        std::cout << "shortestSpan\t" << sp.shortestSpan() << "\n";
        std::cout << "longestSpan\t" <<sp.longestSpan() << "\n";
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << "\n";
    }

    std::cout << "\ntest range\n";
    test_range();
    return 0;
}
