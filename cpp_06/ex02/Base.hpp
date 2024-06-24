#ifndef BASE_HPP
# define BASE_HPP

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

class Base {
	public:
		virtual ~Base();
};
Base*	generate(void); // randomly generate A or B or C object type
void	identify(Base* p); // display the type of p object
void	identify(Base& p);

#endif