#ifndef FIXED_HPP__

# define FIXED_HPP__
# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					num;
		const static int	fractional_bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed &operator =(const Fixed &fixed);
		~Fixed();

		Fixed(const int n);
		Fixed(const float n);

		float	toFloat(void) const;
		int		toInt(void) const;
		int 	getRawBits( void ) const;
		void	setRawBits(int const raw);
	
};

std::ostream &operator<<(std::ostream &os, const Fixed &d);

#endif