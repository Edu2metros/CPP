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
    _BitcoinData.insert(std::make_pair(BitcoinDate, BitcoinValue));
}

void BitcoinExchange::setInputData(const std::string &date, const std::string &value)
{
    *_InputDate = date;
    *_InputValue = value;
}

BitcoinExchange::BitcoinExchange() : _InputDate(new std::string()), _InputValue(new std::string())
{
    if (checkDebug())
        std::cout << "BitcoinExchange constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _BitcoinData(other._BitcoinData), _InputDate(new std::string(*(other._InputDate))), _InputValue(new std::string(*(other._InputValue)))
{
    if (checkDebug())
        std::cout << "BitcoinExchange copy constructor called" << std::endl;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
    {
        _BitcoinData = other._BitcoinData;
        *_InputDate = *(other._InputDate);
        *_InputValue = *(other._InputValue);
    }
    
    if (checkDebug())
        std::cout << "BitcoinExchange copy assignment operator called" << std::endl;
    
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
    delete _InputDate;
    delete _InputValue;

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
        throw BitcoinExchangeException("Error !\nUsage: ./btc [file]");
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
    if (std::getline(file, line) && !line.empty())
    {
        *_InputDate = line.substr(0, line.find("|") - 1);
        *_InputValue = line.substr(line.find("|") + 2);
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
    data.open("/nfs/homes/eddos-sa/42sp/gitprojetos/cpp/cpp09/ex00/files/data.csv");
    if (!data.is_open())
    {
        throw BitcoinExchangeException("Error !\nCan't find the data.");
    }
    std::string header;
    if (!std::getline(data, header) || header != "date,exchange_rate")
    {
        std::cout << header << std::endl;
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
    if (date.size() != 10)
    {
        std::cout << date.size() << std::endl;
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

float BitcoinExchange::extractInputValue(const std::string& inputLine)
{
    std::string value_str = inputLine.substr(inputLine.find("|") + 1);
    std::stringstream ss(value_str);
    float value;
    if (!(ss >> value))
    {
        throw BitcoinExchangeException("Error !\nInvalid input value.");
    }
    return value;
}

std::string BitcoinExchange::findBitcoinValue(const std::string &date)
{
    validDateInput(date);
    auto it = _BitcoinData.lower_bound(std::make_pair(date, 0.0f));
    if (it == _BitcoinData.end() || it->first != date)
    {
        if (it != _BitcoinData.begin())
        {
            --it;
        }
        else
        {
            throw BitcoinExchangeException("Error !\nNo available date found.");
        }
    }

    float bitcoinValue = it->second;
    std::stringstream ss;
    ss << (bitcoinValue * getValue(*_InputValue));
    return ss.str();
}

void BitcoinExchange::calculate(void)
{
    try
    {
        std::string value = findBitcoinValue(*_InputDate);
        std::cout << *_InputDate << " | " << value << std::endl;
    }
    catch(const BitcoinExchangeException& e)
    {
        std::cerr << e.what() << std::endl;
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