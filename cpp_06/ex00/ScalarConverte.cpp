#include "ScalarConverte.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const std::string& string) : _string(string)
{
    std::cout << "Attributes default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) : _string(copy._string), _char(copy._char), _int(copy._int), _float(copy._float), _double(copy._double)
{
    std::cout << "ScalarConverter copy constructor called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy)
{
    if (this == &copy)
        return *this;
    std::cout << "ScalarConverter copy assignment operator overload" << std::endl;
    _string = copy._string;
    _char = copy._char;
    _int = copy._int;
    _float = copy._float;
    _double = copy._double;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter destructor called" << std::endl;
}

void ScalarConverter::printResults(char c, int i, float f, double d)
{
    if (isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

bool ScalarConverter::isChar(const std::string& literal)
{
    return literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'';
}

bool ScalarConverter::isInt(const std::string& literal)
{
    char* end = NULL;
    long val = std::strtol(literal.c_str(), &end, 10);
    if (*end != '\0' || val < INT_MIN || val > INT_MAX)
        return false;
    return true;
}

bool ScalarConverter::isFloat(const std::string& literal)
{
    if (literal.length() > 0 && literal.at(literal.length() - 1) == 'f') {
        char* end = NULL;
        //float val = std::strtof(literal.c_str(), &end);
        if (*end != 'f') {
            return false;
        }
        return true;
    }
    return false;
}

bool ScalarConverter::isDouble(const std::string& literal)
{
    if (!literal.empty() && literal[literal.length() - 1] == 'd') {
        char* end = NULL;
        //double val = std::strtod(literal.c_str(), &end);
        if (*end != '\0') {
            return false;
        }
        return true;
    }
    return false;
}

void ScalarConverter::handleNan(const std::string& literal)
{
    if (literal == "nanf") {
        float f = FLT_MAX;
        printResults('?', 0, f, static_cast<double>(f));
    } else {
        double d = DBL_MAX;
        printResults('?', 0, static_cast<float>(d), d);
    }
}

void ScalarConverter::handleInf(const std::string& literal, bool positive)
{
    if (literal == "+inff" || literal == "inff") {
        float f = positive ? FLT_MAX : -FLT_MAX;
        printResults('?', 0, f, static_cast<double>(f));
    } else {
        double d = positive ? DBL_MAX : -DBL_MAX;
        printResults('?', 0, static_cast<float>(d), d);
    }
}

void ScalarConverter::convert()
{
    try {
        if (_string == "nan" || _string == "nanf")
            handleNan(_string);
        else if (_string == "+inf" || _string == "inf" || _string == "+inff" || _string == "inff")
            handleInf(_string, true);
        else if (_string == "-inf" || _string == "-inff")
            handleInf(_string, false);
        else {
            if (isChar(_string)) {
                char c = _string[1];
                printResults(c, static_cast<int>(c), static_cast<float>(c), static_cast<double>(c));
            } else if (isInt(_string)) {
                int i = std::stoi(_string);
                printResults(static_cast<char>(i), i, static_cast<float>(i), static_cast<double>(i));
            } else if (isFloat(_string)) {
                float f = std::strtof(_string.c_str(), 0);
                printResults(static_cast<char>(f), static_cast<int>(f), f, static_cast<double>(f));
            } else if (isDouble(_string)) {
                double d = std::strtod(_string.c_str(), 0);
                printResults(static_cast<char>(d), static_cast<int>(d), static_cast<float>(d), d);
            } else
                throw std::invalid_argument("Invalid literal");
        }
    } catch (const std::exception& e) {
        std::cout << "Conversion error: " << e.what() << std::endl;
    }
}
