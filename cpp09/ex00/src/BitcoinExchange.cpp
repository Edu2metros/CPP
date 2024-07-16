#include "BitcoinExchange.hpp"

static bool checkDebug(void)
{
    #ifdef DEBUG
        return true;
    #else
        return false;
    #endif
}

BitcoinExchange::BitcoinExchange()
{
    if (checkDebug())
        std::cout << "BitcoinExchange constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    if (checkDebug())
        std::cout << "BitcoinExchange copy constructor called" << std::endl;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (checkDebug())
        std::cout << "BitcoinExchange copy assignment operator called" << std::endl;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
    if (checkDebug())
        std::cout << "BitcoinExchange destructor called" << std::endl;
}

BitcoinExchange::BitcoinExchangeException::BitcoinExchangeException(const std::string& message) : message(message)
{
    if (checkDebug())
        std::cout << "BitcoinExchangeException constructor called" << std::endl;
}

const char* BitcoinExchange::BitcoinExchangeException::what() const noexcept
{
    return (message.c_str());
}

std::ofstream validArgs(int argc, char **argv)
{
    if(argc != 2)
    {
        throw(BitcoinExchange::
BitcoinExchangeException("Error with parameters!\n Please use this program for example: <./btc files/input.txt>"));
    }
    std::ofstream file(argv[1]);
    if(!file.is_open())
    {
        throw(BitcoinExchange::
BitcoinExchangeException("Error !\nCan't find the input."));
    }
    return(file);
}

#define exception(text) BitcoinExchange::ExchangeException(text);

std::ofstream searchData(void)
{
    std::ofstream data("files/data.csv");
    if(!data.is_open())
    {
        throw(exception("test"));
    }
    return(data);
}

void BitcoinExchange::convert(int argc, char **argv)
{
    std::ofstream input = validArgs(argc, argv);
    std::ofstream data = searchData();
}