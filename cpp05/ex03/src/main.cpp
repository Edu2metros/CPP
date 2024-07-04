#include "../include/Bureucrat.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void) 
{
	Intern intern;
	Bureucrat b("bureucrat", 1);

	try
	{
		std::cout << RED << "Shubbery Creation" << RESET << std::endl;
		AForm *form = intern.makeForm("shrubbery creation", "target");
		form->beSigned(b);
		form->execute(b);
		delete form;
		std::cout << RED << "\nError test" << RESET << std::endl;
		form = intern.makeForm("error", "target");
		delete form;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
