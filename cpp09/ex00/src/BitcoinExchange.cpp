#include "BitcoinExchange.hpp"

bool BitcoinExchange::checkDebug(void)
{
    #ifdef DEBUG
        return true;
    #else
        return false;
    #endif
}

void BitcoinExchange::insertBitcoinData(const std::string &BitcoinDate, float BitcoinValue)
{
    _BitcoinData[BitcoinDate] = BitcoinValue;
}

void BitcoinExchange::insertInputData(const std::string &date, const std::string &value)
{
    _InputData[date] = value;
}

BitcoinExchange::BitcoinExchange()
{
    if (checkDebug())
        std::cout << "BitcoinExchange constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    _BitcoinData = other._BitcoinData;
    _InputData = other._InputData;
    
    if (checkDebug())
        std::cout << "BitcoinExchange copy constructor called" << std::endl;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
    {
        _BitcoinData = other._BitcoinData;
        _InputData = other._InputData;
    }
    
    if (checkDebug())
        std::cout << "BitcoinExchange copy assignment operator called" << std::endl;
    
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
    if (checkDebug())
        std::cout << "BitcoinExchange destructor called" << std::endl;
}

BitcoinExchange::BitcoinExchangeException::~BitcoinExchangeException() throw()
{
    #ifdef DEBUG
        std::cout << "BitcoinExchangeException destructor called" << std::endl;
    #endif
}

BitcoinExchange::BitcoinExchangeException::BitcoinExchangeException(const std::string& message) : _message(message)
{
    #ifdef DEBUG
        std::cout << "BitcoinExchangeException constructor called" << std::endl;
    #endif
}

const char* BitcoinExchange::BitcoinExchangeException::what() const throw()
{
    return _message.c_str();
}

void BitcoinExchange::validInput(int argc, char **argv, std::ifstream &file)
{
    if (argc != 2)
    {
        throw BitcoinExchangeException("Error !\nUsage: ./BitcoinExchange [file]");
    }
    file.open(argv[1]);
    if (!file.is_open())
    {
        throw BitcoinExchangeException("Error !\nCan't find the file.");
    }
    std::string header;
    if (!std::getline(file, header) || header != "date | value")
    {
        throw BitcoinExchangeException("Error !\nInvalid file.");
    }
    std::string line;
    while (std::getline(file, line) && line != "")
    {
        std::string date = line.substr(0, line.find("|"));
        std::string value = line.substr(line.find("|") + 1);
        insertInputData(date, value);
    }
    file.close();
}

float BitcoinExchange::getValue(const std::string& value_str)
{
    if (value_str.empty())
    {
        throw BitcoinExchangeException("Error !\nInvalid value.");
    }

    for (size_t i = 0; i < value_str.size(); i++)
    {
        if (!isdigit(value_str[i]) && value_str[i] != '.')
        {
            std::cout << value_str << std::endl;
            throw BitcoinExchangeException("Error !\nInvalid value.");
        }
    }

    return atof(value_str.c_str());
}

bool BitcoinExchange::tableMonth(int month, int day, int year)
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

std::string BitcoinExchange::getDate(const std::string& date)
{
    if (date.size() != 10)
    {
        throw BitcoinExchangeException("Error !\nInvalid date format.");
    }

    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12)
    {
        throw BitcoinExchangeException("Error !\nInvalid month.");
    }

    if (!tableMonth(month, day, year))
    {
        throw BitcoinExchangeException("Error !\nInvalid day.");
    }

    return date;
}

void BitcoinExchange::validData(std::ifstream &data)
{
    data.open("/home/eddos-sa/projects/CPP/cpp09/ex00/files/data.csv");
    if (!data.is_open())
    {
        throw BitcoinExchangeException("Error !\nCan't find the data.");
    }
    std::string header;
    if (!std::getline(data, header) || header != "date,exchange_rate")
    {
        throw BitcoinExchangeException("Error !\nInvalid data.");
    }
    std::string line;
    while (std::getline(data, line) && line != "")
    {
        std::string date = getDate(line.substr(0, line.find(",")));
        float value = getValue(line.substr(line.find(",") + 1));
        insertBitcoinData(date, value);
    }
    data.close();
}

void BitcoinExchange::validDateInput(const std::string &date)
{
    std::cout << date << std::endl;
    if (date.size() != 10)
    {
        throw BitcoinExchangeException("Error !\nInvalid date format.");
    }
    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());
    if (month < 1 || month > 12)
    {
        throw BitcoinExchangeException("Error !\nInvalid month.");
    }
    if (!tableMonth(month, day, year))
    {
        throw BitcoinExchangeException("Error !\nInvalid day.");
    }
}

std::string BitcoinExchange::findBitcoinValue(const std::string &date)
{
    validDateInput(date);
    std::map<std::string, float>::iterator it = _BitcoinData.lower_bound(date);
    if (it != _BitcoinData.end() && it->first == date)
    {
        std::stringstream ss;
        ss << it->second;
        return ss.str();
    }
    else
    {
        if (it != _BitcoinData.begin())
        {
            --it;
            std::stringstream ss;
            ss << it->second;
            return ss.str();
        }
        else
        {
            throw BitcoinExchangeException("Error !\nNo available date found.");
        }
    }
}

void BitcoinExchange::calculate(void)
{
    for(std::map<std::string, std::string>::iterator it = _InputData.begin(); it != _InputData.end(); ++it)
    {
        try
        {
            std::string value = findBitcoinValue(it->first);
            std::cout << it->first << " | " << value << std::endl;
        }
        catch(const BitcoinExchangeException& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}

void BitcoinExchange::convert(int argc, char **argv)
{
    std::ifstream file;
    std::ifstream data;
    validInput(argc, argv, file);
    validData(data);
    calculate();
}
