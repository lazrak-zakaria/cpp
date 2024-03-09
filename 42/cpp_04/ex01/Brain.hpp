#ifndef BRAIN_HPP
#define BRAIN_HPP


#include <string>
#include <iostream>

class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain& br);
		~Brain();
		Brain &operator =(const Brain& br);
		void	setIdea(std::string s, int idx);
		std::string	getIdea(int idx) const;
		
};

#endif