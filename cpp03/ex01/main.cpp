#include "ScavTrap.hpp"

int main(void)
{
	// Claptrap claptrap;
	ScavTrap scavtrap("Scav");
//	Claptrap rotine:
	// claptrap.get_stats();
	// claptrap.attack("Richard Rasmussen");
	// claptrap.beRepaired(500);
	// claptrap.get_stats();
	// claptrap.takeDamage(510);
	// claptrap.get_stats();
	std::cout << std::endl;
//	ScavTrap rotine:
	scavtrap.get_stats();
	scavtrap.attack("Michael Jackson");
	scavtrap.beRepaired(500);
	scavtrap.get_stats();
	scavtrap.takeDamage(500);
	scavtrap.get_stats();
	scavtrap.guardGate();
}
