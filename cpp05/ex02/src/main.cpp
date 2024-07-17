#include "../include/Bureucrat.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

int main(void) 
{
	// grade too low, same grade and grade ok
	std::cout << RED << "\nShruberry Tests" << RESET << std::endl;
	{
		// grade too low, same grade and grade ok
		ShrubberyCreationForm a("Palácio_da_Alvorada");
		std::cout << RED << "\nTest 1" << RESET << std::endl;
		Bureucrat b("JoseSarney", 146);
		Bureucrat c("Lula", 144);
		Bureucrat d("FHC", 136);
		b.signForm(a);
		b.executeForm(a);
		d.signForm(a);
		d.executeForm(a);
	}
	std::cout << GREEN << "\nRobotomy Tests" << RESET << std::endl;
	{
		RobotomyRequestForm a("Robotomy");
		Bureucrat b("Tiririca", 73);
		Bureucrat c("Bolsonaro", 72);
		Bureucrat d("Getulio Vargas", 44);

		std::cout << RED << "\nTiririca test" << RESET << std::endl;
		b.signForm(a);
		b.executeForm(a);
		std::cout << GREEN << "Bolsonaro test" << RESET << std::endl;
		c.signForm(a);
		c.executeForm(a);
		std::cout << BLUE << "Getulio Vargas test" << RESET << std::endl;
		d.signForm(a);
		d.executeForm(a);
	}
	std::cout << BLUE << "\nPresidential Tests" << RESET << std::endl;
	{
		PresidentialPardonForm a("Presidential");
		Bureucrat b("Lula", 26);
		Bureucrat c("Dilma", 25);
		Bureucrat d("Temer", 4);

		std::cout << RED << "\nLula test" << RESET << std::endl;
		b.signForm(a);
		b.executeForm(a);
		std::cout << GREEN << "Dilma test" << RESET << std::endl;
		c.signForm(a);
		c.executeForm(a);
		std::cout << BLUE << "Temer test" << RESET << std::endl;
		d.signForm(a);
		d.executeForm(a);
	}
	{
		// Try to execute a form that was not signed
		std::cout << RED << "\nTest 2" << RESET << std::endl;
		ShrubberyCreationForm a("Palácio_da_Alvorada");
		Bureucrat b("JoseSarney", 1);
		b.executeForm(a);
	}
	return 0;
}
