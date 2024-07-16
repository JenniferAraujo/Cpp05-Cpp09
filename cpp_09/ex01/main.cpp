#include "RPN.hpp"

int	main(int ac, char *av[]) {
	if (ac != 2 || !av[1][0]) {
		std::cout << "Error: Invalid argument." << std::endl;
		return 1;
	}
	std::string expression = av[1];
	RPN calculator;
	try {
		calculator.calculate(expression);
	} catch (const RPN::RPNException& e) {
		std::cout << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}