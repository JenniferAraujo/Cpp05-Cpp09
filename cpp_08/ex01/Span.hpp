#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <limits>
#include <algorithm>
#include <cstdlib>
#include <exception>

# define CYAN    "\e[0;36m"
# define MAGENTA "\033[0;35m"
# define YELLOW  "\e[0;33m"
# define GREEN	"\e[0;32m"
# define ORANGE	"\e[38;5;208m"
# define RED	"\e[0;31m"
# define BLUE	"\033[34m"
# define RESET "\033[0m"

class Span {
	private:
		unsigned int		 _maxInt;  // número máximo de inteiros que pode armazenar
		std::vector<int>	_numbers; // Container para armazenar os inteiros
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& copy);
		Span& operator=(const Span& copy);
		void	addNumber(int num);  // add um número ao Span
		void	addNUmber(std::vector<int>::iterator begin, std::vector<int>::iterator end);  // add uma faixa de números usando iteradores
		int		shortestSpan();  // encontrar o menor num entre os números armazenados
		int		longestSpan();  // encontrar o maior num entre os números armazenados
		void	printNumbers(void) const;
		~Span();
};

template <typename T>
void	printContainer(const T& container) {
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

#endif