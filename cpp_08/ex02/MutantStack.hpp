#ifndef MSTACK___
#define MSTACK___
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        // Aliased as member type stack::container_type.
        typedef typename std::stack<T>::container_type::iterator iterator;
        MutantStack(){}
        ~MutantStack(){}
        MutantStack(const MutantStack& s) : std::stack<T>(s)
        {}
        MutantStack& operator =(const MutantStack& a)
        {
            this->std::stack<T>::operator=(a);
            return *this;
        }

        /*
            Member objects
                Container c
	                the underlying container
                    (protected member object)
        */
        iterator    begin()
        {
            return this->std::stack<T>::c.begin();
        };
        iterator    end()
        {
            return this->std::stack<T>::c.end();
        };
};
#endif
