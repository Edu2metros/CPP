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

	void setName(const std::string& zombieName){
		name = zombieName;
	}
};

Zombie* zombieHorde(int N, std::string name);
