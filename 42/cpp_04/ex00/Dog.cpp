#include "Dog.hpp"

Dog::Dog() 
{
	type = "Dog";
	std::cout << "Dog Default constructor\n";
}

Dog::Dog(const Dog & newDog)
{
	std::cout << "Dog copy constructor\n";
	*this = newDog;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor\n";
}

Dog& Dog::operator=(const Dog &newDog)
{
	std::cout << "Dog Copy assignment operator\n";
	type = newDog.type;
	return (*this);
}

void	Dog::makeSound()const
{
	std::cout << "Dog sound\n";
}