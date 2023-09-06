
#include <iostream>

template <typename T, typename F>
void iter(T a, size_t l, F f)
{
    for (size_t i = 0; i < l ; ++i)
    {   
        f(a[i]);
    }
}

template <typename T>
void f(T h)
{
    std::cout << h << "\n"; 
}
