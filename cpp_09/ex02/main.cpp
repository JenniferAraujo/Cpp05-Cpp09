#include "PmergeMe.hpp"

int	main(int ac, char* av[]) {
	if (ac <= 2) {
		std::cout << "Error: Invalid argument." << std::endl;
		return 1;
	}
	PmergeMe sorter;
	std::vector<int> vec;
	try {
		for (int i = 1; i < ac; ++i) {
			sorter.checkNumber(av[i]);
			vec.push_back(std::atoi(av[i]));
		}
		sorter.sort(vec);
	} catch (const PmergeMe::PmergeMeException& e) {
		std::cout << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}