#include "Base.hpp"

int	main(void)
{
	std::cout << CYAN << "\nGenerate and identify instances of A, B and C" << RESET << std::endl;
	for (int i = 0; i < 10; ++i) {
		Base* p = generate();
		if (p) {
			std::cout << "Identifying with pointer: ";
			identify(p);
			std::cout << "Identifying with reference: ";
			identify(*p);
			delete p;
		} else
			std::cout << RED << "Failed to generate instance" << RESET << std::endl;
		std::cout << std::endl;
	}
	
	std::cout << CYAN << "\nTest with null pointer" << RESET << std::endl;
	Base* nullPtr = NULL;
	identify(nullPtr);

	std::cout << CYAN << "\nTest with invalid class" << RESET << std::endl;
	Base *test = new Base;
	std::cout << "Identifying with pointer: ";
	identify(test);
	std::cout << "Identifying with reference: ";
	identify(*test);
	delete test;
}