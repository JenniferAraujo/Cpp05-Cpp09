#include "./includes/Bureaucrat.hpp"
#include "./includes/AForm.hpp"
#include "./includes/PresidentialPardonForm.hpp"
#include "./includes/RobotomyRequestForm.hpp"
#include "./includes/ShrubberyCreationForm.hpp"

int main(void)
{
	try {
		Bureaucrat john("John", 50);
		// AForm formB("FormB", 60, 20);

		// john.signForm(formA);
		// john.signForm(formB);
		// john.signForm(formB);

		// std::cout << MAGENTA << &formA << RESET << std::endl;
		// std::cout << MAGENTA << &formB << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}