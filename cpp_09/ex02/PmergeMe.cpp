#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& copy) {
	*this = copy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& copy) {
	if (this == &copy)
		return *this;
	return *this;
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMeException::PmergeMeException(const std::string& message) : _message(message) {}

const char* PmergeMe::PmergeMeException::what() const throw() {
	return _message.c_str();
}

void	PmergeMe::checkNumber(const std::string& str) {
	for (size_t i = 0; i < str.size(); ++i) {
		if (!std::isdigit(str[i]))
			throw PmergeMeException("Only positive integers are allowed.");
	}
	char *endptr;
	long num = std::strtol(str.c_str(), &endptr, 10);
	if (*endptr != '\0' || num <= 0 || num > INT_MAX) {
		throw PmergeMeException("Invalid number.");
	}
}

void	PmergeMe::checkAllEqual(const std::vector<int>& numbers) {
	int first = numbers[0];
	for (size_t i = 1; i < numbers.size(); ++i) {
		if (numbers[i] != first) {
			return ;
		}
	}
	throw PmergeMeException("All numbers are the same.");
}

std::vector<int>	PmergeMe::jacobsthalSeq(int number) {
	std::vector<int> vec;
	int a = 0, b = 1;
	while (b <= number) {
		vec.push_back(b);
		int temp = b;
		b = a + 2 * b;
		a = temp;
	}
	return vec;
}

std::vector<int>	PmergeMe::jacobsthalDiff(int number) {
	std::vector<int> diff;
	std::vector<int> vec = jacobsthalSeq(number);
	for (size_t i = 1; i < vec.size(); ++i) {
		diff.push_back(vec[i] - vec[i - 1]);
	}
	return diff;
}

std::vector<int>	PmergeMe::sortVector(std::vector<int> vec) {
	if (vec.size() <= 1)
		return vec;

	bool odd = vec.size() % 2 != 0;
	int last = 0;
	if (odd) {
		last = vec.back();
		vec.pop_back();
	}
	std::vector<std::pair<int, int> > pairs;
	createPairs(vec, pairs);

	std::vector<int> pend;
	std::vector<int> sorted;
	for (size_t i = 0; i < pairs.size(); ++i) {
		pend.push_back(pairs[i].first);
		sorted.push_back(pairs[i].second);
	}
	sorted = sortVector(sorted);

	std::vector<int> jacobsthal = this->jacobsthalDiff(pend.size());
	size_t index = 0;
	for (size_t i = 0; i < jacobsthal.size(); ++i) {
		size_t groupSize = jacobsthal[i];
		if (index >= pend.size())
			break ;

		std::vector<int> group;
		for (size_t j = 0; j < groupSize && index < pend.size(); ++j) {
			group.push_back(pend[index]);
			++index;
		}
		std::reverse(group.begin(), group.end());
		for (size_t k = 0; k < group.size(); ++k)
			insertSorted(sorted, group[k]);
	}
	for (size_t i = index; i < pend.size(); ++i)
		insertSorted(sorted, pend[i]);
	if (odd)
		insertSorted(sorted, last);
	return sorted;
}

std::list<int>	PmergeMe::sortList(std::list<int> list) {
	if (list.size() <= 1)
		return list;

	bool odd = list.size() % 2 != 0;
	int	last = 0;
	if (odd) {
		last = list.back();
		list.pop_back();
	}
	std::list<std::pair<int, int> > pairs;
	createPairs(list, pairs);

	std::list<int> pend;
	std::list<int> sorted;
	for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
		pend.push_back(it->first);
		sorted.push_back(it->second);
	}
	sorted = sortList(sorted);

	std::vector<int> jacobsthal = this->jacobsthalDiff(pend.size());
	std::list<int>::iterator it = pend.begin();

	for (size_t i = 0; i < jacobsthal.size(); ++i) {
		size_t groupSize = jacobsthal[i];
		if (it == pend.end())
			break ;
		std::vector<int> group;
		for (size_t j = 0; j < groupSize && it != pend.end(); ++j) {
			group.push_back(*it);
			++it;
		}
		std::reverse(group.begin(), group.end());
		for (size_t k = 0; k < group.size(); ++k)
			insertSorted(sorted, group[k]);
	}
	while (it != pend.end()) {
		insertSorted(sorted, *it);
		++it;
	}
	if (odd)
		insertSorted(sorted, last);
	return sorted;
}

void	PmergeMe::sort(const std::vector<int>& numbers) {
	std::vector<int> vec = numbers;
	std::list<int> list(numbers.begin(), numbers.end());

	checkAllEqual(numbers);
	checkIfSorted(numbers); 
	std::cout << BLUE << "Before sort: " << RESET;
	print(numbers);

	clock_t init, end;

	// Sort std::vector
	init = clock();
	std::vector<int> sortVec = sortVector(vec);
	end = clock();
	double vectorTime = double(end - init) / (double) CLOCKS_PER_SEC;

	// Sort std::list
	init = clock();
	std::list<int> sortLst = sortList(list);
	end = clock();
	double listTime = double(end - init) / (double)CLOCKS_PER_SEC;

	std::cout << MAGENTA << "\nSort with vector: " << RESET;
	print(sortVec);
	std::cout << "Time to sort " << numbers.size() << " elements with std::vector: " << std::fixed << CYAN << vectorTime << " seconds" << RESET << std::endl;

	std::cout << ORANGE << "\nSort with list: " << RESET;
	print(std::vector<int>(sortLst.begin(), sortLst.end()));
	std::cout << "Time to sort " << numbers.size() << " elements with std::list: " << CYAN << listTime << " seconds" << RESET << std::endl;
}

void	PmergeMe::print(const std::vector<int>& numbers) {
	for (std::vector<int>::const_iterator it = numbers.begin(); it != numbers.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
