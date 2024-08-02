#include <iostream>
#include "Array.hpp"

void test()
{
    try
    {
        Array<int> a(20);
        for (size_t i = 0; i < a.size(); ++i)
            a[i] = i + 1;
        Array<int> b(100);
        //b = a;
        for (size_t i = 0; i < b.size() + 1; ++i)
            std::cout << b[i] << "\n";
    }
    catch(std::exception & e )
    {
        std::cout << e.what() << "\n";
    }

    try
    {
        Array<std::string> arr(20);
        for (size_t i = 0; i < arr.size(); ++i)
            arr[i] = "####";
        Array<std::string> arr2(arr);
        for (size_t i = 0; i < arr2.size(); ++i)
            std::cout << arr2[i] << "\n";

        const Array<std::string> ARR(arr);
        std::cout << "\n" << ARR[0] << "\n";
        //ARR[0] = "@@@@"; read only
    }
    catch(std::exception & e )
    {
        std::cout << e.what() << "\n";
    }
}

int main()
{
    test();
}
