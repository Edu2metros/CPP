#ifndef WRONGDOG_HPP
#define WRONGDOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"


class WrongDog : public Animal
{
private:
	Brain* brain;
public:
	WrongDog(void);
	WrongDog(const WrongDog &dog);
	WrongDog &operator=(const WrongDog &dog);
	virtual ~WrongDog(void);
	// void makeSound(void) const;
	void getBrain(void) const;
};

#endif