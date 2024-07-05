#pragma once

#include <string>
#include <iostream>

struct Data
{
	std::string s1;
	int n;
	std::string s2;
};

class Serializer
{
public:
	//Syntax Orthodox Canonical Form
	Serializer();
	Serializer(const Serializer& other);
	Serializer& operator=(const Serializer& other);
	~Serializer();

	//Methods
	uintptr_t serialize(Data *ptr);
	Data *deserialize(uintptr_t raw);
};