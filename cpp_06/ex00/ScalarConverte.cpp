#include "ScalarConverte.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << BLUE << "ScalarConverter default constructor called" << RESET << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
	std::cout << BLUE << "ScalarConverter copy constructor called" << RESET << std::endl;
	*this = copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy)
{
	if (this == &copy)
		return *this;
	std::cout << BLUE << "ScalarConverter copy assignment operator overload" << RESET << std::endl;
	return *this;
}

bool	ScalarConverter::isChar(const std::string& literal)
{
	if (literal.length() >= 2 || std::isdigit(literal[0]) || !std::isprint(literal[0]))
		return false;
	return true;
}

bool ScalarConverter::isInt(const std::string& literal)
{
	if (literal.empty())
		return false;
	int start = 0;
	if (literal[0] == '-' || literal[0] == '+')
	{
		if (literal.size() == 1)
			return false;
		start = 1;
	}
	for (size_t i = start; i < literal.size(); ++i)
	{
		if (!isdigit(literal[i]))
			return false;
	}
	char* end;
	long val = strtol(literal.c_str(), &end, 10);
	if (*end != '\0' || val < -2147483647 || val > 2147483647)
		return false;
	return true;
}

bool	ScalarConverter::isFloat(const std::string & literal)
{
	int size = literal.length();
	if (size < 2)
		return false;
	int start = 0;
	if (literal[0] == '-')
	{
		if (size == 2) return false;
		start = 1;
	}
	if (literal[size - 1] != 'f')
		return false;
	bool point_found = false;
	for (int i = start; i < size - 1; i++)
	{
		if (literal[i] == '.')
		{
			if (point_found)
				return false;
			point_found = true;
		}
		else if (literal[i] < '0' || literal[i] > '9')
			return false;
	}
	return point_found; 
}

bool	ScalarConverter::isDouble(const std::string& literal)
{
	if (literal.empty())
		return false;
	int start = 0;
	if (literal[0] == '-')
	{
		if (literal.size() == 1)
			return false;
		start = 1;
	}
	bool point_found = false;
	for (size_t i = start; i < literal.size(); ++i)
	{
		if (literal[i] == '.')
		{
			if (point_found)
				return false;
			point_found = true;
		}
		else if (!isdigit(literal[i]))
			return false;
	}
	return point_found && (literal.size() > 1);
}

void ScalarConverter::charConversion(char c)
{
	std::cout << "Char: '" << c << "'"<< std::endl;
	std::cout << "Int: " << static_cast<int>(c) << std::endl;
	std::cout << "Float: " << static_cast<float>(c) << ".0f"<< std::endl;
	std::cout << "Double: " << static_cast<double>(c) << ".0"<< std::endl;
}

void	ScalarConverter::intConversion(const std::string &literal)
{
	int i = std::atoi(literal.c_str());
	if ((i >= 0 && i < 32) || i == 127)
		std::cout << "char: Non displayable" << std::endl;
	else if (i > 126 || i < 0)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(i) << "'"<< std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void ScalarConverter::floatConversion(float _float)
{
	char signal = '\0';
	if (isinf(_float) && _float > 0)
		signal = '+';
	double d = static_cast<double>(_float);
	int i = static_cast<int>(_float);
	if (_float != i || i > 126 || i < 0)
		std::cout << "char: impossible" << std::endl;
	else if ((i >= 0 && i < 32) || i == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(i) << "'"<< std::endl;
	if (_float > std::numeric_limits<int>::max() || _float < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	if (i == _float)
		std::cout << "float: " << signal << _float << ".0f" <<  std::endl;
	else
		std::cout << "float: " << signal << _float << "f" <<  std::endl;
	if (i == d)
		std::cout << "double: " << signal << d << ".0" << std::endl;
	else
		std::cout << "double: " << signal << d << std::endl;
}

void	ScalarConverter::doubleConversion(double _double)
{
	char signal = '\0';
	if (isinf(_double) && _double > 0)
		signal = '+';
	float _float = static_cast<float>(_double);
	int i = static_cast<int>(_double);
	if (_double != i || i > 126 || i < 0)
		std::cout << "char: impossible" << std::endl;
	else if ((i >= 0 && i < 32) || i == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(i) << "'"<< std::endl;
	if (_float > std::numeric_limits<int>::max() || _float < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	if (i == _float)
		std::cout << "float: " << signal << _float << ".0f" <<  std::endl;
	else if (isinf(static_cast<float>(_double)))
	{
		char signal = (_double > 0) ? '+' : '-';
		std::cout << "float: " << signal << static_cast<float>(_double) << std::endl;
	}
	else
		std::cout << "float: " << signal << _float << "f" <<  std::endl;
	if (i == _double)
		std::cout << "double: " << signal << _double << ".0" << std::endl;
	else
		std::cout << "double: " << signal << _double << std::endl;
}

void	ScalarConverter::inf_nan(const std::string& literal)
{
	std::cout << "char: impossible\nint: impossible" << std::endl;
	if (literal == "+inf" || literal == "-inf" || literal == "nan")
	{
		std::cout << "float: " << literal << "f" << std::endl;
		std::cout << "double: " << literal << std::endl;
		return ;
	}
	std::cout << "float: " << literal << std::endl;
	std::cout << "double: ";
	if (literal == "+inff")
		std::cout << "+inf" << std::endl;
	else if (literal == "-inff")
		std::cout << "-inf" << std::endl;
	else
		std::cout << "nan" << std::endl;
}

void ScalarConverter::convert(const std::string& literal)
{
	if (literal == "+inf" || literal == "-inf" || literal == "+inff" || literal == "-inff" || literal == "nan" || literal == "nanf")
		inf_nan(literal);
	else if (literal.length() == 1 && isChar(literal))
		charConversion(literal[0]);
	else if (isInt(literal))
		intConversion(literal);
	else if (isFloat(literal))
		floatConversion(strtof(literal.c_str(), NULL));
	else if (isDouble(literal))
		doubleConversion(strtod(literal.c_str(), NULL));
	else
		std::cout << "Oops, impossible to convert 😞" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << BLUE << "ScalarConverter destructor called" << RESET << std::endl;
}