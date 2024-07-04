#pragma once

#include "Bureucrat.hpp"
#include "AForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern &copy);
	~Intern();
	Intern &operator=(const Intern &copy);

	AForm *makeForm(std::string formName, std::string target);
	class FormNotFoundException : public std::exception
	{
		private:
		const char *_msg;
		public:
		FormNotFoundException(const char *msg);
		virtual const char *what(void) const throw();
	};
};