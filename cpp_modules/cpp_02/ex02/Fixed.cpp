#include "Fixed.hpp"

Fixed::Fixed() : num(0)
{
	// std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &fixed)
{
	// std::cout << "Copy constructor called\n";
	num = fixed.getRawBits();
}

Fixed	&Fixed::operator=(const Fixed& fixed)
{
//	std::cout << "Copy assignment operator called\n";
	this->num = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called\n";
}

int	Fixed::getRawBits() const
{
	// std::cout << "getRawBits member function called\n";
	return (this->num);
}

void	Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called\n";
	this->num = raw;
}

Fixed::Fixed(const int n)
{
	// std::cout << "Int constructor called\n";

	int	p = 1 << fractional_bits;

	this->num = n * p;
}

Fixed::Fixed(const float n)
{
	// std::cout << "Float constructor called\n";

	int	p = 1 << fractional_bits;

	this->num = roundf(n * p);
	//std::cout << this->num << "\n"; 
}

int		Fixed::toInt(void) const
{
	int	p = 1 << fractional_bits;

	return (this->num / p);
}

float	Fixed::toFloat(void) const
{
	int	p = 1 << fractional_bits;

	return (((float)this->num) / p);
}


/****************************          ex02           *******************************/


bool	Fixed::operator>(const Fixed &fixed) const
{
	return (this->num > fixed.num);
}

bool	Fixed::operator>=(const Fixed &fixed) const
{
	return (this->num  >= fixed.num);
}

bool	Fixed::operator<=(const Fixed &fixed) const
{
	return (this->num  <= fixed.num);
}

bool	Fixed::operator<(const Fixed &fixed) const
{
	return (this->num < fixed.num);
}

bool	Fixed::operator==(const Fixed &fixed) const
{
	return (this->num == fixed.num);
}

bool	Fixed::operator!=(const Fixed &fixed) const
{
	return (this->num != fixed.num);
}

Fixed	Fixed::operator+(const Fixed &fixed) const
{
	Fixed	answer;
	answer.setRawBits(this->num + fixed.num);
	return (answer);
}

Fixed	Fixed::operator-(const Fixed &fixed) const
{
	Fixed	answer;
	answer.setRawBits(this->num - fixed.num);
	return (answer);
}

Fixed	Fixed::operator*(const Fixed &fixed) const
{
	Fixed	answer;
	int		p = 1 << fractional_bits;

	answer.setRawBits((this->num  * fixed.num) / p) ;
	return (answer);
}

Fixed	Fixed::operator/(const Fixed &fixed) const
{
	Fixed	answer;
	int	p = 1 << fractional_bits;

 	answer.setRawBits((this->num * p) / fixed.num);
	return (answer);
}

Fixed	&Fixed::operator++()
{
	this->num++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed answer(*this);
	this->num++;
	return (answer);
}

Fixed	&Fixed::operator--()
{
	this->num--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed answer(*this);
	this->num--;
	return (answer);
}

Fixed& Fixed::min(Fixed &f1, Fixed &f2)
{
	return ((f1 < f2) ? f1 : f2);
}

const Fixed&  Fixed::min(const Fixed&  f1,const Fixed&  f2)
{
	return ((f1 < f2) ? f1 : f2);
}

const Fixed& Fixed::max(const Fixed&  f1, const Fixed& f2)
{
	//std::cout << "const max\n";
	return ((f1 > f2) ? f1 : f2);
}

Fixed& Fixed::max(Fixed &f1, Fixed &f2)
{
	return ((f1 > f2) ? f1 : f2);
}

std::ostream& operator<<(std::ostream& os, const Fixed& d)
{
    os << d.toFloat();
    return os;
};
