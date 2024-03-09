#include "WrongCat.hpp"

WrongCat::WrongCat() 
{
	type = "WrongCat";
	std::cout << "WrongCat Default constructor\n";
}

WrongCat::WrongCat(const WrongCat & newWrongCat)
{
	std::cout << "WrongCat copy constructor\n";
	*this = newWrongCat;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor\n";
}

WrongCat& WrongCat::operator=(const WrongCat &newWrongCat)
{
	std::cout << "WrongCat Copy assignment operator\n";
	type = newWrongCat.type;
	return (*this);
}

void	WrongCat::makeSound()const
{
	std::cout << "WrongCat sound\n";
}
