#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./rpn \"expression\"" << std::endl;
        return (1);
    }
    RPN rpn;
    try
    {
        rpn.calculate(argv[1]);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}