#ifndef WEAPON_HPP__
# define WEAPON_HPP__

#include <string>

class Weapon
{
	private :
		std::string type;
		Weapon(void);
	public :
		const	std::string& getType() const;
		void	setType(std::string newType);
		Weapon(std::string type);
};

#endif