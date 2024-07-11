#pragma once

#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <string>

class Span
{
	private:
	unsigned int _lenght;
	std::vector<int> _numbers;
	public:
	//Orthodox Canonical Form
	Span();
	Span(unsigned int n);
	Span(Span const & src);
	~Span();
	Span & operator=(Span const & rhs);

	//Member functions
	void addNumber(int n);
	void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	int shortestSpan();
	int longestSpan();
	std::ostream& shortestSpanTwo(std::ostream &out);
	class NoSpaceException : public std::exception
	{
		public:
		virtual const char * what() const throw();
	};
	class NoSpanException : public std::exception
	{
		public:
		virtual const char * what() const throw();
	};
};