#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal 
{
	protected:
		std::string type;

	public:
		Animal();
		Animal(const Animal& newAnimal);
		virtual ~Animal();
		Animal& operator=(const Animal& newAnimal);

		std::string	getType() const;
		virtual void makeSound() const;
};

#endif
