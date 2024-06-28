#include  "Easyfind.hpp"

void	testVector(void)
{
	int arr[] = {5, 4, 3, 2, 1, 3};
	std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));

	std::cout << BLUE << "Testing std::vector" << RESET << std::endl;
	printContainer(vec);
	std::cout << CYAN << "Test with valid number" << RESET << std::endl;
	try {
		std::vector<int>::iterator result = easyfind(vec, 3);
		std::cout << "Value found in the deque: " << *result << " at position: " << std::distance(vec.begin(), result) << std::endl;
	} catch (const ValueNotFoundException& e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << CYAN << "Test with invalid number" << RESET << std::endl;
	try {
		std::vector<int>::iterator result = easyfind(vec, 6);
		std::cout << "Value found in the deque: " << *result << " at position: " << std::distance(vec.begin(), result) << std::endl;
	} catch (const ValueNotFoundException& e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

void	testList(void)
{
	int arr[] = {1, 2, 3, 4, 5};
	std::list<int> lst(arr, arr + sizeof(arr) / sizeof(int));

	std::cout << ORANGE << "\nTesting std::list" << RESET << std::endl;
	printContainer(lst);
	std::cout << CYAN << "Test with valid number" << RESET << std::endl;
	try {
		std::list<int>::iterator result = easyfind(lst, 4);
		std::cout << "Value found in the deque: " << *result << " at position: " << std::distance(lst.begin(), result) << std::endl;
	} catch (const ValueNotFoundException& e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << CYAN << "Test with invalid number" << RESET << std::endl;
	try {
		std::list<int>::iterator result = easyfind(lst, 7);
		std::cout << "Value found in the deque: " << *result << " at position: " << std::distance(lst.begin(), result) << std::endl;
	} catch (const ValueNotFoundException& e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

void	testDeque(void)
{
	int arr[] = {40, 41, 42, 43, 45};
	std::deque<int> deq(arr, arr + sizeof(arr) / sizeof(int));

	std::cout << MAGENTA << "\nTesting std::deque" << RESET << std::endl;
	printContainer(deq);
	std::cout << CYAN << "Test with valid number" << RESET << std::endl;
	try {
		std::deque<int>::iterator result = easyfind(deq, 45);
		std::cout << "Value found in the deque: " << *result << " at position: " << std::distance(deq.begin(), result) << std::endl;
	} catch (const ValueNotFoundException& e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << CYAN << "Test with invalid number" << RESET << std::endl;
	try {
		std::deque<int>::iterator result = easyfind(deq, 8);
		std::cout << "Value found in the deque: " << *result << " at position: " << std::distance(deq.begin(), result) << std::endl;
	} catch (const ValueNotFoundException& e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

int	main(void)
{
	testVector();
	testList();
	testDeque();

	return (0);
}


