#ifndef ZOMBIE_HPP__

# define ZOMBIE_HPP__

# include <iostream>
# include <string>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie();
		Zombie(std::string name);
		void	announce(void);
		void	setName(std::string name);
		~Zombie();
		
};

#endif