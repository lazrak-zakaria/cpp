#ifndef CHARACTER_HPP__
# define CHARACTER_HPP__

#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria*	materias[4];
	public:
			
		Character();
		Character(const Character& c);
		Character& operator =(const Character& c);
		~Character(); // Of course, the Materias must be deleted when a Character is destroyed.

		Character(std::string name);

		std::string const& getName() const;
		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);
};



#endif 