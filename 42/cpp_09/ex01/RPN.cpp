#include "RPN.hpp"
#include <climits>
#include <string.h>
#include <cstdlib> 
bool    RPN::is_digit(std::string &s)
{
    int i = 0;
    if (s[i] == '-' && !s[i+1])
        return 0;
    if (s[i] == '-')
        ++i;
    while (isdigit(s[i]))
        ++i;
    if (s[i])
        return 0;
    return 1;
}

void    RPN::calculate(std::string s)
{
    std::string tmp;
    long long c = 0;
    long long left = 0;
    long long right = 0;
    std::stack<int> stk;

    for (int i = 0; s[i]; ++i)
    {
        tmp = "";
        if (s[i] == ' ')
            throw std::runtime_error("Expression is not valid.");
        while (s[i] != ' ' && s[i])
            tmp += s[i++];

        if (is_digit(tmp))
        {
            c = atoll(tmp.c_str());
            if (c > INT_MAX || c < INT_MIN)
                throw std::runtime_error("Number is not valid.");
			size_t  j = 0;
			while (tmp[j] == '0') j++;
            if (tmp.substr(j).length() > 11)
                throw std::runtime_error("Number is not valid.");
            stk.push(c);
        }
        else if ((tmp == "-" || tmp == "+" || tmp == "/" || tmp == "*"))
        {
            if (stk.size() < 2)
                throw std::runtime_error("Expression is not valid.");
            right = stk.top();
            stk.pop();
            left = stk.top();
            stk.pop();
            switch (tmp[0])
            {
                case '+':
                    c = left + right;
                    break;
                case '-':
                    c = left - right;
                    break;
                case '*':
                    c = left * right;
                    break;
                case '/':
                    if (right == 0)
                        throw std::runtime_error("Attempted to divide by Zero.");
                    c = left / right;
                    break;
            }
            stk.push(c);
        }
        else
        {
            throw std::runtime_error("Expression is not valid.");
        }
        if (!s[i])
            break;
        if (!s[i+1]) 
            throw std::runtime_error("Expression is not valid.");
    }
    if (stk.size() != 1)
        throw std::runtime_error("Expression is not valid.");
    std::cout << stk.top() << "\n";
}

RPN::RPN(){}
RPN::~RPN(){}
RPN::RPN(const RPN& n){(void)n;}
RPN& RPN::operator = (const RPN& n){(void)n; return *this;}
