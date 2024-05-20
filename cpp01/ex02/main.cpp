#include <string>
#include <iostream>

int main(void)
{
	std::string brain = "HI THIS IS BRAIN";

	std::string* stringPTR = &brain;
	std::string& stringREF = brain;
	std::cout << "Memory adress Brain: " << &brain << std::endl;
	std::cout << "Memory adress: stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory adress: stringREF: " << &stringREF << std::endl;

	std::cout << std::endl;
	std::cout << "Value of Brain: " << brain << std::endl;
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;
	return(0);
}