#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <vector>
#include <list>
#include <deque>
#include <limits>
#include <stack>
# include <map>
#include <iostream>
#include <algorithm>
# include <iomanip>
# include <string>
# include <cstdlib>
# include <fstream>
# include <sstream>
#include <stdexcept>

# define CYAN    "\e[0;36m"
# define MAGENTA "\033[0;35m"
# define YELLOW  "\e[0;33m"
# define GREEN	"\e[0;32m"
# define ORANGE	"\e[38;5;208m"
# define RED	"\e[0;31m"
# define BLUE	"\033[34m"
# define RESET "\033[0m"

class BitcoinExchange {
	private:
		std::map<std::string, float, std::greater<std::string> > dataBase;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange& operator=(const BitcoinExchange& copy);
		BitcoinExchange(std::ifstream& data);
		
		void	printDataBase() const;
		void 	handleInput(const std::string& filename);
		std::string	findClosestDate(const std::string& target_date) const;
		void	processLine(const std::string& line);
		~BitcoinExchange();

		class BitcoinExchangeException : public std::exception
		{
			public:
				BitcoinExchangeException(const std::string& message);
				virtual const char* what() const throw();
				virtual ~BitcoinExchangeException() throw() {}
			private:
				std::string _message;
		};
};

#endif
