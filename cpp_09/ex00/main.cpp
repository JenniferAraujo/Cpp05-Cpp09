#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2) {
		std::cout << "Error: Invalid argument." << std::endl;
		return 1;
	} 
	try {
		BitcoinExchange  bitcoin;
		bitcoin.handleInput(av[1]);
	}
	catch (const BitcoinExchange::BitcoinExchangeException& e) {
		std::cout << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
