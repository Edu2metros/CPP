#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
    std::cout << "Dog default constructor called" << std::endl;
    brain = new Brain();
}

Dog::Dog(const Dog &dog) : Animal(dog) {
    std::cout << "Dog copy constructor called" << std::endl;
    brain = new Brain(*dog.brain);
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << "Dog assignation operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog(void) {
    std::cout << "Dog destructor called" << std::endl;
    delete brain;
}

void Dog::makeSound(void) const {
    std::cout << "Dog sound: au au au!!!" << std::endl;
}

void Dog::getBrain(void) const
{
	std::cout << "getBrain called from Dog class." << std::endl;
	brain->getBrainAddress();
}

void Dog::setIdea(int index, std::string idea)
{
	brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const
{
	return (brain->getIdea(index));
}

void Dog::printIdeas(void) const
{
	brain->printIdeas();
}

void Dog::getAnimalAdress(void) const
{
	std::cout << "getAnimalAdress called from Dog class." << std::endl;
	Animal::getAnimalAdress();
}