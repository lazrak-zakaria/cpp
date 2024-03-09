#include "../MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::memset(materias, 0, sizeof(materias));
}

MateriaSource::MateriaSource(const MateriaSource& ms)
{
	std::memset(materias, 0, sizeof(materias));
	*this = ms;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& ms)
{
	if (this == &ms)
		return *this;
	for (int i = 0; i < 4; ++i)
	{
		if (materias[i])
			delete materias[i];
		materias[i] = NULL;
		if (ms.materias[i] && ms.materias[i]->getType() == "ice")
			materias[i] = new Ice();
		else if (ms.materias[i] && ms.materias[i]->getType() == "cure")
			materias[i] = new Cure();
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i =0; i < 4 ; ++i)
		if (materias[i])
			delete materias[i];
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; ++i)
		if (!materias[i])
		{
			materias[i] = m;
			return ;
		}
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	AMateria* answer = NULL;
	for (int i = 0; i < 4; ++i)
	{
		if (materias[i])
		{
			//std::cout << materias[i]->getType() << "\n";
			if (type == materias[i]->getType())
			{
				answer = materias[i]->clone();
				break;
			}
		}
	}
	return answer;
}
