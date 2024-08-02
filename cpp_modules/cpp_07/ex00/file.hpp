#ifndef __FILE_HPP__
#define __FILE_HPP__


template< typename T>
void swap(T & a, T& b)
{
    T t = a;
    a = b;
    b = t;
}

/*
When the compiler encounters the function call max<int>(1, 2), 
it will determine that a function definition for max<int>(int, int) does not already exist. Consequently, 
the compiler will use our max<T> function template to create one.
*/

template< typename T>
T max(T  a, T b)
{
    return (a > b ? a : b);
}

template< typename T>
T min(T  a, T b)
{
    return (a < b ? a : b);
}
#endif