#include "Serializer.hpp"

bool checkDebug(void)
{
	#ifdef DEBUG
		return true;
	#else
		return false;
	#endif
}

Serializer::Serializer()
{
	if (checkDebug())
		std::cout << "Serializer constructor called" << std::endl;
}

Serializer::Serializer(const Serializer& other)
{
	if (checkDebug())
		std::cout << "Serializer copy constructor called" << std::endl;
	*this = other;
}

Serializer& Serializer::operator=(const Serializer& other)
{
	if (checkDebug())
		std::cout << "Serializer operator= called" << std::endl;
	(void)other;
	return *this;
}

Serializer::~Serializer()
{
	if (checkDebug())
		std::cout << "Serializer destructor called" << std::endl;
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return(reinterpret_cast<Data *>(raw));
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return(reinterpret_cast<uintptr_t>(ptr));
}
