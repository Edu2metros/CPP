#include "FlagTrap.hpp"

FlagTrap::FlagTrap(std::string name) : Claptrap(name, 100, 100, 30)
{
	std::cout << "[FLAGTRAP MESSAGE CLASS] Default constructor for " << _name << " called!" << std::endl;
}

FlagTrap::FlagTrap(const FlagTrap &other) : Claptrap(other)
{
	std::cout << "[FLAGTRAP MESSAGE CLASS] Copy constructor for " << _name << " called!" << std::endl;
}

FlagTrap &FlagTrap::operator=(const FlagTrap &other)
{
	if (this == &other)
		return (*this);
	Claptrap::operator=(other);
	std::cout << "[FLAGTRAP MESSAGE CLASS] Assignation operator for " << _name << " called!" << std::endl;
	return (*this);
}

FlagTrap::~FlagTrap()
{
	std::cout << "[FLAGTRAP MESSAGE CLASS] Destructor for " << _name << " called!" << std::endl;
}

void FlagTrap::highFivesGuys()
{
	std::cout << "High five !! Guys" << std::endl;
}