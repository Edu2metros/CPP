#include "Zombie.hpp"

int main(int argc, char **argv)
{
	int hordeSize;
	if(argc == 2 && std::atoi(argv[1]) > 0)
		hordeSize = std::atoi(argv[1]);
	else
		hordeSize = 5;
	std::cout << "Horde size: " << hordeSize << std::endl;
	Zombie *horde = zombieHorde(hordeSize, "Horde");
	for(int i = 0; i < hordeSize; i++)
		horde[i].PrintZombie();
	delete[] horde;
	return(0);
}