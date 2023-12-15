// #include "Fixed.hpp"
#include "../includes/Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl; // 0 が初期化されている
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;

    std::cout << std::endl;
    std::cout << " ----- " << "MyTests" <<" ----- " << std::endl;
	std::cout << "+   " << a + b << std::endl;
	std::cout << "-   " << a - b << std::endl;
	std::cout << "*   " << a * b << std::endl;
	std::cout << "/   " << a / b << std::endl;
	std::cout << ">   " << "expect: 0 " << "answer: " << (a > b) <<  std::endl;
	std::cout << "<   " << "expect: 1 " << "answer: " << (a < b) << std::endl;
	std::cout << ">=  " << "expect: 0 " << "answer: " << (a >= b) << std::endl;
	std::cout << "<=  " << "expect: 1 " << "answer: " << (a <= b) << std::endl;
	std::cout << "==  " << "expect: 0 " << "answer: " << (a == b) << std::endl;
	std::cout << "!=  " << "expect: 1 " << "answer: " << (a != b) << std::endl;
	std::cout << "min " << Fixed::min( a, b ) << std::endl;
	std::cout << "max " << Fixed::max( a, b ) << std::endl;
	std::cout << "a++ " << a++ << std::endl;
	std::cout << "++a " << ++a << std::endl;
	std::cout << "a-- " << a-- << std::endl;
	std::cout << "--a " << --a << std::endl;
    return 0;
}