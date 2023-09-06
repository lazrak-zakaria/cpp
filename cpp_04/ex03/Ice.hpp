#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
	private:
	public:
		Ice();
		Ice(const Ice& i);
		Ice& operator=(const Ice& i);
		~Ice();

		void use(ICharacter& target);
		Ice*	clone() const;
};

#endif