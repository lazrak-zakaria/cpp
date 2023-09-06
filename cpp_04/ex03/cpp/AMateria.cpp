#include "../AMateria.hpp"

AMateria::AMateria()
{
	//std::cout << "AMateria Defaul constructor\n";
}

AMateria::AMateria(const AMateria &newAMateria)
{
	//std::cout << "AMateria copy constructor\n";
	*this = newAMateria;
}

AMateria& AMateria::operator =(const AMateria &newAMateria)
{
	//std::cout << "AMateria copy assignement operator\n";
	type = newAMateria.type;
	return *this;
}

AMateria::~AMateria()
{
	//std::cout << "AMateria Destructor\n";
}

AMateria::AMateria(std::string const& type)
{
	this->type = type;
}

std::string const& AMateria::getType() const
{
	return (type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* shoots " << target.getName() <<" *\n";
}
