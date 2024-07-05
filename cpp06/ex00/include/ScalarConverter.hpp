#pragma once
#include <iostream>
#include <string>

#define RED(text) "\033[31m" + std::string(text) + "\033[0m"
#define GREEN(text) "\033[32m" text "\033[0m"
#define YELLOW(text) "\033[33m" text "\033[0m"
#define BLUE(text) "\033[34m" text "\033[0m"


class ScalarConverter
{
	private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);

public:
	~ScalarConverter();
	ScalarConverter &operator=(const ScalarConverter &other);

	static void convert(const std::string &input);
	class ImpossibleConversionException : public std::exception
	{
		private:
		std::string _message;
		public:
		ImpossibleConversionException(const std::string &message);
		virtual const char *what() const throw();
	};	
};