#include "Span.hpp"

void	Span::printNumbers(void) const {
	for (std::vector<int>::const_iterator it = _numbers.begin(); it != _numbers.end(); ++it){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int	main(void) {
	srand(time(NULL));
	std::cout << CYAN << "Add Number" << RESET << std::endl;
	{
		Span span(5);
		try {
			span.addNumber(6);
			span.addNumber(2);
			span.addNumber(1);
			span.addNumber(4);
			span.addNumber(9);
			span.printNumbers();
			std::cout << CYAN << "\nTesting exceeding maximum span size" << RESET << std::endl;
			span.addNumber(11);
		} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}

		try {
			std::cout << CYAN << "\nShortest and longest" << RESET << std::endl;
			std::cout << ORANGE "Shortest span: " << RESET << span.shortestSpan() << std::endl;
			std::cout << BLUE << "Longest span: " << RESET << span.longestSpan() << std::endl;
		} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << CYAN << "\nAdd Number by Iterator" << RESET << std::endl;
	{
		std::vector<int> numsToAdd;
		numsToAdd.push_back(11);
		numsToAdd.push_back(12);

		Span span(5);
		span.addNumber(1);
		span.addNumber(2);

		try {
			span.addNUmber(numsToAdd.begin(), numsToAdd.end());
			std::cout << MAGENTA << "Span after adding range: " << RESET;
			span.printNumbers();
			std::cout << ORANGE "Shortest span: " << RESET << span.shortestSpan() << std::endl;
			std::cout << BLUE << "Longest span: " << RESET << span.longestSpan() << std::endl;
		} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << CYAN << "\nTest with Large Number of Elements" << RESET << std::endl;
	{
		Span span(10000);
		try {
			for (int i = 0; i < 10000; i++) {
				span.addNumber(rand() % 100000);
			}
			std::cout << ORANGE "Shortest span: " << RESET << span.shortestSpan() << std::endl;
			std::cout << BLUE << "Longest span: " << RESET << span.longestSpan() << std::endl;
		} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}

