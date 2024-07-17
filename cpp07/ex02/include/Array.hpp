#pragma once

#include <iostream>
#include <string>

template <typename T>
class Array
{
private:
	T* _array;
	unsigned int _size;

public:
	Array();
	Array(unsigned int n);
	Array(const Array& copy);
	~Array();
	Array& operator=(const Array& copy);
	T& operator[](unsigned int index);
	unsigned int size() const;

	class OutOfRangeException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};