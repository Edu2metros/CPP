#pragma once

#include "AForm.hpp"
#include "Bureucrat.hpp"

#define ShubberyGrade 145
#define ShubberyExec 137

class ShrubberyCreationForm : public AForm
{
	private:
	const std::string _target;

	public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm( void );
	const std::string getTarget(void) const;
	void execute(Bureucrat const & executor) const;
	class FileNotOpenedException : public std::exception
	{
		public:
		virtual const char* what() const throw();
	};
};