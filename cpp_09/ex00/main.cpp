#include "BitcoinExchange.hpp"

void	BitcoinExchange::printDataBase() const {
	std::map<std::string, float>::const_iterator i;
	for (i = dataBase.begin(); i != dataBase.end(); ++i) {
		std::cout << i->first << " => " << i->second << std::endl;
	}
}

int	main(int ac, char **av)
{
	if (ac < 2 || ac > 2) {
		std::cout << "Error: Invalid arguments." << std::endl;
		return (0);
	} 
	try {
		BitcoinExchange  bitcoin;
		bitcoin.handleInput(av[1]);
	}
	catch(std::string error) {
		std::cout << "Error : " << error << std::endl;
	}
}