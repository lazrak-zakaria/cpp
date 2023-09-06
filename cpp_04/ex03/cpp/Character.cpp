#include "../Character.hpp"

Character::Character()
{
	//std::cout << "Character default constructor\n";
	std::memset(materias, 0, sizeof(materias));
}

Character::~Character()
{
	for (int i = 0; i < 4; ++i)
		if (materias[i])
		{
			delete materias[i];
		}
}

Character::Character(const Character& c)
{
	std::memset(materias, 0, sizeof(materias));
	*this = c;
}

Character &Character::operator=(const Character& c)
{
	if (this == &c)
		return *this;
	name = c.name;
	for (int i = 0; i < 4 ; ++i)
	{
		if (materias[i])
			delete materias[i];
		materias[i] = NULL;
		// if (c.materias[i])
			// materias[i] = c.materias[i]->clone();
		if (c.materias[i] && c.materias[i]->getType() == "ice")
			materias[i] = new Ice();
		else if (c.materias[i] && c.materias[i]->getType() == "cure")
			materias[i] = new Cure();
	}
	return *this;
}

Character::Character(std::string name)
{
	//std::cout << "Character parametrized constructor\n";
	this->name = name;
	std::memset(materias, 0, sizeof(materias));
}


std::string const& Character::getName() const
{
	return name;
}

void	Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; ++i)
		if (!materias[i])
		{
			materias[i] = m;
			return ;
		}
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && materias[idx])
		materias[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && materias[idx])
		materias[idx]->use(target);
}
