#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>
#include <list>
#include <string>
# include <stdlib.h>
#include <exception>

# define CYAN    "\e[0;36m"
# define MAGENTA "\033[0;35m"
# define YELLOW  "\e[0;33m"
# define GREEN	"\e[0;32m"
# define ORANGE	"\e[38;5;208m"
# define RED	"\e[0;31m"
# define BLUE	"\033[34m"
# define RESET "\033[0m"

class	PmergeMe {
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& copy);
		PmergeMe& operator=(const PmergeMe& copy);
		~PmergeMe();

		void				checkNumber(const std::string& str);
		void				checkAllEqual(const std::vector<int>& numbers);
		void				sort(const std::vector<int>& sequence);
		std::vector<int>	sortVector(std::vector<int> vec);
		std::list<int>		sortList(std::list<int> list);
		std::vector<int>	jacobsthalSeq(int number);
		std::vector<int>	jacobsthalDiff(int number);
		void				print(const std::vector<int> &sequence);

		class PmergeMeException : public std::exception {
			public:
				PmergeMeException(const std::string& message);
				virtual const char* what() const throw();
				virtual ~PmergeMeException() throw() {}
			private:
				std::string _message;
		};

		template<typename Container, typename PairContainer>
		void	createPairs(Container& container, PairContainer& pairs) {
			for (typename Container::iterator it = container.begin(); it != container.end(); ) {
				int first = *it++;
				if (it == container.end()) break;
				int second = *it++;
				if (first < second)
					pairs.push_back(std::make_pair(first, second));
				else
					pairs.push_back(std::make_pair(second, first));
			}
		}
		template<typename Container>
		void	insertSorted(Container& container, int value) {
			typename Container::iterator pos = std::lower_bound(container.begin(), container.end(), value);
			container.insert(pos, value);
		}
};

#endif
