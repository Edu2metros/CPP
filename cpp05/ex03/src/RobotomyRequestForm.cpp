#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", ROBOTOMYGRADE, ROBOTOMYEXEC), _target(target)
{
	if(check_debug())
		std::cout << "Construtor for RobotomyRequestForm called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other.getTarget()) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if(this != &other)
		const_cast<std::string&>(this->_target) = other.getTarget();
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

void RobotomyRequestForm::execute(Bureucrat const & executor) const
{
	if(executor.getGrade() > getGradeExecute())
		throw(GradeExecException());
	else if(!getSigned())
		throw(NotSignedException());
	else
	{
		std::cout << "*drilling noises* ";
		if(rand() % 2)
			std::cout << getTarget() << " has been robotomized successfully by " << executor.getName() << std::endl;
		else
			std::cout << getTarget() << " has failed to be robotomized by " << executor.getName() << std::endl;
	}
}
