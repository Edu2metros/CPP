#include "Fixed.hpp"
#include <iostream>
#include <string>
#include <cmath>

Fixed::Fixed(void) : value(0)
{
}

Fixed::Fixed(const int value) : value(value << this->bits)
{
}

Fixed::Fixed(const float value) : value(roundf(value * (1 << this->bits)))
{
}

Fixed::Fixed(Fixed const &other)
{
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if(this != &other)
		this->value = other.getRawBits();
	return(*this);
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits( void ) const
{
	return(this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float Fixed::toFloat(void) const
{
	return((float)this->value / (1 << this->bits));
}

int Fixed::toInt(void) const
{
	return(this->value >> this->bits);
}

// Operators << > >= < <= == !=

std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
    return (out);
}

bool Fixed::operator>(const Fixed &other) const
{
    return this->toFloat() > other.toFloat();
}

bool Fixed::operator<(const Fixed &other) const
{
    return this->toFloat() < other.toFloat();
}

bool Fixed::operator>=(const Fixed &other) const
{
    return this->toFloat() >= other.toFloat();
}

bool Fixed::operator<=(const Fixed &other) const
{
    return this->toFloat() <= other.toFloat();
}

bool Fixed::operator==(const Fixed &other) const
{
    return this->toFloat() == other.toFloat();
}

bool Fixed::operator!=(const Fixed &other) const
{
    return this->toFloat() != other.toFloat();
}

//Operators + - * /

Fixed Fixed::operator+(const Fixed &other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}

//Operators ++ --

Fixed& Fixed::operator++()
{
	this->value += 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	++(*this);
	return tmp;
}

Fixed& Fixed::operator--()
{
	this->value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	--(*this);
	return tmp;
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return a;
    else
        return b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return a;
    else
        return b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return a;
    else
        return b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return a;
    else
        return b;
}
