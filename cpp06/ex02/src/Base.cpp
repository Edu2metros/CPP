#include "Base.hpp"

bool checkDebug(void)
{
	#ifdef DEBUG
		return true;
	#else
		return false;
	#endif
}

Base::~Base()
{
	if (checkDebug())
		std::cout << "Base destructor called" << std::endl;
}
