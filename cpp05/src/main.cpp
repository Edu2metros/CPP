#include "../include/Bureucrat.hpp"

int main(void)
{
	try //Test initialization with grade too high
	{
		std::cout << "Test 1" << std::endl;
		Bureucrat Tiririca("Tiririca", 0);
	}
	catch (std::exception & e)
	{
		std::cerr << RED << "error: " << e.what() << RESET << std::endl;
	}
	try //Test initialization with grade too low
	{
		std::cout << "Test 2" << std::endl;
		Bureucrat Tiririca("Tiririca", 151);
	}
	catch (std::exception & e)
	{
		std::cerr << RED << "error: " << e.what() << RESET << std::endl;
	}
	try //Test with minimum grade
	{
		std::cout << "Test 3" << std::endl;
		Bureucrat Tiririca("Tiririca", 148);
		std::cout << Tiririca << std::endl;
		Tiririca--;
		std::cout << Tiririca << std::endl;
		Tiririca.decrementGrade();
		std::cout << Tiririca << std::endl;
		Tiririca--;
		std::cout << "AAAAAAAAAAAAAAAAA" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << RED << "error: " << e.what() << RESET << std::endl;
	}
	try //Test with maximum grade
	{
		std::cout << "Test 4" << std::endl;
		Bureucrat Tiririca("Tiririca", 3);
		Tiririca++;
		std::cout << Tiririca << std::endl;
		Tiririca.incrementGrade();
		std::cout << Tiririca << std::endl;
		Tiririca++;
		std::cout << "AAAAAAAAAAAAAAAAA" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << RED << "error: " << e.what() << RESET << std::endl;
	}
}