#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
public:
	std::string name;
	Weapon *weapon;

	HumanB(const std::string& name);
	void attack(void);
	void setWeapon(Weapon &new_weapon);
};

#endif