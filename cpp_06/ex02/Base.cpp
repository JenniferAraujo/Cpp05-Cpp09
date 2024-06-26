#include "C.hpp"

Base::~Base(){}

Base*	generate(void)
{
	int randomValue = std::rand() % 3;
	switch (randomValue) {
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
		default:
			std::cout << "Oops, something wrong with the Random Value" << std::endl;
			return NULL; 
	}
}

void	identify(Base* p)
{
	A* testA = dynamic_cast<A *>(p);
	if (testA != NULL)
	{
		std::cout << ORANGE << "A" << RESET << std::endl;
		return;
	}
	B* testB = dynamic_cast<B *>(p);
	if (testB != NULL)
	{
		std::cout << MAGENTA << "B" << RESET << std::endl;
		return;
	}
	C* testC = dynamic_cast<C *>(p);
	if (testC != NULL)
	{
		std::cout << BLUE << "C" << RESET << std::endl;
		return;
	}
	std::cout << RED << "Unknown Type" << RESET << std::endl;	
}

void identify(Base& p)
{
	try {
		A& testA = dynamic_cast<A &>(p);
		std::cout << ORANGE << "A" << RESET << std::endl;
		(void)testA;
		return ;
	}
	catch (std::exception &){}
	try {
		B& testB = dynamic_cast<B &>(p);
		std::cout << MAGENTA << "B" << RESET << std::endl;
		(void)testB;
		return ;
	}
	catch (std::exception &){}
	try {
		C& testC = dynamic_cast<C &>(p);
		std::cout << BLUE << "C" << RESET << std::endl;
		(void)testC;
		return ;
	}
	catch (std::exception &){
		std::cout << RED << "Unknown Type" << RESET << std::endl;	
	}
}