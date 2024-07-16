#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <exception>
#include <cstdlib>
#include <sstream>

class BitcoinExchange
{
private:
    std::map<std::string, float> _BitcoinData;
    std::map<std::string, std::string> _InputData;

    void validInput(int argc, char **argv, std::ifstream &file);
    void validData(std::ifstream &data);
    bool checkDebug(void);
    float getValue(const std::string& value);
    std::string getDate(const std::string& date);
    bool tableMonth(int month, int day, int year);
    void calculate(void);

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void convert(int argc, char **argv);
    void insertBitcoinData(const std::string &BitcoinDate, float BitcoinValue);
    void insertInputData(const std::string &date, const std::string &value);
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
