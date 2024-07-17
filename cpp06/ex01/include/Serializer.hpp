#pragma once

#include "Data.hpp"

typedef unsigned int *uintptr_t;
class Serializer
{
private:
	//Syntax Orthodox Canonical Form
	Serializer();
	Serializer(const Serializer& other);
	Serializer& operator=(const Serializer& other);
	~Serializer();
public:
	//Methods
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};