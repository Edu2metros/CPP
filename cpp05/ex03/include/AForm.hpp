#pragma once

#include "Bureucrat.hpp"

class Bureucrat;

class AForm
{
	private:
	AForm( void );
	const std::string _name;
	bool _signed;
	const int _gradeSign;
	const int _gradeExecute;

	public:
	AForm(std::string name, int gradeSign, int gradeExecute);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm( void );

	std::string getName(void) const;
	int getGradeSign(void) const;
	int getGradeExecute(void) const;
	bool getSigned(void) const;
	void beSigned(Bureucrat bureu);
	virtual void execute(Bureucrat const & executor) const;
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
	class NotSignedException : public std::exception
	{
		public:
		virtual const char *what(void) const throw ();
	};
	class GradeExecException : public std::exception
	{
		public:
		virtual const char *what(void) const throw ();
	};
};

std::ostream& operator<<(std::ostream& out, const AForm &AForm);
