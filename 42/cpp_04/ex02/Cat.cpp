#include "Cat.hpp"

Cat::Cat() 
{
	type = "Cat";
	br = new Brain();
	std::cout << "Cat Default constructor\n";
}

Cat::Cat(const Cat & newCat)
{
	std::cout << "Cat copy constructor\n";
	br = NULL;
	*this = newCat;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor\n";
	delete br;
}

Cat& Cat::operator=(const Cat &newCat)
{
	std::cout << "Cat Copy assignment operator\n";
	if (this == &newCat)
		return (*this);
	type = newCat.type;
	if (br)
		delete br;
	br = new Brain();
	for (int j = 0; j < 100; ++j)
		br->setIdea(newCat.br->getIdea(j), j);
	return (*this);
}

void	Cat::makeSound()const
{
	std::cout << "Cat sound\n";
}
