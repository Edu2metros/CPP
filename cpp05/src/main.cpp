#include "../include/Bureucrat.hpp"

int main(void)
{
	try
	{
		Bureucrat Tiririca("nome", 151);	
	}
	catch (std::exception & e)
	{
		std::cerr << RED("erro: ") << e.what() << std::endl;
	}
}