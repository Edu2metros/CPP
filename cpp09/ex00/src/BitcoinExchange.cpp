#include "BitcoinExchange.hpp"

bool BitcoinExchange::checkDebug(void)
{
    #ifdef DEBUG
        return true;
    #else
        return false;
    #endif
}

void BitcoinExchange::insertBitcoinDate(std::string &BitcoinDate)
{
    _BitcoinDate.insert(BitcoinDate);
}

void BitcoinExchange::insertBitcoinValue(float BitcoinValue)
{
    _BitcoinValue.insert(BitcoinValue);
}

void BitcoinExchange::insertInputDate(std::string &date)
{
    _InputDate.insert(date);
}

void BitcoinExchange::insertInputValue(float value)
{
    _InputValue.insert(value);
}

BitcoinExchange::BitcoinExchange()
{
    if (checkDebug())
        std::cout << "BitcoinExchange constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    (void)other;
    if (checkDebug())
        std::cout << "BitcoinExchange copy constructor called" << std::endl;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    (void)other;
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
    return (_message.c_str());
}

void BitcoinExchange::validInput(int argc, char **argv, std::ifstream &file)
{
    if(argc != 2)
    {
        throw(BitcoinExchangeException("Error !\nUsage: ./BitcoinExchange [file]"));
    }
    file.open(argv[1]);
    if(!file.is_open())
    {
        throw(BitcoinExchangeException("Error !\nCan't find the file."));
    }
    std::string header;
    if(!std::getline(file, header) || header != "date | value")
    {
        throw(BitcoinExchangeException("Error !\nInvalid file."));
    }
    std::string line;
    while(std::getline(file, line) && line != "")
    {
        std::string date = line.substr(0, line.find("|"));
        float value = getValue(line.substr(line.find("|") + 1));
        insertInputDate(date);
        insertInputValue(value);
    }
    file.close();
}

float BitcoinExchange::getValue(const std::string& value_str) 
{
    if (value_str.empty()) {
        throw BitcoinExchangeException("Error !\nInvalid value.");
    }

    for (size_t i = 0; i < value_str.size(); i++) {
        if (!isdigit(value_str[i]) && value_str[i] != '.') {
            throw BitcoinExchangeException("Error !\nInvalid value.");
        }
    }

    return atof(value_str.c_str());
}

bool BitcoinExchange::tableMonth(int month, int day, int year) 
{
    if (month < 1 || month > 12) {
        return false;
    }

    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return (day <= 31);
        case 4: case 6: case 9: case 11:
            return (day <= 30);
        case 2:
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
                return (day <= 29);
            } else {
                return (day <= 28);
            }
        default:
            return false;
    }
}

std::string BitcoinExchange::getDate(const std::string& date) 
{
    if (date.size() != 10) {
        throw BitcoinExchangeException("Error !\nInvalid date format.");
    }

    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12) {
        throw BitcoinExchangeException("Error !\nInvalid month.");
    }

    if (!tableMonth(month, day, year)) {
        throw BitcoinExchangeException("Error !\nInvalid day.");
    }

    return date;
}

void BitcoinExchange::validData(std::ifstream &data)
{
    data.open("files/data.csv");
    if(!data.is_open())
    {
        throw(BitcoinExchangeException("Error !\nCan't find the data."));
    }
    std::string header;
    if(!std::getline(data, header) || header != "date,exchange_rate")
    {
        throw(BitcoinExchangeException("Error !\nInvalid data."));
    }
    std::string line;
    while(std::getline(data, line) && line != "")
    {
        std::string date = getDate(line.substr(0, line.find(",")));
        float value = getValue(line.substr(line.find(",") + 1));
        insertBitcoinDate(date);
        insertBitcoinValue(value);
    }
    data.close();
}

void BitcoinExchange::validDateInput(std::string date)
{
    if(date.size() != 10)
    {
        throw(BitcoinExchange::BitcoinExchangeException("Error !\nInvalid date format."));
    }
    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());
    if(month < 1 || month > 12){
        throw(BitcoinExchange::BitcoinExchangeException("Error !\nInvalid month."));
    }
    if(!tableMonth(month, day, year)){
        throw(BitcoinExchange::BitcoinExchangeException("Error !\nInvalid day."));
    }
}

std::string BitcoinExchange::findBitcoinValue(std::string date, float value)
{
    // verificar se a data é válida
    // depois encontrar a data exata ou a mais próxima inferior
    // retornar o valor do bitcoin na data encontrada
    validDateInput(date);
   if()
}

void BitcoinExchange::calculate(void)
{
    std::set<float>::iterator itValue = _InputValue.begin();   
    for (std::set<std::string>::iterator it = _InputDate.begin(); it != _InputDate.end(); ++it)
    {
        try
        {
            std::string value = findBitcoinValue(*it, *itValue);
            std::cout << *it << " | " << value << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
        itValue++;
    }
}

void BitcoinExchange::convert(int argc, char **argv)
{
    std::ifstream bitcoinFile;
    std::ifstream inputFile;

    validData(bitcoinFile);
    validInput(argc, argv, inputFile);
    calculate();
}