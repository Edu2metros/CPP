#include "WrongDog.hpp"

WrongDog::WrongDog(void) : Animal("WrongDog") {
	std::cout << "WrongDog default constructor called" << std::endl;
	brain = new Brain();
}

WrongDog::WrongDog(const WrongDog &dog) : Animal(dog)
{
	std::cout << "WrongDog copy constructor called" << std::endl;
	brain = dog.brain;
}

WrongDog &WrongDog::operator=(const WrongDog &other) {
	std::cout << "WrongDog assignation operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		delete brain;
		brain = other.brain;
	}
	return *this;
}

WrongDog::~WrongDog(void) {
	std::cout << "WrongDog destructor called" << std::endl;
	delete brain;
}

void WrongDog::makeSound(void) const {
	std::cout << "WrongDog sound: au au au!!!" << std::endl;
}

void WrongDog::getBrain(void) const {
	std::cout << "getBrain called from WrongDog class." << std::endl;
	brain->getBrainAddress();
}
