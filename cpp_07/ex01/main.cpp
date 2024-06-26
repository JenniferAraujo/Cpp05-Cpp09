#include "Iter.hpp"

template <typename T>
void printArray(const T* array, size_t size) {
	for (size_t i = 0; i < size; ++i) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

struct Person {
	std::string _name;
	int			_age;
};

int	main(void)
{
	int intArray[] = {1, 2, 3, 4, 5};
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::string stringArray[] = {"apple", "banana", "cherry"};

	// Array vazio
	int emptyArray[] = {};

	// Array nulo 
	int* nullArray = NULL;

	// Arrays multidimensionais
	int multiDimArray[2][3] = {{1, 2, 3}, {4, 5, 6}};

	Person persons[] = {{"Jessica", 31}, {"Mya", 9}, {"Lily", 3}};
	size_t personSize = sizeof(persons) / sizeof(persons[0]);

	std::cout << CYAN <<  "Int Array: " << RESET;
	printArray(intArray, sizeof(intArray) / sizeof(intArray[0]));

	std::cout << ORANGE << "Double Array: " << RESET;
	printArray(doubleArray, sizeof(doubleArray) / sizeof(doubleArray[0]));

	std::cout << MAGENTA << "String Array: " << RESET;
	printArray(stringArray, sizeof(stringArray) / sizeof(stringArray[0]));

	std::cout << "Empty Array: ";
	printArray(emptyArray, sizeof(emptyArray) / sizeof(emptyArray[0]));

	std::cout << YELLOW << "Null Array: " << RESET;
	printArray(nullArray, 0);

	std::cout << BLUE << "Multi-dimensional Array:" << RESET << std::endl;
	for (size_t i = 0; i < 2; ++i) {
		for (size_t j = 0; j < 3; ++j) {
			std::cout << multiDimArray[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << RED << "Persons Array:" << RESET << std::endl;
	for (size_t i = 0; i < personSize; ++i) {
		std::cout << "Name: " << persons[i]._name << ", Age: " << persons[i]._age << std::endl;
	}
}