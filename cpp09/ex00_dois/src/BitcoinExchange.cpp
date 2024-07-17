#include "BitcoinExchange.hpp"

bool BitcoinExchange::checkDebug(void) 
{
	#ifdef DEBUG
		return true;
	#else
		return false;
	#endif
}

BitcoinExchange::BitcoinExchange(std::ifstream &input) 
{
	if(checkDebug()) 
	{
		std::cout << "BitcoinExchange construtor called" << std::endl;
	}
 // alloca a quantidade de linhas que tem input
	for(std::string line; std::getline(input, line);) 
	{
		_BitcoinDateInput = new std::string;
		_BitcoinPriceInput = new float;
	}
}