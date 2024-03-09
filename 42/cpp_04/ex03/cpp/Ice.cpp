#include "../Ice.hpp"

Ice::Ice()
{
	type = "ice";
	//std::cout << "Ice Defaul constructor\n";
}

Ice::Ice(const Ice &newIce)
{
	//std::cout << "Ice copy constructor\n";
	*this = newIce;
}

Ice& Ice::operator =(const Ice &newIce)
{
	//std::cout << "Ice copy assignement operator\n";
	type = newIce.type;
	return *this;
}

Ice::~Ice()
{
	//std::cout << "Ice Destructor\n";
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at "
				<< target.getName() << " *\n";
}

Ice*	Ice::clone() const
{
	Ice *answer = new Ice();
	return (answer);	
}
