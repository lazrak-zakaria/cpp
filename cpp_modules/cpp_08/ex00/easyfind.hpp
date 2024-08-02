#ifndef EAS
#define EAS

template<typename T>
typename T::iterator easyfind(T &c, int s)
{
    typename T::iterator it;
    for (it = c.begin(); it != c.end(); ++it)
        if (*it == s)
            break ;
    return it;
}

#endif
