#include "../include/Bureucrat.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

void shruberryTests() {
  {
    ShrubberyCreationForm a("garden");
	std::cout << RED << "\nTest 1" << RESET << std::endl;
    Bureucrat b("JoseSarney", 146);
    Bureucrat c("FHC", 144);
    b.signForm(a);
    b.executeForm(a);
	c.signForm(a);
	c.executeForm(a);
  }
}

void robotomyTests() {
  {
    RobotomyRequestForm a("Robotomy");
    Bureucrat b("Tiririca", 73);
	Bureucrat c("Bolsonaro", 72);
	Bureucrat d("Lula", 5);
	
	std::cout << RED << "\nTiririca test" << RESET << std::endl;
	b.signForm(a);
	b.executeForm(a);
	std::cout << GREEN << "Bolsonaro test" << RESET << std::endl;
	c.signForm(a);
	c.executeForm(a);
	std::cout << BLUE << "Lula test" << RESET << std::endl;
	d.signForm(a);
	d.executeForm(a);
  }
}

void presidentialTests() {
  {
    PresidentialPardonForm a("Sérgio Cabral");
    Bureucrat b("justice", 73);

    b.signForm(a);
    b.executeForm(a);
  }
  {
    PresidentialPardonForm a("Aécio Neves");
    Bureucrat b("Joesley Batista", 48);

    b.signForm(a);
    b.executeForm(a);
  }
  {
    PresidentialPardonForm a("Tiririca");
    Bureucrat b("Bolsonaro", 42);
    Bureucrat c("Lula", 5);

    b.signForm(a);
    c.executeForm(a);
  }
}

int main(void) 
{
	std::cout << RED << "\nShruberry Tests" << RESET << std::endl;
	shruberryTests();
	std::cout << GREEN << "\nRobotomy Tests" << RESET << std::endl;
	robotomyTests();
	std::cout << BLUE << "\nPresidential Tests" << RESET << std::endl;
	presidentialTests();

	return 0;
}
