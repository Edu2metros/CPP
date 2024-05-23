#include <string>
#include <iostream>

class Zombie{
	private:
	std::string name;

	public:
	Zombie(std::string zombieName) : name(zombieName) {}

	void PrintZombie(void){
		std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	}
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);
