#pragma once

#define RED(text) "\x1b[31m" text "\x1b[0m"

#include <string>
#include <iostream>

class Bureucrat
{
	private:
	const std::string _name;
	int _grade;

	public:
	// Orthodox Canonical Class Form
	Bureucrat(std::string name, int grade);
	Bureucrat(const Bureucrat& other);
	Bureucrat& operator=(const Bureucrat& other);
	~Bureucrat( void );

	// Get and Setters
	std::string getName(void) const;
	void setName( std::string name );

	int getGrade(void) const;
	void setGrade(int grade);
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