#ifndef SCALARCONVERTE_HPP
# define SCALARCONVERTE_HPP

# include <iostream>
# include <string>
# include <cctype>
# include <stdint.h>
# include <limits>
# include <stdlib.h>
# include <unistd.h>
# include <iomanip> 
# include <cstdlib>
#include <cmath> 
# include <ctime>

# define CYAN    "\e[0;36m"
# define MAGENTA "\033[0;35m"
# define YELLOW  "\e[0;33m"
# define GREEN	"\e[0;32m"
# define ORANGE	"\e[38;5;208m"
# define RED	"\e[0;31m"
# define BLUE	"\033[34m"
# define RESET "\033[0m"


class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);
		ScalarConverter& operator=(const ScalarConverter& copy);

	public:
		~ScalarConverter();

		//types
		static bool	isChar(const std::string& literal);
		static bool	isInt(const std::string& literal);
		static bool	isFloat(const std::string& literal);
		static bool	isDouble(const std::string& literal);

		//conversions
		static void	charConversion(char c);
		static void	intConversion(const std::string& literal);
		static void	floatConversion(float _float);
		static void	doubleConversion(double _double);
		static void	inf_nan(const std::string& literal);
		static void	convert(const std::string& literal);
};

#endif
