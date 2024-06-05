#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string name) : Claptrap(name, 100, 50, 20) {
    std::cout << "ScavTrap " << GetName() << " is ready to protect the gate!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : Claptrap(other) {
    std::cout << "ScavTrap " << GetName() << " is ready to protect the gate!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {
        Claptrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << GetName() << " is no longer guarding the gate!" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
    std::cout << "ScavTrap " << GetName() << " attacks " << target << " with style, causing " << GetAttack() << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << GetName() << " is now guarding the gate!" << std::endl;
}
