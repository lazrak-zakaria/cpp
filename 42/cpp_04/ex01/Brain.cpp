#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default constructor\n";
}

Brain::Brain(const Brain& br)
{
	std::cout << "Brain copy constructor\n";
	*this = br;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor\n";
}

Brain& Brain::operator=(const Brain& br)
{
	std::cout << "Brain copy assignement operator\n";
	for (int i = 0; i < 100; ++i)
		ideas[i] = br.ideas[i];
	return *this;
}

void	Brain::setIdea(std::string s, int idx)
{
	if (!(idx >= 0 && idx < 100))
		return ;
	ideas[idx] = s;
}

std::string	Brain::getIdea(int idx) const
{
	std::string ret; 
	if (!(idx >= 0 && idx < 100))
		return ret;
	ret = ideas[idx];
	return ret;
}
