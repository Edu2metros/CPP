#include <iostream>
#include <string>

class Zombie{
	private:
	std::string name;

	public:
	Zombie(std::string zombieName) : name(zombieName) {}
	
	void PrintZombie(void){
		std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	}
};

Zombie* newZombie(std::string name){
	return(new Zombie(name));
}

void randomChump(std::string name){
	Zombie temp(name);
	temp.PrintZombie();
}

int main(void){
	Zombie *new_zombie = newZombie("Foo");
	new_zombie->PrintZombie();
	delete new_zombie;
	randomChump("Bar");
	return(0);
}