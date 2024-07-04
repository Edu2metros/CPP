#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", PresidentialGrade, PresidentialExec), _target(target)
{
	if(check_debug())
		std::cout << "Construtor for PresidentialPardonForm called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), _target(other.getTarget()) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if(this != &other)
		const_cast<std::string&>(this->_target) = other.getTarget();
	return(*this);
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	if(check_debug())
		std::cout << "Destrutor for class PresidentialPardonForm called!" << std::endl;
}

const std::string PresidentialPardonForm::getTarget(void) const
{
	return(_target);
}

void PresidentialPardonForm::execute(Bureucrat const & executor) const
{
	if(executor.getGrade() > getGradeExecute())
		throw(GradeTooLowException());
	else if(!getSigned())
		throw(NotSignedException());
	else
		std::cout << getTarget() << " has been pardoned by " << executor.getName() << std::endl;
}
