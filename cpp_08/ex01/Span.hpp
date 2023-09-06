#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <exception>
#include <iostream>
#include <climits>
class Span
{
    private:
        std::vector<int> vec;
        unsigned int n;
        unsigned int i;
    public:
        Span();
        ~Span();
        Span& operator= (const Span&);
        Span(const Span&);

        Span(int);
        int shortestSpan();
        int longestSpan();
        void    addNumber(int s);
        void    addRange(std::vector<int>::const_iterator first, std::vector<int>::const_iterator last);

};

#endif