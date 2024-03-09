#include "Span.hpp"

Span::Span() : n(0), i(0)
{
}

Span::~Span()
{
}

Span& Span::operator =(const Span& from)
{
    if (this != &from)
    {
        i = from.i;
        n = from.n;
        vec = from.vec;
    }
    return *this;
}

Span::Span(const Span& from) : vec(from.vec) ,n(from.n), i(from.i)
{
}


Span::Span(int n): n(n), i(0)
{
}

int Span::shortestSpan()
{
    if (i < 2)
        throw std::logic_error("no span can be found");
    std::vector<int> v2(vec);
    std::sort(v2.begin(), v2.end());
    int mn = v2[1] - v2[0];
    for (unsigned int j = 2; j < i; ++j)
        mn = std::min(mn, v2[j] - v2[j-1]);
    return (mn);
}

int Span::longestSpan()
{
    if (i < 2)
        throw std::logic_error("no span can be found");
    std::vector<int>::iterator mn , mx ;
    mn = std::min_element(vec.begin(), vec.end());
    mx = std::max_element(vec.begin(), vec.end());
    return (*mx - *mn);
}

void    Span::addNumber(int s)
{
    if (i == n)
        throw std::logic_error("full");
    vec.push_back(s);
    ++i;
}

void    Span::addRange(std::vector<int>::const_iterator first, std::vector<int>::const_iterator last)
{
    if (last - first > n - i)
        throw std::logic_error("cannot add this range");
    vec.insert(vec.end(), first, last);
    i += last - first;
}
