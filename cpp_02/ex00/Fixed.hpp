#ifndef FIXED_HPP__

# define FIXED_HPP__
# include <iostream>

class Fixed
{
	private:
		int					num;
		const static int	fractional_bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		~Fixed();
		Fixed &operator=(const Fixed &fixed);
		int 	getRawBits( void ) const;
		void	setRawBits(int const raw);
};

#endif