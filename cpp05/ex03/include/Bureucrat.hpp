#pragma once

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define WHITE "\x1b[37m"
#define RESET "\x1b[0m"
#include <string>
#include <iostream>
#include <fstream>
#include "AForm.hpp"

class AForm;

class Bureucrat
{
	private:
	const std::string _name;
	int _grade;

	public:
	// Orthodox Canonical Class AForm
	Bureucrat(std::string name, int grade);
	Bureucrat(const Bureucrat& other);
	Bureucrat& operator=(const Bureucrat& other);
	~Bureucrat( void );

	// Get and Setters
	void checkGrade(int grade) const;
	std::string getName(void) const;
	void setName( std::string name );

	int getGrade(void) const;
	void setGrade(int grade);

	void incrementGrade(void);
	void decrementGrade(void);
	void signForm(AForm &form);
	void executeForm(AForm const & form);
	class GradeTooHighException : public std::exception
	{
		public:
		virtual const char *what(void) const throw ();	
	};
	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char *what(void) const throw ();
	};
	Bureucrat& operator++(void);
	Bureucrat operator++(int);

	Bureucrat& operator--(void);
	Bureucrat operator--(int);
};

std::ostream& operator<<(std::ostream& out, const Bureucrat &bureucrat);
int check_debug(void);