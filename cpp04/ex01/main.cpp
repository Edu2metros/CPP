#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongDog.hpp"

int main()
{
	int size = 10;
	Animal* animals[size];
	std::cout << "Test by subject:" << std::endl;
	for(int i = 0; i < size; i++)
	{
		if(i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for(int i = 0; i < size; i++)
		animals[i]->makeSound();
	for(int i = 0; i < size; i++)
		delete animals[i];
	std::cout << std::endl << std::endl;

	std::cout << "Test by me:" << std::endl;
	std::cout << "Deep copy examples:" << std::endl;
	Dog basic;
	{
		Dog tmp = basic;
		std::cout << std::endl;
		tmp.getBrain();
		tmp.setIdea(0, "I'm a dog");
		tmp.setIdea(1, "So I need to bark");
		tmp.setIdea(2, "And to pee on the street");
		tmp.setIdea(70, "And play with my owner!");
		tmp.printIdeas();
	}
	std::cout << std::endl << std::endl;
	basic.getBrain();
	basic.printIdeas();
	std::cout << std::endl << std::endl;
	Cat cat;
	{
		Cat tmp(cat);
		std::cout << std::endl;
		tmp.getBrain();
		tmp.setIdea(0, "I'm a cat");
		tmp.setIdea(1, "So I need to meow");
		tmp.setIdea(2, "And to sleep all day");
		tmp.setIdea(70, "And hurt my owner! :D");
		tmp.printIdeas();
		cat.getBrain();
		cat.setIdea(50, "And hunt birds.");
		cat.printIdeas();
	}
	std::cout << std::endl << std::endl;

/* 	std::cout << "Shallow copy examples:" << std::endl;
	WrongDog wrongBasic;
	{
		WrongDog tmp = wrongBasic;
		WrongDog tmp2(tmp);
		std::cout << std::endl;
		tmp.getBrain();
		tmp2.getBrain();
		wrongBasic.getBrain();
	}
	std::cout << "Seg fault." << std::endl; */
	std::cout << std::endl << std::endl;
    return 0;
}
