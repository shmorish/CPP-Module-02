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
        Fixed(void);
        Fixed(int value);
        Fixed(float value);
        Fixed(const Fixed &src);
        Fixed &operator=(const Fixed &src);
        ~Fixed(void);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;

    private:
        int _fixedPointValue;
        static const int _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif