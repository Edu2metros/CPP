#include <iostream>

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	private:
	int value;
	static const int bits = 8;

	public:
	
	// constructor
	Fixed( void );
	
	//Constructor with parameters
	Fixed(const int value);
	Fixed(const float value);

	// copy constructor
	Fixed(Fixed const &other);

	// copy assign operator
	Fixed& operator=(const Fixed& other);

	// destructor
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat(void) const;
	int toInt(void) const;
	
	//Operators << > >= < <= == !=
	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	//Operators + - * /
	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

	//Operator pre increment (++x) and post increment (x++) and pre decrement (--x) and post decrement (x--)
	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);

	//Function members
	static Fixed& min(Fixed &a, Fixed &b);
	static const Fixed& min(const Fixed &a, const Fixed &b);
	static Fixed& max(Fixed &a, Fixed &b);
	static const Fixed& max(const Fixed &a, const Fixed &b);
	static void teste(void);
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif