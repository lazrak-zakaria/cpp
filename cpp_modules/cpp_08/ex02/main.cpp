#include "MutantStack.hpp"
#include <list>
#include <iostream>

void    test()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "size      " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << "  ";
        ++it;
    }
    std::cout << "\n";
    std::stack<int> s(mstack);
    MutantStack<int> ms__(mstack);
    
    it = ms__.begin();
    ite = ms__.end();
    while (it != ite)
    {
        std::cout << *it << "  ";
        ++it;
    }
    std::cout << "\n";
    ms__ = mstack;
    it = ms__.begin();
    while (it != ite)
    {
        std::cout << *it << "  ";
        ++it;
    }
    std::cout << "\n";
}

void test2()
{
    MutantStack<int> mstack;
    std::list<int> lst;
    for (int i = 0; i < 21; ++i)
    {
        mstack.push(i);
        lst.push_back(i);
    }
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    std::list<int>::iterator itl = lst.begin();
    std::list<int>::iterator itel = lst.end();
    for (; it != ite; ++it)
        std::cout << *it << " ";
    std::cout << "\n";
    for (; itl != itel; ++itl)
        std::cout << *itl << " ";
    std::cout << "\n";

}

int main()
{
    test();
    std::cout << "\n";
    test2();
return 0;
}