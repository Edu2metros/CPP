#pragma once

#include <stack>
#include <iostream>
#include <string>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
	// Syntax Orthodox Canonical Form
	MutantStack();
	MutantStack(MutantStack const &src);
	~MutantStack();
	MutantStack &operator=(MutantStack const &rhs);

	//Iterators
	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;
	iterator begin();
	iterator end();
	const_iterator begin() const;
	const_iterator end() const;
};

#include "../src/MutantStack.tpp"