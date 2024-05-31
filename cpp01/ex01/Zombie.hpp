#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class Zombie{
	private:
	std::string name;

	public:
	Zombie();
	Zombie(std::string zombieName);
	~Zombie(void);

	void PrintZombie(void) const;
	void setName(const std::string& zombieName);
};

Zombie* zombieHorde(int N, std::string name);

#endif