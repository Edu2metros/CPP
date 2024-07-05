#include "ScalarConverter.hpp"

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

const char *ScalarConverter::ImpossibleConversionException::what() const throw()
{
	return _message.c_str();
}

/* void convertToChar(const std::string &input)
{
    if (input == "nan" || input == "inf" || input == "-inf" || input == "+inf")
        std::cout << "char: Impossible" << std::endl;
    int i;
	try
	{
        i = std::stoi(input);
	}
 	catch (const std::invalid_argument& e) {
        throw ScalarConverter::ImpossibleConversionException("Char: Impossible");
    } catch (const std::out_of_range& e) {
        throw ScalarConverter::ImpossibleConversionException("Char: Impossible");
    }
    if (i < 32 || i > 126)
		throw ScalarConverter::ImpossibleConversionException("Char: Impossible"); 
    else if(!isprint(i))
        throw ScalarConverter::ImpossibleConversionException("Char: Non displayable");

    std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
} */

void convertToChar(const std::string &input)
{
    int i;
    if (input.length() == 1) {
        i = static_cast<int>(input[0]);
    } else {
        try {
            i = std::stoi(input);
        } catch (const std::invalid_argument& e) {
            throw ScalarConverter::ImpossibleConversionException("Char: Impossible");
        } catch (const std::out_of_range& e) {
            throw ScalarConverter::ImpossibleConversionException("Char: Impossible");
        }
    }
    if (i < 32 || i > 126)
        throw ScalarConverter::ImpossibleConversionException("Char: Impossible"); 
    else if(!isprint(i))
        throw ScalarConverter::ImpossibleConversionException("Char: Non displayable");

    std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
}

void convertToInt(const std::string &input)
{
	int i;
	if(input.length() == 1)
		i = static_cast<int>(input[0]);
	else
	{
		try
		{
			i = std::stoi(input);
		}
		catch (const std::invalid_argument& e) {
			throw ScalarConverter::ImpossibleConversionException("Int: Impossible");
		} catch (const std::out_of_range& e) {
			throw ScalarConverter::ImpossibleConversionException("Int: Impossible");
		}
	}
	std::cout << "int: " << i << std::endl;
}

void convertToFloat(const std::string &input)
{
	float f;
	if(input.length() == 1)
		f = static_cast<float>(input[0]);
	else
	{
		try
		{
			f = std::stof(input);
		}
		catch (const std::invalid_argument& e) {
			throw ScalarConverter::ImpossibleConversionException("Float: Impossible");
		} catch (const std::out_of_range& e) {
			throw ScalarConverter::ImpossibleConversionException("Float: Impossible");
		}
	}
	if(f - static_cast<int>(f) == 0)
		std::cout << "float: " << f << ".0f" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;
}

void convertToDouble(const std::string &input)
{
	double d;
	if(input.length() == 1)
		d = static_cast<double>(input[0]);
	else
	{
		try
		{
			d = std::stod(input);
		}
		catch (const std::invalid_argument& e) {
			throw ScalarConverter::ImpossibleConversionException("Double: Impossible");
		} catch (const std::out_of_range& e) {
			throw ScalarConverter::ImpossibleConversionException("Double: Impossible");
		}
	}
	if(d - static_cast<int>(d) == 0)
		std::cout << "double: " << d << ".0" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(const std::string &input)
{
	if(input == "nan" || input == "inf" || input == "-inf" || input == "+inf")
	{
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
		std::cout << "float: " << input << "f" << std::endl;
		std::cout << "double: " << input << std::endl;
		return;
	}
	convertToChar(input);
	convertToInt(input);
	convertToFloat(input);
	convertToDouble(input);
}
