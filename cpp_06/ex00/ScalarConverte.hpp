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
# include <ctime>

# define CYAN    "\e[0;36m"
# define MAGENTA "\033[0;35m"
# define YELLOW  "\e[0;33m"
# define GREEN	"\e[0;32m"
# define ORANGE	"\e[38;5;208m"
# define RED	"\e[0;31m"
# define BLUE	"\033[34m"
# define RESET "\033[0m"

#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define FLT_MAX 3.402823466e+38F
#define FLT_MIN 1.175494351e-38F
#define DBL_MAX 1.7976931348623158e+308
#define DBL_MIN 2.2250738585072014e-308

class ScalarConverter
{
	private:
		std::string _string;
		char _char;
		int _int;
		float _float;
		double _double;
	public:
		ScalarConverter();
		ScalarConverter(const std::string& string);
		ScalarConverter(const ScalarConverter& copy);
		ScalarConverter& operator=(const ScalarConverter& copy);
		~ScalarConverter();

		void convert();

		bool isChar(const std::string& literal);
		bool isInt(const std::string& literal);
		bool isFloat(const std::string& literal);
		bool isDouble(const std::string& literal);

		void printResults(char c, int i, float f, double d);
		void handleNan(const std::string& literal);
		void handleInf(const std::string& literal, bool positive);
};

#endif
