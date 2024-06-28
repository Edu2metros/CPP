#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", GRADE, EXEC), _target(target)
{
	if(check_debug())
		std::cout << "Construtor for RobotomyRequestForm called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other.getTarget())
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if(this != &other)
	{
		const_cast<std::string&>(this->_target) = other.getTarget();
	}
	return(*this);
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
	if(check_debug())
		std::cout << "Destrutor for class RobotomyRequestForm called!" << std::endl;
}

const std::string RobotomyRequestForm::getTarget(void) const
{
	return(_target);
}