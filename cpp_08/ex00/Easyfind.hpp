#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <exception> 

# define CYAN    "\e[0;36m"
# define MAGENTA "\033[0;35m"
# define YELLOW  "\e[0;33m"
# define GREEN	"\e[0;32m"
# define ORANGE	"\e[38;5;208m"
# define RED	"\e[0;31m"
# define BLUE	"\033[34m"
# define RESET "\033[0m"

class ValueNotFoundException : public std::exception
{
	public:
	virtual const char *what() const throw(){
		return ("OPs, value not found in container!");
	}
};

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end()){
		throw ValueNotFoundException();
	}
	return it;
}

template <typename T>
void	printContainer(const T& container)
{
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

#endif

