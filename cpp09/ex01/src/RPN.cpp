#include "RPN.hpp"

template <typename T>
void printMsg(T msg)
{
    #ifdef DEBUG
        std::cout << msg << std::endl;
    #endif
}

RPN::RPN(void)
{
    printMsg("RPN constructor called");
}

RPN::RPN(const RPN &rpn)
{
    printMsg("RPN copy constructor called");
    _stack = rpn._stack;
}

RPN& RPN::operator=(const RPN &rpn)
{
    printMsg("RPN assignation operator called");
    if (this != &rpn)
        _stack = rpn._stack;
    return *this;
}

RPN::~RPN()
{
    printMsg("RPN destructor called");
}

RPN::RPNException::RPNException(std::string message) : _message(message) {}

const char *RPN::RPNException::what() const throw()
{
    return _message.c_str();
}

RPN::RPNException::~RPNException() throw() {}

void RPN::operatorStack(int a, int b, char token)
{
    if (token == '+')
        _stack.push(b + a);
    else if (token == '-')
        _stack.push(b - a);
    else if (token == '*')
        _stack.push(b * a);
    else if (token == '/')
        _stack.push(b / a);
}

void RPN::calculate(std::string expr)
{
    std::string token;
    std::istringstream iss(expr);

    while (iss >> token)
    {
        if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (_stack.size() < 2)
                throw RPNException("Error: not enough values in the stack");
            int a = _stack.top();
            _stack.pop();
            int b = _stack.top();
            _stack.pop();
            operatorStack(a, b, token[0]);
        }
        else
            _stack.push(atoi(token.c_str()));
    }
    std::cout << _stack.top() << std::endl;
}