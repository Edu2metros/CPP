#include "PmergeMe.hpp"

bool isalldigit(char *str)
{
	for(int i = 0; str[i]; i++)
	{
		if(!isdigit(str[i]))
			return false;
	}
	return true;
}

void valid(int argc, char **argv)
{
	if(argc < 2)
	{
		std::cout << "Usage: " << argv[0] << "[number1] [number2] ... [numberN]" << std::endl;
		exit(1);
	}
	for(int i = 1; i < argc; i++)
	{
		int number = atoi(argv[i]);
		if(!isalldigit(argv[i]))
		{
			std::cout << "Invalid input. The program only accept positive interger."
<< std::endl;
			exit(1);
		}
		if((number == 0 && strcmp(argv[i], "0") != 0) || number < 0)
		{
			std::cout << "Invalid input. The program only accept positive interger."
<< std::endl;
			exit(1);
		}
	}
}

int main(int argc, char **argv)
{
	valid(argc, argv);
	PmergeMe sort(argc, argv);
	sort.run();
	return 0;
}