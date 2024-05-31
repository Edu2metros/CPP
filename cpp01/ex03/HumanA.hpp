#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
public:
	std::string name;
	Weapon& weapon;

	HumanA(const std::string& name, Weapon& type);
	void attack( void ) const;
};

#endif