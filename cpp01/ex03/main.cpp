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
		return(type);
	}
	void setType(const std::string& name){
		type = name;
	}
};

class HumanA
{
public:
	Weapon weapon;
	std::string name;

	HumanA() : name(""), weapon() {}
	HumanA(const std::string& name, const Weapon& type) : name(name), weapon(type) {}

	void attack(void){
		std::cout << name << " attacks with their " << weapon.getType() << std::endl;
	}
};

class HumanB
{
public:
	Weapon weapon_type;
	std::string name;

	HumanB() : name(""), weapon_type{} {}
	HumanB(const std::string& name) : name(name){}

	void attack(void){
		std::cout << name << " attacks with their " << weapon_type.getType() << std::endl;
	}
	void setWeapon(const Weapon& weapon){
		weapon_type = weapon;
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
	}
	std::cout << "Test 2: " << std::endl;
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}