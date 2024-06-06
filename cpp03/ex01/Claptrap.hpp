#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class Claptrap
{
protected:
    std::string _name;
    int _health;
    int _energy;
    int _attack;

public:
    Claptrap();
    Claptrap(std::string name, int health, int energy, int attack);
    Claptrap(const Claptrap& other);
    Claptrap& operator=(const Claptrap& other);
    ~Claptrap();

    std::string GetName();
    int GetHealth();
    int GetEnergy();
    int GetAttack();
    virtual void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
	void get_stats();
};

#endif
