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
	int i = 0;
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
		_BitcoinDB[i++] = std::make_pair(date, exchange_rate);
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
}

itMap BitcoinExchange::findDate(std::string date)
{
	if(date.find_first_not_of("0123456789-") != std::string::npos)
		throw BitcoinExchange::BitcoinExchangeException("Invalid Date Format");
	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());
	if(!_tableMonth(month, day, year))
		throw BitcoinExchange::BitcoinExchangeException("Invalid Date");
	itMap it = _BitcoinDB.begin();
	while(it != _BitcoinDB.end())
	{
		if(it->second.first == date)
			return it;
		it++;
	}
	while(true)
	{
		if(_tableMonth(month, day, year))
		{
			std::stringstream ss;
			ss << std::setfill('0') << std::setw(4) << year << "-" << std::setfill('0') << std::setw(2) << month << "-" << std::setfill('0') << std::setw(2) << day;
			date = ss.str();
			it = _BitcoinDB.begin();
			while(it != _BitcoinDB.end())
			{
				if(it->second.first == date)
					return it;
				it++;
			}
		}
		if(day == 1)
		{
			if(month == 1)
			{
				year--;
				month = 12;
				day = 31;
			}
			else
			{
				month--;
				day = 31;
			}
		}
		else
			day--;
		if(year < 2009)
			throw BitcoinExchange::BitcoinExchangeException("Date not found");
	}
}

void BitcoinExchange::findValue(std::string value)
{
    value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());
	if(value.find_first_not_of("0123456789.") != std::string::npos)
		throw BitcoinExchange::BitcoinExchangeException("Invalid Value Format");
    if (value.empty())
        throw BitcoinExchange::BitcoinExchangeException("Inexistent Value");
    float val = atof(value.c_str());
    if (val < 0)
        throw BitcoinExchange::BitcoinExchangeException("Error: not a positive value.");
    if (val > 1000)
        throw BitcoinExchange::BitcoinExchangeException("Error: too large a number.");
}


void BitcoinExchange::_calculate(void)
{
	itMap itInput = _BitcoinInput.begin();
	while(itInput != _BitcoinInput.end())
	{
		try
		{
			findValue(itInput->second.second);
			std::string dateInput = itInput->second.first;
			itMap itDB = findDate(dateInput);
			float result = atof(itDB->second.second.c_str()) * atof(itInput->second.second.c_str());
			std::cout << itInput->second.first << " =>" << itInput->second.second << " = " << result << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		itInput++;
	}
}
void BitcoinExchange::convert(std::string input)
{
	_validDBFile();
	_validInputFile(input);
	_calculate();
}