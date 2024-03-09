#include "../Cure.hpp"

Cure::Cure()
{
	//std::cout << "Cure Defaul constructor\n";
	type = "cure";
}

Cure::Cure(const Cure &newCure)
{
	//std::cout << "Cure copy constructor\n";
	*this = newCure;
}

Cure& Cure::operator =(const Cure &newCure)
{
	//std::cout << "Cure copy assignement operator\n";
	type = newCure.type;
	return *this;
}

Cure::~Cure()
{
	//std::cout << "Cure Destructor\n";
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals "
				<< target.getName() << "'s wounds *\n";
}

Cure*	Cure::clone() const
{
	Cure *answer = new Cure();
	return (answer);	
}
