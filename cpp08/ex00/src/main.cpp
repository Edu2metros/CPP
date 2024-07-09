#include "easyfind.hpp"

int main()
{
	std::vector<int> vec;
	for(int i = 9; i > 0; i --)
		vec.push_back(i);
	try
	{
		std::vector<int>::iterator it = easyfind(vec, 1);
		std::cout << "Value found: " << *it << std::endl;
	}
	catch (std::string &e)
	{
		std::cout << e << std::endl;
	}
	try
	{
		std::vector<int>::iterator it = easyfind(vec, 10);
		std::cout << "Value found: " << *it << std::endl;
	}
	catch (std::string &e)
	{
		std::cout << e << std::endl;
	}
	return 0;
}