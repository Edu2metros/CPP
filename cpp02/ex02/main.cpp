#include "Fixed.hpp"
#include <iostream>

int main(void) {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    std::cout << "Initial values:\n";
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    // Testing increment and decrement operators
    std::cout << "Increment and Decrement Tests:\n";
    std::cout << "Pre-increment: " << ++a << std::endl;
    std::cout << "Post-increment: " << a++ << std::endl;
    std::cout << "Current value: " << a << std::endl;
    std::cout << "Pre-decrement: " << --a << std::endl;
    std::cout << "Post-decrement: " << a-- << std::endl;
    std::cout << "Current value: " << a << std::endl;

    // Testing arithmetic operators
    Fixed c(42.42f);
    Fixed d(5);

    std::cout << "Arithmetic Tests:\n";
    std::cout << "c * b: " << c * b << std::endl;
    std::cout << "c / b: " << c / b << std::endl;
    std::cout << "c + b: " << c + b << std::endl;
    std::cout << "c - b: " << c - b << std::endl;

    // Testing comparison operators
    std::cout << "Comparison Tests:\n";
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;

    // Testing min and max functions
    std::cout << "Min and Max Tests:\n";
    std::cout << "Max of a and b: " << Fixed::max(a, b) << std::endl;
    std::cout << "Min of a and b: " << Fixed::min(a, b) << std::endl;
    std::cout << "Max of c and d: " << Fixed::max(c, d) << std::endl;
    std::cout << "Min of c and d: " << Fixed::min(c, d) << std::endl;
	std::cout << c << std::endl;
	c++;
	++c;
	std::cout << c << std::endl;
	c--;
	--c;
	std::cout << c << std::endl;
    return 0;
}
