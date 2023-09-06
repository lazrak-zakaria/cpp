#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


void	fun()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << "\n";
	std::cout << i->getType() << "\n";
	//std::cout <<meta->getType() << "\n";
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	
	delete i;
	delete j;
	delete meta;
}

void	fun1()
{
	{
		Animal a;
		Animal b(a);
		Animal c;
		c = a;

		std::cout << c.getType() << "\n";
	}
	std::cout << "\n";
	{
		Cat a;
		Cat b(a);
		Cat c;
		c = a;
	
		std::cout << c.getType() << "\n";
	}
	std::cout << "\n";
	{
		Dog a;
		Dog b(a);
		Dog c;
		c = a;
	
		std::cout << c.getType() << "\n";
	}
}

int main()
{
	fun();
	//system("leaks ex00");
	return 0;
}