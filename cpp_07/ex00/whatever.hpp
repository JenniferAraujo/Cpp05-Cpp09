#ifndef WHATEVER_HPP
# define WHATEVER_HPP

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

template <typename T>
void	swap(T& a, T& b){
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T min(T& a, T& b){
	return (a < b) ? a : b;
}

template <typename T>
T max(T& a, T& b){
	return (a > b) ? a : b;
}

#endif
