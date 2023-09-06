#ifndef WrongCat_HPP
#define WrongCat_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat& newWrongCat);
		~WrongCat();
		WrongCat& operator=(const WrongCat& newWrongCat);
		void makeSound()const;
};

#endif
