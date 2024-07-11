#include "MutantStack.hpp"

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack()
{
	#ifdef DEBUG
		std::cout << "MutantStack default constructor called" << std::endl;
	#endif
}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack<T, Container>& other) : std::stack<T, Container>(other)
{
	#ifdef DEBUG
		std::cout << "MutantStack copy constructor called" << std::endl;
	#endif
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack()
{
	#ifdef DEBUG
		std::cout << "MutantStack destructor called" << std::endl;
	#endif
}

template <typename T, typename Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack<T, Container>& other)
{
	if (this != &other)
	{
		std::stack<T, Container>::operator=(other);
	}
	#ifdef DEBUG
		std::cout << "MutantStack assignation operator called" << std::endl;
	#endif
	return *this;
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin()
{
    typedef typename std::stack<T, Container>::container_type::iterator container_iterator;
    container_iterator container_it = std::stack<T, Container>::c.begin();
    return iterator(container_it);
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end()
{
    typedef typename std::stack<T, Container>::container_type::iterator container_iterator;
    container_iterator container_it = std::stack<T, Container>::c.end();
    return iterator(container_it);
}
