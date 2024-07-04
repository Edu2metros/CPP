#include "../include/AForm.hpp"

AForm::AForm( void ) : _name("AForm"), _signed(false), _gradeSign(1), _gradeExecute(1)
{
	if(check_debug())
		std::cout << "Construtor for AForm called" << std::endl;
}

AForm::AForm(std::string name, int gradeSign, int gradeExecute) : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
	if(check_debug())
		std::cout << "Construtor for AForm called" << std::endl;
	if(_gradeSign < 1 || _gradeExecute < 1)
		throw(GradeTooHighException());
	else if(_gradeSign > 150 || _gradeExecute > 150)
		throw(GradeTooLowException());
}

AForm::AForm(const AForm& other) : _name(other.getName()), _gradeSign(other.getGradeSign()), _gradeExecute(other.getGradeExecute())
{
	_signed = other.getSigned();
}

AForm& AForm::operator=(const AForm& other)
{
	if(this != &other)
	{
		const_cast<std::string&>(this->_name) = other.getName();
		const_cast<int&>(this->_gradeSign) = other.getGradeSign();
		const_cast<int&>(this->_gradeExecute) = other.getGradeExecute();
		_signed = other.getSigned();
	}
	return(*this);
}

AForm::~AForm( void )
{
	if(check_debug())
		std::cout << "Destrutor for class AForm called!" << std::endl;
}

std::string AForm::getName(void) const
{
	return(_name);
}

int AForm::getGradeSign(void) const
{
	return(_gradeSign);
}

int AForm::getGradeExecute(void) const
{
	return(_gradeExecute);
}

bool AForm::getSigned(void) const
{
	return(_signed);
}

const char* AForm::GradeTooHighException::what(void) const throw ()
{
	return("Error: The AForm can only have a grade bigger than ");
}

const char* AForm::GradeTooLowException::what(void) const throw ()
{
	return("The AForm can only have a grade minus than ");
}

const char* AForm::NotSignedException::what(void) const throw ()
{
	return("The AForm is not signed. Your grade is: ");
}

std::ostream& operator<<(std::ostream& out, const AForm &Aform)
{
	out << Aform.getName() << ", Aform grade to sign " << Aform.getGradeSign()\
<< ", Aform grade to execute " << Aform.getGradeExecute() << ", Aform is signed " << Aform.getSigned();
	return(out);
}

void AForm::beSigned(Bureucrat GetulioVargas)
{
	if(_gradeSign < GetulioVargas.getGrade())
		throw GradeTooLowException();
	_signed = true;
}

void AForm::execute(Bureucrat const & executor) const
{
	if(executor.getGrade() > _gradeExecute)
		throw GradeTooLowException();
	else if(!getSigned())
		throw NotSignedException();
}
