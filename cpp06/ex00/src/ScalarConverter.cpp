#include "ScalarConverter.hpp"

#define INT_MIN -2147483648
#define INT_MAX 2147483647

bool checkDebug(void)
{
	#ifdef DEBUG
		return true;
	#else
		return false;
	#endif
}

ScalarConverter::ScalarConverter()
{
	if (checkDebug())
		std::cout << "ScalarConverter: Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	if (checkDebug())
		std::cout << "ScalarConverter: Copy constructor called" << std::endl;
	*this = other;
}

ScalarConverter::~ScalarConverter()
{
	if (checkDebug())
		std::cout << "ScalarConverter: Destructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	if (checkDebug())
		std::cout << "ScalarConverter: Assignation operator called" << std::endl;
	(void)other;
	return *this;
}

ScalarConverter::ImpossibleConversionException::ImpossibleConversionException(const std::string &message)
{
	_message = message;
}

ScalarConverter::ImpossibleConversionException::~ImpossibleConversionException() throw()
{
	if(checkDebug())
		std::cout << "ScalarConverter: ImpossibleConversionException destructor called" << std::endl;
}

const char *ScalarConverter::ImpossibleConversionException::what() const throw()
{
	return _message.c_str();
}

static std::string removeF(const std::string &input)
{
	std::string str = input;
	if (str[str.length() - 1] == 'f' && str.find(".") != std::string::npos)
		str = str.substr(0, str.length() - 1);
	return str;
}

static int nearestInt(const std::string &input)
{
    char* end;
   	long longNum = std::strtold(input.c_str(), &end);
	if(longNum < INT_MIN || longNum > INT_MAX || *end != '\0')
		throw(ScalarConverter::ImpossibleConversionException("int: impossible"));
    return static_cast<int>(longNum);
}

static std::string cutString(const std::string &input) {
    int i = input.find(".");
    if (i != -1) {
        return input.substr(0, i);
    }
    return input;
}

static bool impossibleConversion(const std::string &input)
{
	if(input == "nan" || input == "inf" || input == "-inf" || input == "+inf")
	{
		std::string message;
		message += "char: Impossible\n";
		message += "int: Impossible\n";
		message += "float: " + input + "f\n";
		message += "double: " + input + "\n";
		std::cout << message;
		return true;
	}
	return false;
}


static void convertToChar(const std::string &input)
{
    if (input.length() == 1 && !std::isdigit(static_cast<unsigned char>(input[0]))) {
        char result = static_cast<char>(input[0]);
        if (result >= 32 && result <= 126) {
            std::cout << "char: '" << result << "'" << std::endl;
        } else {
            std::cout << "char: non displayable" << std::endl;
        }
    } else {
        char* end;
        long num = std::strtol(cutString(input).c_str(), &end, 10);
        if (*end == '\0' && num >= 0 && num <= 255) {
            char result = static_cast<char>(num);
            if (result >= 32 && result <= 126) {
                std::cout << "char: '" << result << "'" << std::endl;
            } else {
                std::cout << "char: non displayable" << std::endl;
            }
        } else {
            std::cout << "char: impossible" << std::endl;
        }
    }
}


static void convertToInt(const std::string &input)
{
	try{
	int result = nearestInt(removeF(input));
	std::cout << "int: " << result << std::endl;
	}
	catch(ScalarConverter::ImpossibleConversionException &e){
		std::cout << e.what() << std::endl;
	}
}

static void convertToFloat(const std::string &input)
{
	try{
		char *end;
		float result = static_cast<float>(std::strtof(removeF(input).c_str(), &end));
		if(*end != '\0')
			throw(ScalarConverter::ImpossibleConversionException("float: impossible"));
		if(result - static_cast<int>(result) == 0)
			std::cout << "float: " << result << ".0f" << std::endl;
		else
			std::cout << "float: " << result << "f" << std::endl;
	}
	catch(std::exception &e){
		std::cout << "float: impossible" << std::endl;
	}
}

static void convertToDouble(const std::string &input)
{
	try{
		char *end;
		double result = static_cast<double>(std::strtod(removeF(input).c_str(), &end));
		if(*end != '\0')
			throw(ScalarConverter::ImpossibleConversionException("double: impossible"));
		if(result - static_cast<int>(result) == 0)
			std::cout << "double: " << result << ".0" << std::endl;
		else
			std::cout << "double: " << result << std::endl;
	}
	catch(std::exception &e){
		std::cout << "double: impossible" << std::endl;
	}
}

void ScalarConverter::convert(const std::string &input)
{
	if(impossibleConversion(input))
		return;
	convertToChar(input);
	convertToInt(input);
	convertToFloat(input);
	convertToDouble(input);
}
