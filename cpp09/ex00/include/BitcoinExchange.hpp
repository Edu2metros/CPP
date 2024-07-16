#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <exception>

class BitcoinExchange
{
    private:
    std::set<std::string> _dates;

    // Orthodox Canonical form
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();
        //Functions members
        static void convert(int argc, char **argv);
        //Exceptions class
        class BitcoinExchangeException : public std::exception
        {
            public:
                BitcoinExchangeException(const std::string& message);
                virtual const char* what() const noexcept;
            private:
                std::string message;
        };
};