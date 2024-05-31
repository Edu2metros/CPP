#include "Weapon.hpp"

Weapon::Weapon(const std::string& name) : type(name){}

const std::string Weapon::getType(void) const
{
	return(this->type);
}

void Weapon::setType(const std::string& name)
{
	this->type = name;
}