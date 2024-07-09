#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>


template <typename T>
typename T::iterator easyfind(T &containerList, int value)
{
	typename T::iterator result = std::find(containerList.begin(), containerList.end(), value);
	if (result == containerList.end())
		throw std::string("Value not found");
	return result;
}