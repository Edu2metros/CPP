#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &brain)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = brain;
}

Brain &Brain::operator=(const Brain &brain)
{
	std::cout << "Brain assignation operator called" << std::endl;
	if(this != &brain)
	{
		for(int i = 0; i < 100; i++)
			_ideas[i] = brain._ideas[i];
	}
	return *this;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

std::string Brain::getIdea(int index) const
{
	return (_ideas[index]);
}

void Brain::setIdea(int index, std::string idea)
{
	if(index >= 0 && index < 100)
		_ideas[index] = idea;
	else
		std::cout << "Index out of range." << std::endl;
}

void Brain::printIdeas(void) const
{
	for(int i = 0; i < 100; i++)
		if(!_ideas[i].empty())
			std::cout << "Idea " << i << ": " << _ideas[i] << std::endl;
}

void Brain::getBrainAddress(void) const
{
    std::cout << "Brain address: \033[1;31m" << this << "\033[0m" << std::endl;
}
