#ifndef SCALARCONVERTE_HPP
# define SCALARCONVERTE_HPP

# include <iostream>
# include <string>
# include <cctype>
# include <stdint.h>
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

class	ScalarConverte {
	private:
		const std::string	_string;
		char				_char;
		int					_int;
		float				_float;
		double				_double;
	public:
		ScalarConverte();
		ScalarConverte(std::string const _string); //obj constructor
		ScalarConverte(const ScalarConverte& copy); //copy constructor
		ScalarConverte& operator= (const ScalarConverte& copy);

		~ScalarConverte();
};

#endif