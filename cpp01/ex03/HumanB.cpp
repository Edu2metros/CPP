#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : name(name){}

void HumanB::attack(void)
{
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &new_weapon)
{
	this->weapon = &new_weapon;
}