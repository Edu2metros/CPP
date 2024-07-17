#pragma once

#include <iostream>
#include <string>
#include <set>
#include <fstream>

class BitcoinExchange {
	private:
	std::set<std::string> _BitcoinDateDB;
	std::set<float> _BitcoinPriceDB;	
	std::string *_BitcoinDateInput;
	float *_BitcoinPriceInput;
	bool checkDebug(void);

	public:
	BitcoinExchange(std::ifstream &file);
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange(void);

	class BitcoinExchangeException : public std::exception
	{
		private:
		std::string _message;
		public:
		BitcoinExchangeException(std::string message);
		virtual const char *what() const throw();
		virtual ~BitcoinExchangeException() throw();
	}
};