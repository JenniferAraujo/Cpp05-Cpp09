#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try {
		Bureaucrat john("John", 50);
		Form formA("FormA", 30, 10);
		Form formB("FormB", 60, 20);

		john.signForm(formA);
		john.signForm(formB);
		john.signForm(formB);

		std::cout << MAGENTA << &formA << RESET << std::endl;
		std::cout << MAGENTA << &formB << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}