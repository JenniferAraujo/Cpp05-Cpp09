#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <exception>

class	PmergeMe {
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& copy);
		PmergeMe& operator=(const PmergeMe& copy);
		~PmergeMe();

		bool				checkNumber(const std::string& str);
		void				sort(const std::vector<int>& sequence);
		std::vector<int>	algoritmVector(std::vector<int> vec);
		std::list<int>		algoritmList(std::list<int> list);
		std::vector<int>	jacobsthalSeq(int number);
		std::vector<int>	jacobsthalDifferences(int number);
		void				insertVector(std::vector<int>& sorted_seq, int value);
		void				insertList(std::list<int>& sorted_seq, int value);
		void				print(const std::vector<int> &sequence);

		class PmergeMeException : public std::exception {
			public:
				PmergeMeException(const std::string& message);
				virtual const char* what() const throw();
				virtual ~PmergeMeException() throw() {}
			private:
				std::string _message;
		};
};

#endif
