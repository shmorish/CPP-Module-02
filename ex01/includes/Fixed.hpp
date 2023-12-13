#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>
#include <string>

# define RED	"\033[31m"
# define ORANGE	"\033[38;5;208m"
# define YELLOW	"\033[33m"
# define GREEN	"\033[32m"
# define BLUE	"\033[34m"
# define PURPLE	"\033[35m"
# define PINK    "\033[38;5;219m"
# define CYAN	"\033[36m"
# define RESET	"\033[0m"

class Fixed
{
    public:
        Fixed(void); // default constructor -> init _fixedPointValue to 0
        Fixed(int value); // constructor with int argument
        Fixed(float value); // constructor with float argument
        Fixed(const Fixed &src); // copy constructor もらった値をコピーする
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