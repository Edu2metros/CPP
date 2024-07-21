#pragma once

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <exception>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <algorithm>

typedef std::map<int, std::pair<std::string, std::string> >::const_iterator itMap;


class BitcoinExchange {
	private:
	std::map<int, std::pair<std::string, std::string> >_BitcoinDB; 
    std::map<int, std::pair<std::string, std::string> > _BitcoinInput;

	void _printMsg(std::string msg); 
	void _validDBFile();
	void _validLine(std::string line);
	void _validInputFile(std::string input);
	void _calculate(void); 
	bool _tableMonth(int month, int day, int year);

	public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &src);
	BitcoinExchange &operator=(BitcoinExchange const &src);
	~BitcoinExchange();
	itMap findDate(std::string date);
	void convert(std::string input);
	void findValue(std::string value);

	class BitcoinExchangeException : public std::exception
	{
		private:
		std::string _message;
		public:
		BitcoinExchangeException(std::string message);
		virtual const char *what() const throw();
		virtual ~BitcoinExchangeException() throw();
	};
};