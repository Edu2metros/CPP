#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "Constructors" << std::endl;
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << std::endl << std::endl;
	std::cout << "Types and sounds" << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound();
	dog->makeSound();
	meta->makeSound();
	std::cout << std::endl << std::endl;
	std::cout << "Destructors" << std::endl;
	delete cat;
	delete dog;
	delete meta;
	std::cout << std::endl << std::endl;
	std::cout << "WrongCat" << std::endl;
	WrongCat cat2;
	cat2.makeSound();
	std::cout << std::endl << std::endl;
	std::cout << "Destructor Wrong cat" << std::endl;
	return (0);
}