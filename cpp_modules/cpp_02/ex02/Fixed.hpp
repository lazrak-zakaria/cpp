#ifndef FIXED_HPP__

# define FIXED_HPP__
# include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					num;
		const static int	fractional_bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed(const int n);
		Fixed(const float n);
		Fixed	&operator =(const Fixed &fixed);
		float	toFloat(void) const;
		int		toInt(void) const;
		~Fixed();
		int 	getRawBits( void ) const;
		void	setRawBits(int const raw);
	
		/* operator overloding */

		
		bool	operator >(const Fixed &fixed) const;
		bool	operator >=(const Fixed &fixed) const;
		bool	operator <=(const Fixed &fixed) const;
		bool	operator <(const Fixed &fixed) const;
		bool	operator ==(const Fixed &fixed) const;
		bool	operator !=(const Fixed &fixed) const;

		Fixed	operator +(const Fixed &fixed) const;
		Fixed	operator -(const Fixed &fixed) const;
		Fixed	operator *(const Fixed &fixed) const;
		Fixed	operator /(const Fixed &fixed) const;

		Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);

		static const Fixed& min(const Fixed& f1, const Fixed &f2);
		static const Fixed& max(const Fixed& f1, const Fixed &f2);
		static Fixed& max(Fixed &f1, Fixed &f2);
		static Fixed& min(Fixed &f1, Fixed &f2);
};

std::ostream& operator<<(std::ostream& os, const Fixed& d);

#endif
