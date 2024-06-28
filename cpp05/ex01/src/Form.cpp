#include "../include/Form.hpp"

Form::Form(std::string name, int gradeSign, int gradeExecute) : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
	if(check_debug())
		std::cout << "Construtor for Form called" << std::endl;
	if(_gradeSign < 1 || _gradeExecute < 1)
		throw(GradeTooHighException());
	else if(_gradeSign > 150 || _gradeExecute > 150)
		throw(GradeTooLowException());
}

Form::Form(const Form& other) : _name(other.getName()), _gradeSign(other.getGradeSign()), _gradeExecute(other.getGradeExecute())
{
	_signed = other.getSigned();
}

Form& Form::operator=(const Form& other)
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

Form::~Form( void )
{
	if(check_debug())
		std::cout << "Destrutor for class Form called!" << std::endl;
}

std::string Form::getName(void) const
{
	return(_name);
}

int Form::getGradeSign(void) const
{
	return(_gradeSign);
}

int Form::getGradeExecute(void) const
{
	return(_gradeExecute);
}

bool Form::getSigned(void) const
{
	return(_signed);
}

const char* Form::GradeTooHighException::what(void) const throw ()
{
	return("Grade Too High Exception error.");
}

const char* Form::GradeTooLowException::what(void) const throw ()
{
	return("Grade Too Low Exception error.");
}

std::ostream& operator<<(std::ostream& out, const Form &form)
{
	std::string signedForm = form.getSigned() ? "true" : "false";
	out << form.getName() << ", form grade to sign " << form.getGradeSign() << ", form grade to execute " << form.getGradeExecute() << ", form is signed: " << signedForm;
	return(out);
}

void Form::beSigned(Bureucrat GetulioVargas)
{
	if(GetulioVargas.getGrade() > _gradeSign)
		throw GradeTooLowException();
	_signed = true;
}


