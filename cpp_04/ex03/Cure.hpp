#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
	private:
	public:
		Cure();
		Cure(const Cure& i);
		Cure& operator=(const Cure& i);
		~Cure();
		
		
		void use(ICharacter& target);
		Cure*	clone() const;

};

#endif