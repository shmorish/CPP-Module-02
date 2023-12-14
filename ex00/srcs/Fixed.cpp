// #include "Fixed.hpp"
#include "../includes/Fixed.hpp"

// Default constructor
Fixed::Fixed(void) : _fixedPointValue(0)
{
    std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

// Copy constructor
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