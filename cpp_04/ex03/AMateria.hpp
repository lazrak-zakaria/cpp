#ifndef AMATERIA_CPP
#define AMATERIA_CPP


#include <string>
#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string type;
	public:
		AMateria();
		AMateria(const AMateria &newAMateria);
		AMateria& operator=(const AMateria &newAMateria);
		virtual ~AMateria();

		AMateria(std::string const& type);
		std::string const &getType() const;
		virtual	AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif