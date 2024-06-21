#include "FlagTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	FlagTrap flagtrap("Flag");
	flagtrap.get_stats();
	flagtrap.attack("Claptrap");
	flagtrap.takeDamage(10);
	flagtrap.get_stats();
	flagtrap.beRepaired(10);
	flagtrap.get_stats();
	flagtrap.highFivesGuys();
}
