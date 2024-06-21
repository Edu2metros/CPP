#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	protected:
	std::string type;
	Animal(void);
	Animal(std::string type);
	public:
	Animal(const Animal &animal);
	Animal &operator=(const Animal &animal);
	virtual ~Animal(void);
	virtual void makeSound(void) const = 0;
	std::string getType(void) const;
	void getAnimalAdress(void) const;
};

#endif