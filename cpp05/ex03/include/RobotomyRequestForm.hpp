#pragma once

#include "AForm.hpp"

#define ROBOTOMYGRADE 72
#define ROBOTOMYEXEC 45

class RobotomyRequestForm : public AForm
{
	private:
	const std::string _target;

	public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	~RobotomyRequestForm( void );
	const std::string getTarget(void) const;
	void execute(Bureucrat const & executor) const;
};