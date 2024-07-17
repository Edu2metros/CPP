#include "Array.hpp"

void printMsg(std::string msg)
{
	#ifdef DEBUG
		std::cout << msg << std::endl;
	#endif
	(void)msg;
}

template <typename T>
Array<T>::Array() : _array(NULL), _size(0)
{
	printMsg("Default constructor called");
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n)
{
	printMsg("Parametric constructor called");
}

template <typename T>
Array<T>::Array(const Array& copy) : _array(new T[copy._size]), _size(copy._size)
{
	printMsg("Copy constructor called");
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = copy._array[i];
}

template <typename T>
Array<T>::~Array()
{
	printMsg("Destructor called");
	delete[] _array;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& copy)
{
	printMsg("Assignation operator called");
	if (this != &copy)
	{
		delete[] _array;
		_array = new T[copy._size];
		_size = copy._size;
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = copy._array[i];
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw OutOfRangeException();
	return _array[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

template <>
const char *Array<int>::OutOfRangeException::what() const throw()
{
	return "Index out of range";
}

template <>
const char *Array<float>::OutOfRangeException::what() const throw()
{
	return "Index out of range";
}

template <>
const char *Array<double>::OutOfRangeException::what() const throw()
{
	return "Index out of range";
}

template <>
const char *Array<std::string>::OutOfRangeException::what() const throw()
{
	return "Index out of range";
}

template class Array<int>;
template class Array<float>;
template class Array<double>;
template class Array<std::string>;