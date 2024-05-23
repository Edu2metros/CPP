#include "Zombie.hpp"

int main(void)
{
	int hordeSize = 10;
	Zombie *horde = zombieHorde(hordeSize, "Horde");
	for(int i = 0; i < hordeSize; i++)
		horde[i].PrintZombie();
	delete[] horde;
	return(0);
}