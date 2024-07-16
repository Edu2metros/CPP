#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <exception>
#include <cstdlib>

class BitcoinExchange
{
    private:
    std::set<std::string> _BitcoinDate;
    std::set<float> _BitcoinValue;

    std::set<std::string> _InputDate;
    std::set<float> _InputValue;

    void validInput(int argc, char **argv, std::ifstream &file);
    void validData(std::ifstream &data);
    bool checkDebug(void);
    float getValue(const std::string& value);
    std::string getDate(const std::string& date);
    bool tableMonth(int month, int day, int year);
    void calculate(void);

    // Orthodox Canonical form
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();
        //Functions members
        void convert(int argc, char **argv);
        void insertBitcoinDate(std::string &BitcoinDate);
        void insertBitcoinValue(float BitcoinValue);
        void insertInputDate(std::string &line);
        void insertInputValue(float value);
        void validDateInput(std::string date);
        std::string findBitcoinValue(std::string date, float value);
        //Exceptions class
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