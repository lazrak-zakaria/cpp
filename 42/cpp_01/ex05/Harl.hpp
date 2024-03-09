#ifndef HARL_HPP__
# define HARL_HPP__

#include <string>
#include <iostream>

class Harl
{
	private:
		void info( void );
		void warning( void );
		void error( void );
		void debug( void );

	public:
		void complain( std::string level );
};

#endif