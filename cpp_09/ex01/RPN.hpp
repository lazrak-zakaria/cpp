#ifndef RPN__
#define RPN__

#include <iostream>
#include <string>
#include <stack>


class RPN
{
    private:
        static bool    is_digit(std::string &s);
        RPN();
        ~RPN();
        RPN(const RPN&);
        RPN& operator = (const RPN&);
    public:
        static void    calculate(std::string s);
};

#endif