// #include "Fixed.hpp"
#include "../includes/Fixed.hpp"

// Default constructor
Fixed::Fixed(void) : _fixedPointValue(0)
{
    std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    _fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    _fixedPointValue = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &src)
{
    std::cout << PURPLE << "Copy constructor called" << RESET << std::endl;
    *this = src;
}

// Assignation operator overload
Fixed &Fixed::operator=(const Fixed &src)
{
    std::cout << BLUE << "Assignation operator called" << RESET << std::endl;
    if (this != &src)
        _fixedPointValue = src.getRawBits();
    return *this;
}

// Destructor
Fixed::~Fixed(void)
{
    std::cout << RED << "Destructor called" << RESET << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << YELLOW << "getRawBits member function called" << RESET << std::endl;
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