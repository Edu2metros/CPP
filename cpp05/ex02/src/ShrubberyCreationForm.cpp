#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", GRADE, EXEC), _target(target)
{
	if(check_debug())
		std::cout << "Construtor for ShrubberyCreationForm called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other.getTarget())
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if(this != &other)
	{
		const_cast<std::string&>(this->_target) = other.getTarget();
	}
	return(*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	if(check_debug())
		std::cout << "Destrutor for class ShrubberyCreationForm called!" << std::endl;
}

const std::string ShrubberyCreationForm::getTarget(void) const
{
	return(_target);
}