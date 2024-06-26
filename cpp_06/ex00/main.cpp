#include "ScalarConverte.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Invalid argument!" << std::endl;
		return (0);
	}
	ScalarConverter::convert(av[1]);
}
