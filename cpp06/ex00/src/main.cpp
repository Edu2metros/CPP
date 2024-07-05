#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if(argc == 1)
	{
		std::cerr << "Too few arguments! Please use: ./convert [args]" << std::endl;
		return(1);
	}
	for(int i = 1; i < argc; i++)
	{
		std::cout << RED("Converting: ") << RED(argv[i]) << std::endl;
		ScalarConverter::convert(argv[i]);
	}
	return(0);
}