#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal Default constructor\n";
	type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal & newWrongAnimal)
{
	std::cout << "WrongAnimal copy constructor\n";
	*this = newWrongAnimal;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &newWrongAnimal)
{
	std::cout << "WrongAnimal Copy assignment operator\n";
	type = newWrongAnimal.type;
	return (*this);
}

std::string WrongAnimal::getType() const
{
	return (type);
}

void	WrongAnimal::makeSound()const
{
	std::cout << "WrongAnimal sound\n";
}
