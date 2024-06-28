#pragma once

#include "AForm.hpp"

#define GRADE 25
#define EXEC 5

class PresidentialPardonForm : public AForm
{
	private:
	const std::string _target;

	public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	~PresidentialPardonForm( void );
	const std::string getTarget(void) const;
};