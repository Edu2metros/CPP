#include "Claptrap.hpp"

Claptrap::Claptrap() : _name("Claptrap"), _health(10), _energy(10), _attack(0) {
    std::cout << "Default constructor called!" << std::endl;
}

Claptrap::Claptrap(std::string name, int health, int energy, int attack) : _name(name), _health(health), _energy(energy), _attack(attack) {
    std::cout << "Constructor with parameters called!" << std::endl;
}

Claptrap::Claptrap(const Claptrap& other) : _health(other._health), _energy(other._energy), _attack(other._attack) {
    std::cout << "Copy constructor called!" << std::endl;
}

Claptrap& Claptrap::operator=(const Claptrap& other) {
    if (this != &other) {
        _health = other._health;
        _energy = other._energy;
        _attack = other._attack;
    }
    std::cout << "Copy assignment operator called!" << std::endl;
    return *this;
}

Claptrap::~Claptrap() {
    std::cout << "Destructor called!" << std::endl;
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
    std::cout << "\033[1;33m" << this->_name << ": Take that, you piece of shit! Feel the wrath of my mighty attack, " << target << "!\033[0m" << std::endl;
    std::cout << "\033[1;34m" << this->_name << ": You can't handle my awesomeness, " << target << "! Go cry to your motherboard!\033[0m" << std::endl;
    std::cout << "\033[1;35m" << this->_name << ": Is that all you've got, " << target << "? My grandma fights better than you!\033[0m" << std::endl;
    std::cout << "\033[1;36m" << this->_name << ": Boom! That's the sound of you losing, " << target << "!\033[0m" << std::endl;
}

void Claptrap::takeDamage(unsigned int amount) {
    std::cout << "\033[1;31m" << this->_name << ": Ouch! That hurts!\033[0m" << std::endl;
    this->_health -= amount;
    if (_health < 0)
        _health = 0;
    std::cout << "\033[1;32m" << this->_name << ": I've lost " << amount << " points of health! My circuits are frying!\033[0m" << std::endl;
    std::cout << "\033[1;33m" << this->_name << ": Is that the best you can do? I'll be back, stronger than ever!\033[0m" << std::endl;
    std::cout << "\033[1;34m" << this->_name << ": You call that an attack? My grandma hits harder!\033[0m" << std::endl;
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
    std::cout << "\033[1;32m" << this->_name << ": Ah, that's the stuff! Repairs complete, I'm feeling better already!\033[0m" << std::endl;
    std::cout << "\033[1;33m" << this->_name << ": You can't keep a good robot down! My health is now " << this->_health << "!\033[0m" << std::endl;
    std::cout << "\033[1;34m" << this->_name << ": Back in action, ready to kick some more butt!\033[0m" << std::endl;
    std::cout << "\033[1;35m" << this->_name << ": Did someone call for a hero? Because I'm back, baby!\033[0m" << std::endl;
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