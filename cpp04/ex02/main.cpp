#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongDog.hpp"

int main()
{
	Dog dog;
	Cat cat;

	dog.makeSound();
	cat.makeSound();

	dog.getAnimalAdress();
	cat.getAnimalAdress();
	// WrongDog wrongDog;
	// Animal animal;
    return 0;
}
