#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
private:
	std::string type;

public:
	Weapon(const std::string& name);
	const std::string getType(void) const;
	void setType(const std::string& name);
};

#endif