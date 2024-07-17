#pragma once

#include <stack>
#include <iostream>
#include <string>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	// Syntax Orthodox Canonical Form
	MutantStack();
	MutantStack(MutantStack const &src);
	~MutantStack();
	MutantStack &operator=(MutantStack const &rhs);

	//Iterators
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	iterator begin();
	iterator end();
	const_iterator begin() const;
	const_iterator end() const;
};

#include "../src/MutantStack.tpp"