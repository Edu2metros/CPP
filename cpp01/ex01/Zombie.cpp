#include "Zombie.hpp"

Zombie::Zombie(void) : name("") {}

Zombie::Zombie(std::string zombieName) : name(zombieName) {}

Zombie::~Zombie(void)
{
	std::cout << "[DESTRUCTOR]: " << this->name << " is dead." << std::endl;
}

void Zombie::PrintZombie(void) const
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string& zombieName)
{
	this->name = zombieName;
}