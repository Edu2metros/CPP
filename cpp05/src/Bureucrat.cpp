#include "../include/Bureucrat.hpp"

Bureucrat::Bureucrat(std::string name, int grade)
{
	if(grade < 1)
		throw(GradeTooHighException());
	else if(grade > 150)
		throw(GradeTooLowException());
	else
		std::cout << "deu certo" << std::endl;
}

Bureucrat::Bureucrat(const Bureucrat& other)
{
	if(this != &other)
	{
		this->setName(other.getName());
		this->setGrade(other.getGrade());
	}
	std::cout << "Copy construtor called!" << std::endl;
}

Bureucrat& Bureucrat::operator=(const Bureucrat& other)
{
	if(this != &other)
	{
		this->setName(other.getName());
		this->setGrade(other.getGrade());
	}
	std::cout << "Overload operator copy called!" << std::endl;
	return(*this);
}

Bureucrat::~Bureucrat( void )
{
	std::cout << "Destrutor for: " << getName() << "called !" << std::endl; 
}

std::string Bureucrat::getName(void) const
{
	return(_name);
}

void Bureucrat::setName(std::string name)
{
	setName(name);
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
	std::cout << "entrou" << std::endl;
	return("Oh no! The Bureucrat can only have a grade bigger than 1.");
}

const char* Bureucrat::GradeTooLowException::what(void) const throw ()
{
	std::cout << "entrou" << std::endl;
	return("Oh no! The Bureucrat can only have a grade minus than 150");
}
