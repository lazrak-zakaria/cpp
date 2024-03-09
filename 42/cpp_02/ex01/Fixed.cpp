#include "Fixed.hpp"


Fixed::Fixed() : num(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called\n";
	*this = fixed;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
	std::cout << "Copy assignment operator called\n";
	this->num = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called"<<"\n";
}

int	Fixed::getRawBits() const
{
//	std::cout << "getRawBits member function called\n";
	return (this->num);
}

void	Fixed::setRawBits(int const raw)
{
//	std::cout << "setRawBits member function called\n";
	this->num = raw;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called\n";

	int	p = 1 << fractional_bits;

	this->num = n * p;
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called\n";

	int	p = 1 << fractional_bits;

	this->num = roundf(n * p);
}

int		Fixed::toInt(void) const
{
	int	p = 1 << fractional_bits;

	return (this->num / p);
}

float	Fixed::toFloat(void) const
{
	int	p = 1 << fractional_bits;

	return ((float)(this->num) / p);
}


std::ostream &operator<<(std::ostream &os, const Fixed &d)
{
    os << d.toFloat();
    return os;
}
