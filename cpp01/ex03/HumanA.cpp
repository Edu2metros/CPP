#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& type) : name(name), weapon(type) {}

void HumanA::attack( void ) const
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}