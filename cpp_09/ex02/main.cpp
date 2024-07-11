#include "PmergeMe.hpp"

int	main(int ac, char* av[]) {
	if (ac <= 2) {
		std::cout << "Erro: numeros insuficientes para ordenar" << std::endl;
		return (1);
	}
    PmergeMe sorter;
    std::vector<int> sequence;
    for (int i = 1; i < ac; ++i) {
        if (!sorter.checkNumber(av[i])) {
            std::cout << "Erro: Entrada inválida. Somente inteiros positivos são permitidos." << std::endl;
            return (1);
        }
        sequence.push_back(std::atoi(av[i]));
    }
    try {
        sorter.sort(sequence);
    } catch (const PmergeMe::PmergeMeException& e) {
        std::cout << "Erro: " << e.what() << std::endl;
        return (1);
    }
    return (0);
}