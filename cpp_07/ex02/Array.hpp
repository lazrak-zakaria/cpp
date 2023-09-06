#include <iostream>
#include <exception>


template<typename T>
class Array
{   
    private:
        T*      head;
        size_t N;
    public:
        Array()
        {
// https://stackoverflow.com/questions/1087042/c-new-int0-will-it-allocate-memory
            head = new T[0]();
            N = 0;
        }
        ~Array()
        {
            delete []head;
        };

        Array(const Array& from) : head(NULL), N(0)
        {
            if (this == &from)
                return ;
            *this = from;
        }
    
        Array &operator = (const Array& from)
        {
            if (head)
                delete []head;
            N = from.N;
            head = new T[N];
            for (size_t i = 0; i < N; ++i)
                head[i] = from[i];
            return *this;
        }

        Array(size_t i)
        {
            head = new T[i]();
            N = i;
        }

        T& operator[](size_t i)
        {
            // https://cplusplus.com/reference/array/array/operator[]/
            if (i >= N)
                throw std::out_of_range("out of range");
            return head[i];
        }
        
        const T& operator[](size_t i) const // copy constructor // const objects
        {
            if (i >= N)
                throw std::out_of_range("out of range");
            return head[i];
        }

        size_t  size(void)
        {
            return N;
        }
};
