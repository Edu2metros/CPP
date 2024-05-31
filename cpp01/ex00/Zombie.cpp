#include "Zombie.hpp"

void Zombie::PrintZombie(void) const
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string ZombieName) : name(ZombieName)
{
}
Zombie::~Zombie(void)
{
	std::cout << "[DESTRUCTOR]: " << this->name << " is dead." << std::endl;
}