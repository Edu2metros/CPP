#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    BitcoinExchange btc;
    try
    {
        btc.convert(argc, argv);   
    }
    catch(const BitcoinExchange::BitcoinExchangeException& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}