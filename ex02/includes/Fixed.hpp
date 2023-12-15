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
# define PINK	"\033[38;5;219m"
# define CYAN	"\033[36m"
# define RESET	"\033[0m"

class Fixed
{
	public:
		Fixed(void);
		Fixed(int value);
		Fixed(float value);
		Fixed(const Fixed &src);
		~Fixed(void);

		Fixed	&operator=(const Fixed &fixed);
		Fixed	operator+(const Fixed &fixed) const;
		Fixed	operator-(const Fixed &fixed) const;
		Fixed	operator*(const Fixed &fixed) const;
		Fixed	operator/(const Fixed &fixed) const;
		Fixed	&operator++(void);
		Fixed	operator++(int);
		Fixed	&operator--(void);
		Fixed	operator--(int);
		bool	operator>(const Fixed& fixed) const;
		bool	operator<(const Fixed& fixed) const;
		bool	operator>=(const Fixed& fixed) const;
		bool	operator<=(const Fixed& fixed) const;
		bool	operator==(const Fixed& fixed) const;
		bool	operator!=(const Fixed& fixed) const;

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed		&min(Fixed& a, Fixed& b);
		static Fixed		&max(Fixed& a, Fixed& b);
		static const Fixed	&min(const Fixed& a, const Fixed& b);
		static const Fixed	&max(const Fixed& a, const Fixed& b);

	private:
		int 				_fixedPointValue;
		static const int	_fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif