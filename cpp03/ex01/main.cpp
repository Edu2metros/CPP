#include "ScavTrap.hpp"

void get_stats(Claptrap &claptrap)
{
    std::cout << "\033[1;34mName: \033[0m" << claptrap.GetName() << std::endl;
    std::cout << "\033[1;35mHealth: \033[0m" << claptrap.GetHealth() << std::endl;
    std::cout << "\033[1;35mEnergy: \033[0m" << claptrap.GetEnergy() << std::endl;
    std::cout << "\033[1;35mAttack: \033[0m" << claptrap.GetAttack() << std::endl;
}

int main(void)
{
    ScavTrap scav("hiiiii");
	std::cout << scav.GetName() << std::endl;
}
