#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain* brain;
public:
	Dog(void);
	Dog(const Dog &dog);
	Dog &operator=(const Dog &dog);
	virtual ~Dog(void);
	void makeSound(void) const;
	void getBrain(void) const;
	void setIdea(int index, std::string idea);
	std::string getIdea(int index) const;
	void printIdeas(void) const;
};

#endif