#ifndef WrongAnimal_HPP
#define WrongAnimal_HPP

#include <iostream>
#include <string>

class WrongAnimal 
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& newWrongAnimal);
		~WrongAnimal();
		WrongAnimal& operator=(const WrongAnimal& newWrongAnimal);

		std::string	getType() const;
		void makeSound() const;
};

#endif
