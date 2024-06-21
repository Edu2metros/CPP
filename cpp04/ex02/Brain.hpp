#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
	protected:
		std::string _ideas[100];
	public:
		Brain(void);
		Brain(const Brain &brain);
		Brain &operator=(const Brain &brain);
		~Brain(void);

		std::string getIdea(int index) const;
		void setIdea(int index, std::string idea);
		void printIdeas(void) const;
		void getBrainAddress(void) const;
};

#endif