#include "iter.hpp"
#include <algorithm>
template <typename T>
void printArray(T print)
{
	std::cout << print;
}

void oddOrEven(int i)
{
	std::cout << "The number " << i << " is ";
	if (i % 2 == 0)
		std::cout << "even!" << std::endl;
	else
		std::cout << "odd!" << std::endl;
}

int main(void)
{
	// print int
	int intArray[] = {1, 2, 3, 4, 5};
	::iter(intArray, 5, printArray<int>);
	std::cout << std::endl;
	// print string
	std::string stringArray[] = {"Hello", "World", "!\n"};
	::iter(stringArray, 3, printArray<std::string>);
	::iter(intArray, 5, oddOrEven);
}