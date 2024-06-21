#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain* brain;
public:
	Cat(void);
	Cat(const Cat &cat);
	Cat &operator=(const Cat &cat);
	virtual ~Cat(void);

	void makeSound(void) const;
	void getBrain(void) const;
	void setIdea(int index, std::string idea);
	std::string getIdea(int index) const;
	void printIdeas(void) const;
	void getAnimalAdress(void) const;
};

#endif