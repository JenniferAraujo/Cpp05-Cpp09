#include "MutantStack.hpp"

int	main(void) {
	std::cout << MAGENTA <<  " *	Test using Mustack	*\n" << RESET << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);

	std::cout << ORANGE <<  "Top of the stack: " << RESET << mstack.top() << std::endl;

	mstack.pop();

	std::cout << ORANGE << "Stack Size: " << RESET << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << CYAN << "\nMutantStack elements:" << RESET << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
	{
		std::cout << *it << std::endl;
	}

	std::cout << MAGENTA <<  "\n *	Test using List    *\n" << RESET << std::endl;
	std::list<int> list;
	list.push_back(5);
	list.push_back(17);

	std::cout << ORANGE << "Top of the list: " << RESET << list.back() << std::endl;

	list.pop_back();

	std::cout << ORANGE << "List size: " << RESET << list.size() << std::endl;

	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);

	std::cout << CYAN << "\nList elements:" << RESET << std::endl;
	for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
	std::cout << CYAN << "\nTest copy constructor of MutantStack" << RESET << std::endl;
	std::stack<int> test(mstack);
	std::cout << "mstack.top() = " << BLUE << mstack.top() << RESET << " and test.top() = " << GREEN << test.top() << RESET << std::endl;
	std::cout << "mstack.size() = " << BLUE << mstack.size() << RESET << " and test.size() = " << GREEN << test.size()<< RESET << std::endl;
}
