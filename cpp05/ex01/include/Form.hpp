#pragma once

#include "Bureucrat.hpp"

class Bureucrat;

class Form
{
	private:
	const std::string _name;
	bool _signed;
	const int _gradeSign;
	const int _gradeExecute;

	public:
	Form(std::string name, int gradeSign, int gradeExecute);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form( void );

	std::string getName(void) const;
	int getGradeSign(void) const;
	int getGradeExecute(void) const;
	bool getSigned(void) const;
	void beSigned(Bureucrat bureu);
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
};

std::ostream& operator<<(std::ostream& out, const Form &form);
