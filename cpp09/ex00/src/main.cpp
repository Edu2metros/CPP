#include "BitcoinExchange.hpp"

/*  The program name is btc.
• Your program must take a file as argument.
• Each line in this file must use the following format: "date | value".
• A valid date will always be in the following format: Year-Month-Day.
• A valid value must be either a float or a positive integer, between 0 and 1000. */

int main(int argc, char **argv)
{
    BitcoinExchange btc;
    try
    {
        btc.convert(argc, argv);   
    }
    catch(std::exception& exceptionClass)
    {
        std::cerr << exceptionClass.what() << std::endl;
        return(EXIT_FAILURE);
    }
}