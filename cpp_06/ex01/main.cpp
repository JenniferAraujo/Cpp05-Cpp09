#include "Serialization.hpp"

int main(void)
{
	Data test;
	test._type = "Elephant";
	test._age = 42;

	std::cout << "Data test address before serialize => " << CYAN << &test << RESET << std::endl;
	std::cout << "Test _type is " << CYAN << test._type << RESET << " and it is " << CYAN << test._age << RESET << " years old" << std::endl;

	uintptr_t test1 = Serialization::serialize(&test);
	std::cout << "Serialized variable test1 " << ORANGE << test1 << RESET << std::endl;

	Data* test2 = Serialization::deserialize(test1);
	std::cout << "After deserialization, the address is => " << CYAN << test2 << RESET << std::endl;
	std::cout << "And test _type is still " << CYAN << test2->_type << RESET << " and it is still " << CYAN << test2->_age << RESET << " years old" << std::endl;

	if (test2 == &test && test2->_type == test._type && test2->_age == test._age) {
		std::cout << ORANGE << "Serialization and deserialization were successful!" << RESET << std::endl;
	} else {
		std::cout << ORANGE << "Serialization and deserialization failed!" << RESET << std::endl;
	}

	// Test with long string
	Data test3;
	test3._type = std::string(1000, 'A');
	test3._age = 5;

	std::cout << "\nData test3 address before serialize => " << CYAN << &test3 << RESET << std::endl;
	std::cout << "Test3 _type is " << CYAN << test3._type.substr(0, 20) << "..." << RESET << " (truncated) and it is " << CYAN << test3._age << RESET << " years old" << std::endl;

	uintptr_t test4 = Serialization::serialize(&test3);
	std::cout << "Serialized variable test4 " << ORANGE << test4 << RESET << std::endl;

	Data* test5 = Serialization::deserialize(test4);
	std::cout << "After deserialization, the address is => " << CYAN << test5 << RESET << std::endl;
	std::cout << "And test3 _type is still " << CYAN << test5->_type.substr(0, 20) << "..." << RESET << " (truncated) and it is still " << CYAN << test5->_age << RESET << " years old" << std::endl;

	if (test5 == &test3 && test5->_type == test3._type && test5->_age == test3._age) {
		std::cout << ORANGE << "Serialization and deserialization of test3 were successful!" << RESET << std::endl;
	} else {
		std::cout << ORANGE << "Serialization and deserialization of test3 failed!" << RESET << std::endl;
	}

	// Test with extreme values
	Data test6;
	test6._type = "Cat";
	test6._age = std::numeric_limits<int>::max();

	std::cout << "\nData test6 address before serialize => " << CYAN << &test6 << RESET << std::endl;
	std::cout << "Test6 _type is " << CYAN << test6._type << RESET << " and it is " << CYAN << test6._age << RESET << " years old" << std::endl;

	uintptr_t test7 = Serialization::serialize(&test6);
	std::cout << "Serialized variable test7 " << ORANGE << test7 << RESET << std::endl;

	Data* test8 = Serialization::deserialize(test7);
	std::cout << "After deserialization, the address is => " << CYAN << test8 << RESET << std::endl;
	std::cout << "And test6 _type is still " << CYAN << test8->_type << RESET << " and it is still " << CYAN << test8->_age << RESET << " years old" << std::endl;

	if (test8 == &test6 && test8->_type == test6._type && test8->_age == test6._age) {
		std::cout << ORANGE << "Serialization and deserialization of test6 were successful!" << RESET << std::endl;
	} else {
		std::cout << ORANGE << "Serialization and deserialization of test6 failed!" << RESET << std::endl;
	}
}
