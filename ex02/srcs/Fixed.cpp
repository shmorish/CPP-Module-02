// #include "Fixed.hpp"
#include "../includes/Fixed.hpp"

// Default constructor
Fixed::Fixed(void) : _fixedPointValue(0)
{
	// std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const int value)
{
	// std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
	// std::cout << "Float constructor called" << std::endl;
	_fixedPointValue = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &src)
{
	// std::cout << PURPLE << "Copy constructor called" << RESET << std::endl;
	*this = src;
}

// Assignation operator overload
Fixed &Fixed::operator=(const Fixed &src)
{
	// std::cout << BLUE << "Assignation operator called" << RESET << std::endl;
	if (this != &src)
		_fixedPointValue = src.getRawBits();
	return *this;
}

// Destructor
Fixed::~Fixed(void)
{
	// std::cout << RED << "Destructor called" << RESET << std::endl;
}

int Fixed::getRawBits(void) const
{
	// std::cout << YELLOW << "getRawBits member function called" << RESET << std::endl;
	return _fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	_fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
	return (float)_fixedPointValue / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
	return _fixedPointValue >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

// x + y
Fixed   Fixed::operator+(const Fixed &fixed) const
{
	return Fixed(toFloat() + fixed.toFloat());
}

// x - y
Fixed   Fixed::operator-(const Fixed &fixed) const
{
	return Fixed(toFloat() - fixed.toFloat());
}

// x * y
Fixed   Fixed::operator*(const Fixed &fixed) const
{
	return Fixed(toFloat() * fixed.toFloat());
}

// x / y
Fixed   Fixed::operator/(const Fixed &fixed) const
{
	return Fixed(toFloat() / fixed.toFloat());
}

// ++x
Fixed   &Fixed::operator++(void)
{
	_fixedPointValue++;
	return *this;
}

// x++
Fixed   Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}

// --x
Fixed   &Fixed::operator--(void)
{
	_fixedPointValue--;
	return *this;
}

// x--
Fixed   Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return tmp;
}

// x > y
bool	Fixed::operator>(const Fixed& fixed) const
{
	return _fixedPointValue > fixed.getRawBits();
}

// x < y
bool	Fixed::operator<(const Fixed &fixed) const
{
	return _fixedPointValue < fixed.getRawBits();
}

// x >= y
bool	Fixed::operator>=(const Fixed &fixed) const
{
	return _fixedPointValue >= fixed.getRawBits();
}

// x <= y
bool	Fixed::operator<=(const Fixed &fixed) const
{
	return _fixedPointValue <= fixed.getRawBits();
}

// x == y
bool	Fixed::operator==(const Fixed &fixed) const
{
	return _fixedPointValue == fixed.getRawBits();
}

// x != y
bool	Fixed::operator!=(const Fixed &fixed) const
{
	return _fixedPointValue != fixed.getRawBits();
}

// min
Fixed&		Fixed::min(Fixed &a, Fixed &b)
{
	return a < b ? a : b;
}

// max
Fixed&		Fixed::max(Fixed &a, Fixed &b)
{
	return a > b ? a : b;
}

// min
const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	return a < b ? a : b;
}

// max
const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	return a > b ? a : b;
}
