#include "../include/Bureucrat.hpp"

int check_debug(void)
{
	#ifndef DEBUG
		return(0);
	#else
		return(1);
	#endif
}

Bureucrat::Bureucrat(std::string name, int grade) : _name(name)
{
	if(check_debug())
		std::cout << "Construtor called!" << std::endl;
	if(grade < 1)
		throw(GradeTooHighException());
	else if(grade > 150)
		throw(GradeTooLowException());
	_grade = grade;
}

Bureucrat::Bureucrat(const Bureucrat& other)
{
	if(this != &other)
	{
		const_cast<std::string&>(this->_name) = other.getName();
		this->_grade = other.getGrade();
	}
	if(check_debug())
		std::cout << "Copy construtor called!" << std::endl;
}

Bureucrat& Bureucrat::operator=(const Bureucrat& other)
{
	if(this != &other)
	{
		const_cast<std::string&>(this->_name) = other.getName();
		this->_grade = other.getGrade();
	}
	if(check_debug())
		std::cout << "Overload operator copy called!" << std::endl;
	return(*this);
}

Bureucrat::~Bureucrat( void )
{
	if(check_debug())
		std::cout << "Destrutor for: " << getName() << " called !" << std::endl; 
}

std::string Bureucrat::getName(void) const
{
	return(_name);
}

void Bureucrat::setName(std::string name)
{
	const_cast<std::string&>(_name) = name;
}

int Bureucrat::getGrade(void) const
{
	return(_grade);
}

void Bureucrat::setGrade(int grade)
{
	_grade = grade;
}

const char* Bureucrat::GradeTooHighException::what(void) const throw ()
{
	return("The Bureucrat can only have a grade bigger than 1.");
}

const char* Bureucrat::GradeTooLowException::what(void) const throw ()
{
	return("The Bureucrat can only have a grade minus than 150");
}

std::ostream& operator<<(std::ostream &out, const Bureucrat &bureucrat)
{
	out << bureucrat.getName() << ", bureucrat grade " << bureucrat.getGrade();
	return(out);
}

void Bureucrat::checkGrade(int grade) const
{
	if(grade < 1)
		throw(Bureucrat::GradeTooHighException());
	else if(grade > 150)
		throw(Bureucrat::GradeTooLowException());
	return;
}

void Bureucrat::incrementGrade(void)
{
	checkGrade(_grade - 1);
	_grade--;
}

void Bureucrat::decrementGrade(void)
{
	checkGrade(_grade + 1);
	_grade++;
}

Bureucrat& Bureucrat::operator++(void)
{
	checkGrade(_grade - 1);
	_grade--;
	return(*this);
}

Bureucrat Bureucrat::operator++(int)
{
	Bureucrat tmp(*this);
	++(*this);
	return(tmp);
}

Bureucrat& Bureucrat::operator--(void)
{
	checkGrade(_grade + 1);
	_grade++;
	return(*this);
}

Bureucrat Bureucrat::operator--(int)
{
	Bureucrat tmp(*this);
	--(*this);
	return(tmp);
}

void Bureucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << "Form " << form.getName() << " signed successfully!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Failed to sign form " << form.getName() << ": " << e.what() << std::endl;
	}
}
