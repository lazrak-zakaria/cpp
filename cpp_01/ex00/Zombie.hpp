#ifndef ZOMBIE_HPP__

# define ZOMBIE_HPP__

# include <iostream>
# include <string>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie(std::string name);
		void	announce(void);
		~Zombie();
		
};

#endif