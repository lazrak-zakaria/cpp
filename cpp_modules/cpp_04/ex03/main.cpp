#include "AMateria.hpp" 
#include "Character.hpp" 
#include "Cure.hpp" 
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"



void	test();
void	test1();
void 	test2();
void	test3();


int main()
{ 
	test();
	test1();
	test2();
	test3();
	//system("leaks ex03");
	return 0;
}





void	test()
{
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());      // learn new materia
	src->learnMateria(new Cure());		// // learn new materia

	ICharacter* me = new Character("me");     // player

	AMateria* tmp;							// 

	tmp = src->createMateria("ice");      
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");    // new player


	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);				// can't use 

	delete bob;
	delete me;
	delete src;
}

void test1()
{
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());      // learn new materia

	ICharacter* me = new Character("me");     // player

	AMateria* tmp;							

	tmp = src->createMateria("ice");      
	me->equip(tmp);
	tmp = src->createMateria("cure");    // the player did not learn this materia
	if (!tmp)
		std::cout << "the player did not learn this materia\n";
	me->equip(tmp);							//  equip NULL;

	ICharacter* bob = new Character("bob");    // new player


	me->use(0, *bob);
	me->use(1, *bob);				// can't use 
	me->use(2, *bob);				// can't use 

	delete bob;
	delete me;
	delete src;
}


void	test2()
{
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");   
	me->equip(tmp);
	me->use(0, *bob);
	//Save the addresses before calling unequip()  // tmp
	me->unequip(0);
	delete tmp;

	me->use(0, *bob);

	delete bob;
	delete me;
	delete src;

}

void	test3()
{
	{
		Character a("me");
		a.equip(new Ice());
		Character b;
		b = a;
		Character c(a);
		//std::cout << "++++++++++\n";	
	
		std::cout << a.getName() << "\n";
		std::cout << b.getName() << "\n";
		std::cout << c.getName() << "\n";
	}

	{
		MateriaSource a;
		a.learnMateria(new Ice());
 		MateriaSource b(a);
		b.learnMateria(new Cure());
		b.learnMateria(new Cure());

		AMateria *m1 = b.createMateria("cure");
		if (m1)   // expected   !NULL
		{
			std::cout << "Yes\n";
			delete m1;
		}
		b = a;
		m1 = b.createMateria("cure");  // Expected NULL
		if (!m1)
			std::cout << "Yes\n";
	}
}
