#include "Serializer.hpp"

int main()
{
    Data a;

    a.firstName = "z";
    a.lastName = 'l';

    uintptr_t t = Serializer::serialize(&a);
    Data *w = Serializer::deserialize(t);

    if (&a == w)
    {
        std::cout << w->firstName << " ";
        std::cout << w->lastName << "\n";
    }
    
    return 0;
}
