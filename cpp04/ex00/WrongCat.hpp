#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
	WrongCat(void);
	WrongCat(const WrongCat &wrongcat);
	WrongCat &operator=(const WrongCat &wrongcat);
	~WrongCat(void);

	void makeSound(void) const;
	std::string getType(void) const;
};

#endif