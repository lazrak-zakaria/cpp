#include <iostream>
#include <string>
#include <stdlib.h>

#include "Base.hpp"
#include "B.hpp"
#include "A.hpp"
#include "C.hpp"


Base *generate(void)
{
    srand(time(0));
    switch (rand()%3)
    {
        case 0 :        
            return reinterpret_cast<Base*> (new A());
        case 1 :        
            return reinterpret_cast<Base*> (new B());
        case 2 :        
            return reinterpret_cast<Base*> (new C());
    }
    return NULL;
}

/* dynamic_cast < type-id > ( expression ) */

void identify(Base* p)
{
    if (dynamic_cast<A*> (p))
        std::cout << "A\n";
    else if (dynamic_cast<B*> (p))
        std::cout << "B\n";
    else if (dynamic_cast<C*> (p))
        std::cout << "C\n";
}

void identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&> (p);
        std::cout << "A\n";
        (void)a;
        return ;
    }
    catch(const std::exception& e)
    {}

    try
    {
        B& a = dynamic_cast<B&> (p);
        (void)a;
        std::cout << "B\n";
        return ;
    }
    catch(const std::exception& e)
    {}

    try
    {
        C& a = dynamic_cast<C&> (p);
        (void)a;
        std::cout << "C\n";
    }
    catch(const std::exception& e)
    {}
}

int main()
{
    A a;
    B b;
    C c;

    Base* aa = dynamic_cast<Base*>(&a);
    B* k = static_cast<B*>(aa);
    if (!k) std::cout << "OK\n";
    identify(&a);
    identify(&b);
    identify(&c);

    std::cout << "\n";
    identify(a);
    identify(b);
    identify(c);

    std::cout << "\n";

    Base *p = generate();
    if (!p) return 0;
    identify(p);
    identify(*p);
    delete p;
    
    return 0;
}
