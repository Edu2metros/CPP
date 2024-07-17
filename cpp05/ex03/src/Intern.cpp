#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
	if(check_debug())
		std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	if(check_debug())
		std::cout << "Intern copy constructor called" << std::endl;
	*this = copy;
}

Intern::~Intern()
{
	if(check_debug())
		std::cout << "Intern destructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &copy)
{
	if(check_debug())
		std::cout << "Intern assignation operator called" << std::endl;
	(void)copy;
	return (*this);
}

Intern::FormNotFoundException::FormNotFoundException(const char *msg) : _msg(msg) {}

const char *Intern::FormNotFoundException::what(void) const throw()
{
	return _msg;
}

static AForm *createPresidentialPardonForm(std::string target)
{
    return (new PresidentialPardonForm(target));
}

static AForm *createRobotomyRequestForm(std::string target)
{
    return (new RobotomyRequestForm(target));
}

static AForm *createShrubberyCreationForm(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeForm(std::string formName, std::string target) {
    std::string formNames[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    AForm* (*FunctionsRequest[3])(std::string) = {&createPresidentialPardonForm, &createRobotomyRequestForm, &createShrubberyCreationForm};
    for (int i = 0; i < 3; i++) {
        if (formName == formNames[i]) {
            return FunctionsRequest[i](target);
        }
    }
    throw std::runtime_error("Form not found! The options are: presidential pardon, robotomy request, shrubbery creation");
}


