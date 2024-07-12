#include "PmergeMe.hpp"

// Orthodox Canonical Form
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
			throw PmergeMeException("Error: Only positive integers are allowed.");
	}
	char* endptr;
	long num = std::strtol(str.c_str(), &endptr, 10);
	if (*endptr != '\0' || num <= 0 || num > INT_MAX) {
		throw PmergeMeException("Error: invalid number.");
	}
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

std::vector<int>	PmergeMe::algoritmVector(std::vector<int> vec) {
	if (vec.size() <= 1)
		return vec;

	bool flag = vec.size() % 2 != 0;
	int straggler = 0;
	if (flag) {
		straggler = vec.back();
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
	sorted = algoritmVector(sorted);

	std::vector<int> jacobsthal = this->jacobsthalDiff(pend.size());
	size_t index = 0;
	for (size_t i = 0; i < jacobsthal.size(); ++i) {
		size_t groupSize = jacobsthal[i];
		if (index >= pend.size())
			break;

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
	if (flag)
		insertSorted(sorted, straggler);
	return sorted;
}

std::list<int>	PmergeMe::algoritmList(std::list<int> list) {
	if (list.size() <= 1)
		return list;

	bool flag = list.size() % 2 != 0;
	int	straggler = 0;
	if (flag) {
		straggler = list.back();
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
	sorted = algoritmList(sorted);

	std::vector<int> jacobsthal = this->jacobsthalDiff(pend.size());
	std::list<int>::iterator it = pend.begin();

	for (size_t i = 0; i < jacobsthal.size(); ++i) {
		size_t groupSize = jacobsthal[i];
		if (it == pend.end())
			break;
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
	if (flag)
		insertSorted(sorted, straggler);
	return sorted;
}

void	PmergeMe::sort(const std::vector<int>& numbers) {
	std::vector<int> vec = numbers;
	std::list<int> list(numbers.begin(), numbers.end());

	std::cout << "Before sort: ";
	print(numbers);

	clock_t init, end;

	// Sort std::vector
	init = clock();
	std::vector<int> sorted = algoritmVector(vec);
	end = clock();
	double vectorTime = double(end - init) / (double) CLOCKS_PER_SEC;

	// Sort std::list
	init = clock();
	std::list<int> sorted_list = algoritmList(list);
	end = clock();
	double listTime = double(end - init) / (double)CLOCKS_PER_SEC;

	std::cout << "After sort: ";
	print(sorted);
	std::cout << "Time to sort " << numbers.size() << " elements with std::vector: "<< std::fixed << vectorTime << " us" << std::endl;
	std::cout << "Time to sort " << numbers.size() << " elements with std::list: " << listTime << " us" << std::endl;
}

void	PmergeMe::print(const std::vector<int>& numbers) {
	for (std::vector<int>::const_iterator it = numbers.begin(); it != numbers.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
