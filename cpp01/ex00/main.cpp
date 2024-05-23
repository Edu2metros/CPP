#include "Zombie.hpp"

int main(void)
{
	Zombie *new_zombie = newZombie("Foo");
	new_zombie->PrintZombie();
	delete new_zombie;
	randomChump("Bar");
	return(0);
}