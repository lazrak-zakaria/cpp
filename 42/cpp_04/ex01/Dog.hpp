#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
class Dog : public Animal
{
	private:
		Brain* br;
	public:
		Dog();
		Dog(const Dog& newDog);
		~Dog();
		Dog& operator=(const Dog& newDog);
		void makeSound() const;
};

#endif
