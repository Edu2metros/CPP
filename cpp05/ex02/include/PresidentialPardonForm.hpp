#pragma once

#include "AForm.hpp"

#define PresidentialGrade 25
#define PresidentialExec 5

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
	void execute(Bureucrat const & executor) const;
};