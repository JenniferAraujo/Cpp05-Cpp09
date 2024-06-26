#include "Array.hpp"

template <typename T>
void printArray(Array<T>& _data) {
	for (size_t i = 0; i < _data.size(); ++i) {
		std::cout << _data[i] << " ";
	}
	std::cout << std::endl;
}

int main(void)
{
	std::cout << CYAN << "Tests with int" << RESET << std::endl;
	Array<int> intArray(5);
	for (size_t i = 0; i < intArray.size(); ++i) {
		intArray[i] = i + 1;
	}
	std::cout << "Int Array: ";
	printArray(intArray);

	std::cout << CYAN << "Tests with double" << RESET << std::endl;
	Array<double> doubleArray(5);
	for (size_t i = 0; i < doubleArray.size(); ++i) {
		doubleArray[i] = (i + 1) * 1.1;
	}
	std::cout << "Double Array: ";
	printArray(doubleArray);

	std::cout << CYAN << "Tests with string" << RESET << std::endl;
	Array<std::string> stringArray(3);
	stringArray[0] = "apple";
	stringArray[1] = "banana";
	stringArray[2] = "cherry";
	std::cout << "String Array: ";
	printArray(stringArray);

	std::cout << CYAN << "Copy and assignment test" << RESET << std::endl;
	Array<int> copyArray = intArray;
	std::cout << "Copied Array: ";
	printArray(copyArray);

	std::cout << CYAN << "Empty array test" << RESET << std::endl;
	Array<int> emptyArray;
	std::cout << "Empty Array size: " << emptyArray.size() << std::endl;

	return (0);
}


// int main()
// {
// 	Array<int>	a(4);
// 	Array<int>	b; // Empty array

//     b = a;
//     std::cout << CYAN << "*********** Create two arrays and do a = b ***********\n" << RESET << std::endl;
// 	for (size_t i = 0; i < a.size(); i += 1) {
// 		std::cout << "a[" << i << "] = " << a[i] << "\n";
// 	}
// 	std::cout << std::endl;
// 	for (size_t i = 0; i < b.size(); i += 1) {
// 		std::cout << "b[" << i << "] = " << b[i] << "\n";
// 	}
// 	a[0] = 1;
// 	a[1] = 2;
// 	a[2] = 3;
//     a[3] = 4;
// 	std::cout << std::endl;
// 	std::cout << CYAN << "*********** After modifying a's content (no impact on b) ***********\n" << RESET << std::endl;
// 	for (size_t i = 0; i < a.size(); i += 1) {
// 		std::cout << "a[" << i << "] = " << a[i] << "\n";
// 	}
// 	std::cout << std::endl;
// 	for (size_t i = 0; i < b.size(); i += 1) {
// 		std::cout << "b[" << i << "] = " << b[i] << "\n";
// 	}
//     std::cout << std::endl;
// 	std::cout << CYAN << "*********** Test invalid index exception ***********\n" << RESET << std::endl;
// 	// Test out of bound
//     try {
//         std::cout << a[a.size() + 1] << std::endl;
//     }
//     catch (std::exception& e) {
//         std::cout << RED << e.what() << RESET << std::endl;
//     }
//     std::cout << std::endl;

// 	return 0;
//}