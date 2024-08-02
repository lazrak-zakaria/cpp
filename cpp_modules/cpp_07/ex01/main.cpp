#include <iostream>
#include "iter.hpp"


int fun(int h)
{
    std::cout << h << "\n";
    return 0;
}

int main(void)
{

    int arr[] = {1, 2, 3, 4, 5};

    iter<int *, void (*)(int)>(arr, 5, f);
    std::cout << "\n";
    
    iter(arr, 5, f<int>);

    std::cout << "\n";

    iter(arr, 5, fun);

    std::cout << "\n";
    std::string s[] = {"AAA", "BBB", "CCC"};
    iter(s, 3, f<std::string>);


return 0;
}