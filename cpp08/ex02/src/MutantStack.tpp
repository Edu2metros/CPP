#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack()
{
    #ifdef DEBUG
        std::cout << "MutantStack default constructor called" << std::endl;
    #endif
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& other) : std::stack<T>(other)
{
    #ifdef DEBUG
        std::cout << "MutantStack copy constructor called" << std::endl;
    #endif
}

template <typename T>
MutantStack<T>::~MutantStack()
{
    #ifdef DEBUG
        std::cout << "MutantStack destructor called" << std::endl;
    #endif
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& other)
{
    if (this != &other)
    {
        std::stack<T>::operator=(other);
    }
    #ifdef DEBUG
        std::cout << "MutantStack assignation operator called" << std::endl;
    #endif
    return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return this->c.end();
}
