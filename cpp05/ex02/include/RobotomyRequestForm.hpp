#pragma once

#include "AForm.hpp"

#define GRADE 72
#define EXEC 45

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
};