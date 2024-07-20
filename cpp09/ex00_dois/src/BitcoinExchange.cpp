#include "BitcoinExchange.hpp"

void BitcoinExchange::_printMsg(std::string msg)
{
	#ifdef DEBUG
		std::cout << msg << std::endl;
	#endif
}

BitcoinExchange::BitcoinExchange()
{
	_printMsg("BitcoinExchange constructor called");
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	_printMsg("BitcoinExchange copy constructor called");
	*this = src;
}	


BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src)
{
	_printMsg("BitcoinExchange assignation operator called");
	if (this != &src)
	{
		this->_BitcoinDB = src._BitcoinDB;
		this->_BitcoinInput = src._BitcoinInput;
	}
	return *this;
}

BitcoinExchange::BitcoinExchangeException::BitcoinExchangeException(std::string message) : _message(message) {}

const char *BitcoinExchange::BitcoinExchangeException::what() const throw()
{
	return _message.c_str();
}

BitcoinExchange::BitcoinExchangeException::~BitcoinExchangeException() throw() {}


BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::_tableMonth(int month, int day, int year)
{
    if (month < 1 || month > 12)
    {
        return false;
    }

    switch (month)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return (day <= 31);
    case 4: case 6: case 9: case 11:
        return (day <= 30);
    case 2:
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        {
            return (day <= 29);
        }
        else
        {
            return (day <= 28);
        }
    default:
        return false;
    }
}


void BitcoinExchange::_validLine(std::string line)
{
	std::string date;
	std::string exchange_rate;
	std::stringstream ss(line);
	std::getline(ss, date, ',');
	std::getline(ss, exchange_rate, ',');
	if(date.empty() || exchange_rate.empty())
	{
		throw BitcoinExchange::BitcoinExchangeException("Invalid DB Line");
	}
	if(date.size() != 10)
		throw BitcoinExchange::BitcoinExchangeException("Invalid Date Format");
	if(exchange_rate.find_first_not_of("0123456789.") != std::string::npos)
		throw BitcoinExchange::BitcoinExchangeException("Invalid Exchange Rate Format");
	
	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());
	if(!_tableMonth(month, day, year))
		throw BitcoinExchange::BitcoinExchangeException("Invalid Date");
}

void BitcoinExchange::_validDBFile()
{
	std::ifstream file("files/data.csv");
	if(!file.is_open() || file.bad() || file.fail())
		throw BitcoinExchange::BitcoinExchangeException("Invalid DB File");
	std::string header;
	std::getline(file, header);
	if(header != "date,exchange_rate")
		throw BitcoinExchange::BitcoinExchangeException("Invalid DB Header");
	_BitcoinDB.clear();
	std::string line;
	while(std::getline(file, line))
	{
		if(line.empty())
			continue;
		_validLine(line);
		std::string date;
		std::string exchange_rate;
		std::stringstream ss(line);
		std::getline(ss, date, ',');
		std::getline(ss, exchange_rate, ',');
		date.erase(date.find_last_not_of(" \t\n\r\f\v") + 1);
		exchange_rate.erase(exchange_rate.find_last_not_of(" \t\n\r\f\v") + 1);
		_BitcoinDB[date] = exchange_rate;
	}
}


void BitcoinExchange::_validInputFile(std::string input)
{
	std::ifstream file(input.c_str());
	if(!file.is_open() || file.bad() || file.fail())
		throw BitcoinExchange::BitcoinExchangeException("Invalid Input File");
	std::string header;
	std::getline(file, header);
	if(header != "date | value")
		throw BitcoinExchange::BitcoinExchangeException("Invalid Input Header");
	_BitcoinInput.clear();
	std::string line;
	int i = 0;
	while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        std::string date;
        std::string value;
        std::stringstream ss(line);
        std::getline(ss, date, '|');
        std::getline(ss, value, '|');
        date.erase(date.find_last_not_of(" \t\n\r\f\v") + 1);
        value.erase(value.find_last_not_of(" \t\n\r\f\v") + 1);
        _BitcoinInput[i++] = std::make_pair(date, value);
    }
	std::cout << "-----------------" << std::endl;
}

void BitcoinExchange::_calculate(void)
{
    for (std::map<int, std::pair<std::string, std::string> >::const_iterator it = _BitcoinInput.begin(); it != _BitcoinInput.end(); ++it)
    {
        const std::string& date = it->second.first;
        const std::string& inputValue = it->second.second;
        std::map<std::string, std::string>::const_iterator dbIt = _BitcoinDB.lower_bound(date);
        if (dbIt == _BitcoinDB.end() || dbIt->first != date) {
            std::cout << date << " | " << inputValue << " | No data available" << std::endl;
        }
        else
        {
            double value = atof(inputValue.c_str());
            double rate = atof(dbIt->second.c_str());
            double result = value * rate;
            std::cout << date << " | " << inputValue << " | " << std::fixed << std::setprecision(2) << result << std::endl;
        }
    }
}
void BitcoinExchange::convert(std::string input)
{
	// Validate DB File
	// Validate header of the Input File
	_validDBFile();
	_validInputFile(input);
	//Calculate function that parser the input file and calculate the value in BTC
	//Print the result
	_calculate();
}