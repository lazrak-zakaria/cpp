#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal Default constructor\n";
	type = "Animal";
}

Animal::Animal(const Animal & newAnimal)
{
	std::cout << "Animal copy constructor\n";
	*this = newAnimal;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor\n";
}

Animal& Animal::operator=(const Animal &newAnimal)
{
	std::cout << "Animal Copy assignment operator\n";
	type = newAnimal.type;
	return (*this);
}

std::string Animal::getType() const
{
	return (type);
}

void	Animal::makeSound()const
{
	std::cout << "Animal sound\n";
}
