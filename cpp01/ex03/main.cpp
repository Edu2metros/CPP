#include <iostream>
#include <string>

class Weapon
{
private:
	std::string type;

public:
	Weapon() : type("") {}
	Weapon(const std::string& name) : type(name){}
	
	const std::string getType(void){
		return(this->type);
	}

	void setType(const std::string& name){
		this->type = name;
	}
};

class HumanA
{
public:
	std::string name;
	Weapon& weapon;

	HumanA(const std::string& name, Weapon& type) : name(name), weapon(type) {}

	void attack(void){
		std::cout << name << " attacks with their " << weapon.getType() << std::endl;
	}
};

class HumanB
{
public:
	std::string name;
	Weapon *weapon;

	HumanB(const std::string& name) : name(name){}

	void attack(void){
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	}
	void setWeapon(Weapon &new_weapon){
		this->weapon = &new_weapon;
	}
};

int main(void)
{
	std::cout << "Test 1: " << std::endl;
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
		club.setType("Ak 47");
		bob.attack();
	}
	std::cout << "Test 2: " << std::endl;
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
		club.setType("Canivet");
		jim.attack();
	}
	return 0;
}