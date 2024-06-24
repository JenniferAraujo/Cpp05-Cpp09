#include "whatever.hpp"

int main(void)
{
	std::cout << CYAN << "Tests with int" << RESET << std::endl;
	int x = 5, y = 10;
	std::cout << "Before swap: " << ORANGE << "x = " << RESET << x << ", " << ORANGE << "y = " << RESET << y << std::endl;
	swap(x, y);
	std::cout << "After swap: " << BLUE << "x = " << RESET << x << ", " << BLUE << "y = " << RESET << y << std::endl;

	int smallest_int = min(x, y);
	int largest_int = max(x, y);
	std::cout << "\nSmallest between x and y: " << MAGENTA << smallest_int << RESET << std::endl;
	std::cout << "Biggest between x and y: " << YELLOW << largest_int << RESET << std::endl;

	std::cout << std::endl;

	std::cout << CYAN << "Tests with doubles" << RESET << std::endl;
	double a = 3.14, b = 2.71;
	std::cout << "Before swap: " << ORANGE << "a = " << RESET << a << ", " << ORANGE << "b = " << RESET << b << std::endl;
	swap(a, b);
	std::cout << "After swap: " << BLUE << "a = " << RESET << a << ", " << BLUE << "b = " << RESET << b << std::endl;

	double smallest_double = min(a, b);
	double largest_double = max(a, b);
	std::cout << "\nSmallest between a and b: " << MAGENTA << smallest_double << RESET << std::endl;
	std::cout << "Biggest between a and b: " << YELLOW << largest_double << RESET << std::endl;

	std::cout << std::endl;

	std::cout << CYAN << "Tests with string" << RESET << std::endl;
	std::string s1 = "hello1", s2 = "hello2";
	std::cout << "Before swap: " << ORANGE << "s1 = " << RESET << s1 << ", " << ORANGE << "s2 = " << RESET << s2 << std::endl;
	swap(s1, s2);
	std::cout << "After swap: " << BLUE << "s1 = " << RESET << s1 << ", " << BLUE << "s2 = " << RESET << s2 << std::endl;

	std::string smallest_str = min(s1, s2);
	std::string Biggest_str = max(s1, s2);
	std::cout << "\nSmallest between s1 and s2: " << MAGENTA << smallest_str << RESET << std::endl;
	std::cout << "Biggest between s1 and s2: " << YELLOW << Biggest_str << RESET << std::endl;
}

// int main( void ) {
// 	int a = 2;
// 	int b = 3;
// 	::swap( a, b );
// 	std::cout << "a = " << a << ", b = " << b << std::endl; std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl; std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
// 	std::string c = "chaine1"; std::string d = "chaine2";
// 	::swap(c, d);
// 	std::cout << "c = " << c << ", d = " << d << std::endl; std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl; std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
// 	return 0;
// }