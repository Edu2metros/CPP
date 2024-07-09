#include "Span.hpp"

bool checkDebug()
{
	#ifdef DEBUG
		return true;
	#else
		return false;
	#endif
}

Span::Span() : _n(0)
{
	if (checkDebug())
		std::cout << "Span default constructor called" << std::endl;
}

Span::Span(unsigned int n) : _n(n)
{
	if (checkDebug())
		std::cout << "Span parameter constructor called" << std::endl;
}

Span::Span(Span const & src) : _n(src._n)
{
	if (checkDebug())
		std::cout << "Span copy constructor called" << std::endl;
}

Span::~Span()
{
	if (checkDebug())
		std::cout << "Span destructor called" << std::endl;
}

Span & Span::operator=(Span const & rhs)
{
	if (checkDebug())
		std::cout << "Span assignation operator called" << std::endl;
	if (this != &rhs)
	{
		_n = rhs._n;
	}
	return *this;
}

void Span::addNumber(int n)
{
	if (_n == 0)
		throw Span::NoSpaceException();
	_n--;
	_numbers.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_n < std::distance(begin, end))
		throw Span::NoSpaceException();
	_n -= std::distance(begin, end);
	_numbers.insert(_numbers.end(), begin, end);
}

int Span::shortestSpan()
{
	if (_numbers.size() < 2)
		throw Span::NoSpanException();
	std::sort(_numbers.begin(), _numbers.end());
	int min = _numbers[1] - _numbers[0];
	for (size_t i = 2; i < _numbers.size(); i++)
	{
		if (_numbers[i] - _numbers[i - 1] < min)
			min = _numbers[i] - _numbers[i - 1];
	}
	return min;
}

int Span::longestSpan()
{
	if (_numbers.size() < 2)
		throw Span::NoSpanException();
	std::sort(_numbers.begin(), _numbers.end());
	return _numbers[_numbers.size() - 1] - _numbers[0];
}
