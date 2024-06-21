#include "FlagTrap.hpp"

FlagTrap::FlagTrap(std::string name) : Claptrap(name, 100, 100, 30)
{
	std::cout << "Default constructor for " << _name << " called!" << std::endl;
	std::cout << "FlagTrap: " << _name << " created!" << std::endl;
}

FlagTrap::FlagTrap(const FlagTrap &other) : Claptrap(other)
{
	std::cout << "Copy constructor for " << _name << " called!" << std::endl;
	std::cout << "FlagTrap: " << _name << " created!" << std::endl;
}

FlagTrap &FlagTrap::operator=(const FlagTrap &other)
{
	if (this == &other)
		return (*this);
	Claptrap::operator=(other);
	std::cout << "Assignation operator for " << _name << " called!" << std::endl;
	std::cout << "FlagTrap: " << _name << " created!" << std::endl;
	return (*this);
}

FlagTrap::~FlagTrap()
{
	std::cout << "Destructor for " << _name << " called!" << std::endl;
	std::cout << "FlagTrap: " << _name << " destroyed!" << std::endl;
}

void FlagTrap::highFivesGuys()
{
	std::cout << "High five !! Guys" << std::endl;
}