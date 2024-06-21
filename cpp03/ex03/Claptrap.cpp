#include "Claptrap.hpp"

Claptrap::Claptrap() : _name("Claptrap"), _health(10), _energy(10), _attack(0) {
    std::cout << "[MESSAGE CLASS CLAPTRAP] Default constructor called for: " << _name << std::endl;
}

Claptrap::Claptrap(std::string name, int health, int energy, int attack) : _name(name), _health(health), _energy(energy), _attack(attack) {
    std::cout << "[MESSAGE CLASS CLAPTRAP] Constructor with parameters called for: " << _name << std::endl;
}

Claptrap::Claptrap(const Claptrap& other) : _health(other._health), _energy(other._energy), _attack(other._attack) {
    std::cout << "[MESSAGE CLASS CLAPTRAP] Copy constructor called for: " << _name << std::endl;
}

Claptrap& Claptrap::operator=(const Claptrap& other) {
    if (this != &other) {
        _health = other._health;
        _energy = other._energy;
        _attack = other._attack;
    }
    std::cout << "[MESSAGE CLASS CLAPTRAP] Copy assignment operator called for: " << _name << std::endl;
    return *this;
}

Claptrap::~Claptrap() {
    std::cout << "[MESSAGE CLASS CLAPTRAP] Destructor called for: " << _name << std::endl;
}

void Claptrap::attack(const std::string &target) {
    if (this->_energy == 0) {
        std::cout << "\033[1;31m" << this->_name << ": I'm out of energy! I can't attack!\033[0m" << std::endl;
        return;
    }
	if(this->_health == 0){
		std::cout << "\033[1;31m" << this->_name << ": I'm dead! I can't attack!\033[0m" << std::endl;
		return;
	}
    this->_energy--;
    std::cout << "\033[1;32m" << this->_name << " attacks " << target << ", causing " << _attack << " points of damage!\033[0m" << std::endl;
}

void Claptrap::takeDamage(unsigned int amount) {
    std::cout << "\033[1;31m" << this->_name << ": Ouch! That hurts!\033[0m" << std::endl;
    this->_health -= amount;
    if (_health < 0)
        _health = 0;
    std::cout << "\033[1;32m" << this->_name << ": I've lost " << amount << " points of health! My circuits are frying!\033[0m" << std::endl;
}

void Claptrap::beRepaired(unsigned int amount) {
    if (this->_energy == 0) {
        std::cout << "\033[1;31m" << this->_name << ": I'm out of energy! I can't repair myself!\033[0m" << std::endl;
        return;
    }
	if(this->_health == 0){
		std::cout << "\033[1;31m" << this->_name << ": I'm dead! I can't repair myself!\033[0m" << std::endl;
		return;
	}
    this->_health += amount;
    this->_energy--;
    std::cout << "\033[1;33m" << this->_name << ": You can't keep a good robot down! My health is now " << this->_health << "!\033[0m" << std::endl;
}

int Claptrap::GetHealth()
{
	return (this->_health);
}

int Claptrap::GetEnergy()
{
	return (this->_energy);
}

int Claptrap::GetAttack()
{
	return (this->_attack);
}

std::string Claptrap::GetName()
{
	return (this->_name);
}

void Claptrap::get_stats()
{
    std::cout << "\033[1;34mName: \033[0m" << GetName() << std::endl;
    std::cout << "\033[1;35mHealth: \033[0m" << GetHealth() << std::endl;
    std::cout << "\033[1;35mEnergy: \033[0m" << GetEnergy() << std::endl;
    std::cout << "\033[1;35mAttack: \033[0m" << GetAttack() << std::endl;
}