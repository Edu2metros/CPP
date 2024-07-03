#include "Array.hpp"

int main(void)
{
	// Test 1: Fill array and print
	{
		Array<int> a(5);
		for(unsigned int i = 0; i < a.size(); i++)
			a[i] = i;
		for(unsigned int i = 0; i < a.size(); i++)
			std::cout << a[i] << " ";
		std::cout << std::endl;
	}
	// Test 2: Create an array of string and print
	{
		Array<std::string> a(3);
		a[0] = "Hello";
		a[1] = "World";
		a[2] = "!";
		for(unsigned int i = 0; i < a.size(); i++)
			std::cout << a[i] << " ";
		std::cout << std::endl;
	}
	// Test 3: Copy an array and print
	{
		Array<int> a(5);
		for(unsigned int i = 0; i < a.size(); i++)
			a[i] = i;
		Array<int> b(a);
		for(unsigned int i = 0; i < b.size(); i++)
			std::cout << b[i] << " ";
		std::cout << std::endl;
	}
}