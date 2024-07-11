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

bool	PmergeMe::checkNumber(const std::string& str) {
	for (size_t i = 0; i < str.size(); ++i) {
		if (!std::isdigit(str[i]))
			return false;
	}
	char* endptr;
	long num = std::strtol(str.c_str(), &endptr, 10);
	if (*endptr != '\0' || num <= 0 || num > INT_MAX) {
		return false;
	}
	return true;
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

std::vector<int>	PmergeMe::jacobsthalDifferences(int number) {
	std::vector<int> differences;
	std::vector<int> sequence = jacobsthalSeq(number);
	for (size_t i = 1; i < sequence.size(); ++i) {
		differences.push_back(sequence[i] - sequence[i - 1]);
	}
	return differences;
}

void	PmergeMe::insertVector(std::vector<int>& sorted_seq, int value) {
	sorted_seq.insert(std::lower_bound(sorted_seq.begin(), sorted_seq.end(), value), value);
}

void	PmergeMe::insertList(std::list<int>& sorted_seq, int value) {
	sorted_seq.insert(std::lower_bound(sorted_seq.begin(), sorted_seq.end(), value), value);
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
	for (size_t i = 0; i < vec.size(); i += 2) {
		if (vec[i] < vec[i + 1]) {
			pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
		} else {
			pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
		}
	}

	std::vector<int> pend;
	std::vector<int> sorted;
	for (size_t i = 0; i < pairs.size(); ++i) {
		pend.push_back(pairs[i].first);
		sorted.push_back(pairs[i].second);
	}

	sorted = algoritmVector(sorted);

	std::vector<int> jacobsthal = this->jacobsthalDifferences(pend.size());
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
		for (size_t k = 0; k < group.size(); ++k) {
			insertVector(sorted, group[k]);
		}
	}
	for (size_t i = index; i < pend.size(); ++i) {
		insertVector(sorted, pend[i]);
	}
	if (flag)
		insertVector(sorted, straggler);
	return sorted;
}

std::list<int>	PmergeMe::algoritmList(std::list<int> list) {
	if (list.size() <= 1)
		return list;

	bool flag = list.size() % 2 != 0;
	int straggler = 0;
	if (flag) {
		straggler = list.back();
		list.pop_back();
	}

	std::list<std::pair<int, int> > pairs;
	for (std::list<int>::iterator it = list.begin(); it != list.end(); ) {
		int first = *it++;
		int second = *it++;
		if (first < second)
			pairs.push_back(std::make_pair(first, second));
		else
			pairs.push_back(std::make_pair(second, first));
	}

	std::list<int> pend;
	std::list<int> sorted;
	for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
		pend.push_back(it->first);
		sorted.push_back(it->second);
	}

	sorted = algoritmList(sorted);

	std::vector<int> jacobsthal = this->jacobsthalDifferences(pend.size());
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
		for (size_t k = 0; k < group.size(); ++k) {
			insertList(sorted, group[k]);
		}
	}
	while (it != pend.end()) {
		insertList(sorted, *it);
		++it;
	}
	if (flag)
		insertList(sorted, straggler);
	return sorted;
}

void	PmergeMe::sort(const std::vector<int>& numbers) {
	std::vector<int> vec = numbers;
	std::list<int> lst(numbers.begin(), numbers.end());

	std::cout << "Before sort: ";
	print(numbers);

	clock_t init, end;

	// Sort std::vector
	init = clock();
	std::vector<int> sorted_vec = algoritmVector(vec);
	end = clock();
	double vectorTime = double(end - init) * 1000.0 / (double) CLOCKS_PER_SEC;
	// Sort std::list
	init = clock();
	std::list<int> sorted_list = algoritmList(lst);
	end = clock();
	double listTime = double(end - init) * 1000.0 / (double)CLOCKS_PER_SEC;

	std::cout << "After sort: ";
	print(sorted_vec);

	std::cout << "Tempo para processar uma faixa de " << numbers.size() << " elementos com std::vector: " << vectorTime << " segundos" << std::endl;
	std::cout << "Tempo para processar uma faixa de " << numbers.size() << " elementos com std::list: " << listTime << " segundos" << std::endl;
}

void	PmergeMe::print(const std::vector<int>& numbers) {
	for (std::vector<int>::const_iterator it = numbers.begin(); it != numbers.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
