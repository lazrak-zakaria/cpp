#include "Cat.hpp"

Cat::Cat() 
{
	type = "Cat";
	std::cout << "Cat Default constructor\n";
}

Cat::Cat(const Cat & newCat)
{
	std::cout << "Cat copy constructor\n";
	*this = newCat;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor\n";
}

Cat& Cat::operator=(const Cat &newCat)
{
	std::cout << "Cat Copy assignment operator\n";
	type = newCat.type;
	return (*this);
}

void	Cat::makeSound()const
{
	std::cout << "Cat sound\n";
}
