#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>
#include <string>

class Fixed
{
    public:
        Fixed(void); // default constructor -> init _fixedPointValue to 0
        Fixed(int value); // constructor with int argument
        Fixed(float value); // constructor with float argument
        Fixed(const Fixed &src); // copy constructor もらった値をコピーする
        // Fixed operator+(const Fixed &src) const;
        // Fixed operator-(const Fixed &src) const;
        Fixed &operator=(const Fixed &src); // assignation operator overload コピーする
        ~Fixed(void); // destructor
        int getRawBits(void) const; // returns the raw value of the fixed point value
        void setRawBits(int const raw); // sets the raw value of the fixed point value
        float toFloat(void) const; // converts the fixed point value to a floating point value
        int toInt(void) const; // converts the fixed point value to an integer value

    private:
        int _fixedPointValue;
        static const int _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif