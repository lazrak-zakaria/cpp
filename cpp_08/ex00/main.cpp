#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <set>


int main()
{
    std::vector<int> a;
    int i = 0;
    for (i = 0; i < 10; ++i)
        a.push_back(i);
    if (easyfind(a, 15) == a.end())
        std::cout << "OK not found\n";

    a.push_back(15);
    if (easyfind(a, 15) != a.end())
        std::cout << "OK found\n\n";

    std::list<int> b;
    for (i = 0; i < 10; ++i)
        b.push_back(i);

    if (easyfind(b, 15) == b.end())
        std::cout << "OK not found\n";

    b.push_back(15);
    if (easyfind(b, 15) != b.end())
        std::cout << "OK found\n";
    
}
