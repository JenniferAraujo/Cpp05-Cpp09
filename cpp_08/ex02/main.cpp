#include "MutantStack.hpp"

int	main(void)
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);

	std::cout << "Top: " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "Size: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "MutantStack elements:" << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
	{
		std::cout << *it << std::endl;
	}

	std::list<int> list;
	list.push_back(5);
	list.push_back(17);

	std::cout << "Top: " << list.back() << std::endl;

	list.pop_back();

	std::cout << "Size: " << list.size() << std::endl;

	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);

	std::cout << "List elements:" << std::endl;
	for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
	return (0);
}
