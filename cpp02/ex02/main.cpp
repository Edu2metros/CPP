#include "Fixed.hpp"
#include <iostream>
#include <string>
#include <cstring>

int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;

//My own tests
Fixed c(42.42f);
Fixed d(5);

std::cout << c * b << std::endl;
std::cout << c / b << std::endl;
std::cout << c + b << std::endl;
std::cout << c - b << std::endl; 
return 0;
}