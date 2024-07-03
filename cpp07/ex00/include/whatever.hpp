#define pragma_once

#include <iostream>
#include <string>

template <typename T>
void swap(T& param1, T& param2)
{
	T temp = param1;
	param1 = param2;
	param2 = temp;
}
template <typename T>
T min(T& param1, T& param2)
{
	if(param2 > param1)
		return param1;
	return param2;
}

template <typename T>
T max(T& param1, T& param2)
{
	if(param2 < param1)
		return param1;
	return param2;
}