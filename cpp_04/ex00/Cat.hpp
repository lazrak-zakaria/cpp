#ifndef Cat_HPP
#define Cat_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat& newCat);
		~Cat();
		Cat& operator=(const Cat& newCat);
		void makeSound()const;
};

#endif
