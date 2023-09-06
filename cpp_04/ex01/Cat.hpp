#ifndef Cat_HPP
# define Cat_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain* br;
	public:
		Cat();
		Cat(const Cat& newCat);
		~Cat();
		Cat& operator=(const Cat& newCat);
		void makeSound()const;
};

#endif
