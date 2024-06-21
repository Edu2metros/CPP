#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : Claptrap(name + "_clap_name", 100, 50, 30), FlagTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), _name(name + "_clap_name")
{
	std::cout << "Default constructor for " << _name << " called!" << std::endl;
	std::cout << "DiamondTrap: " << _name << " created!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : Claptrap(other), FlagTrap(other), ScavTrap(other)
{
	std::cout << "Copy constructor for " << _name << " called!" << std::endl;
	std::cout << "DiamondTrap: " << _name << " created!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this == &other)
		return (*this);
	Claptrap::operator=(other);
	FlagTrap::operator=(other);
	ScavTrap::operator=(other);
	std::cout << "Assignation operator for " << _name << " called!" << std::endl;
	std::cout << "DiamondTrap: " << _name << " created!" << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destructor for " << _name << " called!" << std::endl;
	std::cout << "DiamondTrap: " << _name << " destroyed!" << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name:" << this->_name << " Claptrap name:" << Claptrap::_name << std::endl;
}
