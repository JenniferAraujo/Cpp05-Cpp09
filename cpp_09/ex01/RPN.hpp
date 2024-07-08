#ifndef RPN_HPP
# define RPN_HPP

#include <limits>
#include <stack>
#include <iostream>
#include <algorithm>
# include <iomanip>
# include <string>
# include <cstdlib>
# include <fstream>
# include <sstream>
#include <stdexcept>
#include <cctype>  

# define CYAN    "\e[0;36m"
# define MAGENTA "\033[0;35m"
# define YELLOW  "\e[0;33m"
# define GREEN	"\e[0;32m"
# define ORANGE	"\e[38;5;208m"
# define RED	"\e[0;31m"
# define BLUE	"\033[34m"
# define RESET "\033[0m"

class RPN {
    private:
		std::stack<double> _stack;

		bool	CheckOperator(char op);
		bool	invalidChar(char c);
		int		performOperation(int first, int second, const std::string &op) const;

    public:
        RPN();
        RPN(const RPN& copy);
		RPN& operator=(const RPN& copy);
        ~RPN();

		void	calculate(const std::string& expression);
		class RPNException : public std::exception
		{
			public:
				RPNException(const std::string& message);
				virtual const char* what() const throw();
				virtual ~RPNException() throw() {}
			private:
				std::string _message;
		};
};

#endif
