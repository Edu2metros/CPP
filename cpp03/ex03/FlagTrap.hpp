#ifndef FLAGTRAP_HPP
#define FLAGTRAP_HPP

#include "Claptrap.hpp"

class FlagTrap : virtual public Claptrap
{
	public:
	FlagTrap(std::string name);
	FlagTrap(const FlagTrap& other);
	FlagTrap& operator=(const FlagTrap& other);
	~FlagTrap();

	void highFivesGuys();
};

#endif