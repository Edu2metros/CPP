#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap diamond("Horseman");
	std::cout << std::endl << std::endl;
	diamond.attack("Claptrap");
	diamond.takeDamage(10);
	diamond.beRepaired(10);
	diamond.whoAmI();
	diamond.guardGate();
	diamond.highFivesGuys();
	std::cout << std::endl << std::endl;
	return (0);
}
