#pragma once

#include "AForm.hpp"
#include "Bureucrat.hpp"

#define GRADE 145
#define EXEC 137

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
};