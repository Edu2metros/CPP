#pragma once

#include <string>
#include <iostream>
#include <stack>
#include <exception>
#include <cstdlib>
#include <sstream>

class RPN
{
    private:
    std::stack<int> _stack;
    public:
        RPN(void);
        RPN(const RPN &rpn);
        RPN& operator=(const RPN &rpn);
        ~RPN();

        void calculate(std::string expr);
        void operatorStack(int a, int b, char token);
        class RPNException : public std::exception
        {
            private:
            std::string _message;
            public:
            RPNException(std::string message);
            const char *what() const throw();
            ~RPNException() throw();
        };
};