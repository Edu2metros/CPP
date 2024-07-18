#include "Span.hpp"

bool checkDebug()
{
	#ifdef DEBUG
		return true;
	#else
		return false;
	#endif
}

Span::Span(int lenght)
{
	if (checkDebug())
		std::cout << "Span parameter constructor called" << std::endl;
	if(lenght <= 0)
		throw Span::LengthException("Can't initialize a Span with a length of 0 or less!");
	_length = lenght;
}

Span::Span(Span const & src) : _length(src._length)
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
		_length = rhs._length;
	}
	return *this;
}

Span::LengthException::LengthException(std::string msg) : _msg(msg)
{
}

Span::LengthException::~LengthException() throw()
{
}

const char * Span::LengthException::what() const throw()
{
	return _msg.c_str();
}

const char * Span::NoSpaceException::what() const throw()
{
	return "No space left in the Span";
}

const char * Span::NoSpanException::what() const throw()
{
	return "No span to calculate";
}

void Span::addNumber(int n)
{
	if (_length == 0)
		throw Span::NoSpaceException();
	_length--;
	_numbers.push_back(n);
}

void Span::addNumber(int *array, unsigned int size)
{
    if (_length < size)
        throw Span::NoSpaceException();
    _length -= size;
    _numbers.insert(_numbers.end(), array, array + size);
}


void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_length < std::distance(begin, end))
		throw Span::NoSpaceException();
	_length -= std::distance(begin, end);
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