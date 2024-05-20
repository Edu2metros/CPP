#include <iostream>
#include <string>

class Zombie{
	private:
	std::string name;

	public:
	Zombie() {}
	Zombie(std::string zombieName) : name(zombieName) {}
	
	void PrintZombie(void){
		std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	}
	void setName(std::string zombieName){
		name = zombieName;
	}
};

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *horde = new Zombie[N];
	for(int i = 0; i < N; i++){
		horde[i].setName(name);
	}
	return(horde);
}

int main(void)
{
	int hordeSize = 5;
	Zombie *horde = zombieHorde(hordeSize, "Horde");
	for(int i = 0; i < hordeSize; i++){
		horde[i].PrintZombie();
	}
	delete[] horde;
	return(0);
}