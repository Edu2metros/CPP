#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string name) : Claptrap(name, 100, 50, 20)
{
    std::cout << "Default constructor called for ScavTrap: " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : Claptrap(other._name, other._health, other._energy, other._attack)
{
    std::cout << "Copy constructor called for ScavTrap: " << other._name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
        Claptrap::operator=(other);
    std::cout << "Assignment operator called for ScavTrap: " << other._name << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "Destructor called for ScavTrap: " << _name << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << _name << " is now guarding the gate." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    std::cout << "\033[1;31mScavTrap " << _name << " smashes " << target << " using a clothes iron, dealing " << _attack << " damage! Irony at its finest!\033[0m" << std::endl;
}
