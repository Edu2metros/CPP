#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &wrongcat)
{
	*this = wrongcat;
}

WrongCat &WrongCat::operator=(const WrongCat &wrongcat)
{
	this->type = wrongcat.type;
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout << "WrongCat sound: bark bark!!!" << std::endl;
}

std::string WrongCat::getType(void) const
{
	return (type);
}