#include "ScalarConverter.hpp"

int main(void)
{
	std::cout << RED("Tests for : 42") << std::endl;
	ScalarConverter::convert("42");
	std::cout << std::endl;
	std::cout << RED("Tests for : 42.0") << std::endl;
	ScalarConverter::convert("42.0");
	std::cout << std::endl;
	//Tests errors
	std::cout << RED("Tests for : nan") << std::endl;
	ScalarConverter::convert("nan");
	std::cout << std::endl;
	std::cout << RED("Tests for : something") << std::endl;
	ScalarConverter::convert("something");
	std::cout << std::endl;
	std::cout << RED("Tests for : 2147483648") << std::endl; // INT_MAX + 1 
	ScalarConverter::convert("2147483648");
	std::cout << std::endl;
	std::cout << RED("Tests for : 0") << std::endl;
	ScalarConverter::convert("0");
	std::cout << std::endl;
	std::cout << RED("Tests for : 220") << std::endl;
	ScalarConverter::convert("220");
	std::cout << std::endl;
	std::cout << RED("Tests for : 0") << std::endl;
	ScalarConverter::convert("0");
	std::cout << std::endl;
	return(0);
}