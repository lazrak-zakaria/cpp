#include "Dog.hpp"

Dog::Dog() 
{
	type = "Dog";
	br = new Brain();
	std::cout << "Dog Default constructor\n";
}

Dog::Dog(const Dog & newDog)
{
	std::cout << "Dog copy constructor\n";
	br = NULL;
	*this = newDog;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor\n";
	delete br;
}

Dog& Dog::operator=(const Dog &newDog)
{
	std::cout << "Dog Copy assignment operator\n";
	if (this == &newDog)
		return (*this);
	type = newDog.type;
	if (br)
		delete br;
	br = new Brain();
	for (int j = 0; j < 100; ++j)
		br->setIdea(newDog.br->getIdea(j), j);
	return (*this);
}

void	Dog::makeSound()const
{
	std::cout << "Dog sound\n";
}