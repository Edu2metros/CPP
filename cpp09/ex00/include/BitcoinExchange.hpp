#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <set>
	#include <exception>
#include <cstdlib>
#include <sstream>

class BitcoinExchange
{
private:
    std::set<std::pair<std::string, float> > _BitcoinData;
    std::string *_InputDate;
    std::string *_InputValue;

    void validInput(int argc, char **argv, std::ifstream &file);
    void validData(std::ifstream &data);
    bool checkDebug(void);
    float getValue(const std::string& value);
    std::string getDate(const std::string& date);
    bool tableMonth(int month, int day, int year);
    void calculate(void);
    float extractInputValue(const std::string& inputLine);

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void convert(int argc, char **argv);
    void insertBitcoinData(const std::string &BitcoinDate, float BitcoinValue);
    void setInputData(const std::string &date, const std::string &value);
    void validDateInput(const std::string &date);
    std::string findBitcoinValue(const std::string &date);
    
    class BitcoinExchangeException : public std::exception
    {
    private:
        std::string _message;
    public:
        BitcoinExchangeException(const std::string& message);
        virtual ~BitcoinExchangeException() throw();
        virtual const char* what() const throw();
    };
};
