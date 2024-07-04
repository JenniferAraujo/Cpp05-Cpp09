#ifndef RPN_HPP
# define RPN_HPP

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

    public:
        RPN();
        RPN(const RPN& copy);
		RPN& operator=(const RPN& copy);
        ~RPN();
};

#endif