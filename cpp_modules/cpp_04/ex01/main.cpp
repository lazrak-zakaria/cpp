#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void f()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j; //should not create a leak
	delete i;
}

void	c()
{
	const int N = 10;
	Animal *a[N];
	for (int i = 0; i < N; ++i)
	{
		if ((i < N/2))
			a[i] = new Dog();
		else
			a[i] = new Cat();
	}
	std::cout << "\n\n";
	for (int i = 0; i < N; ++i)
	{
		std :: cout << a[i]->getType() << " ";
	}
	std::cout << "\n\n";
	for (int i = 0; i < N; ++i)
		delete a[i];
}

void t()
{
	Dog a;
	Dog b;
	Dog c(b);
	
	// error: explicitly assigning value of variable of type 'Dog' to itself
	// a = a;
	b = a;
}

int main()
{
	f();
	//  c();
	//  t();
	//  system("leaks ex01");
return 0;
}