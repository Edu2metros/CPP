#include "PmergeMe.hpp"

void valid(int argc, char **argv)
{
	if(argc < 2)
	{
		std::cout << "Usage: " << argv[0] << "[number1] [number2] ... [numberN]" << std::endl;
		exit(1);
	}
	// aceitar o 0
	for(int i = 1; i < argc; i++)
	{
		if(atoi(argv[i]) == 0 && strcmp(argv[i], "0") != 0)
		{
			std::cout << "Invalid input. The program only accept positive interger."
<< std::endl;
			exit(1);
		}
	}
}

int main(int argc, char **argv)
{
	// validação
	// dividir em dois
	// merge
	// imprimir

	valid(argc, argv);
	PmergeMe sort(argc, argv);
	sort.run();
	return 0;
}