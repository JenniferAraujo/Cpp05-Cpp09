#include "Bureaucrat.hpp"

int main(void)
{
	try {
		Bureaucrat bob("Bob", 2);
		std::cout << GREEN << &bob << RESET << std::endl;
		bob.incrementGrade(); 
		std::cout << GREEN << &bob << RESET << std::endl;
		bob.incrementGrade();
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cout << e.what() << std::endl; }
	catch (const Bureaucrat::GradeTooLowException& e){
		std::cout << e.what() << std::endl; }

	try
	{
		Bureaucrat alice("Alice", 150);
		std::cout << MAGENTA << &alice << RESET << std::endl;
		alice.decrementGrade();
		std::cout << MAGENTA << &alice << RESET << std::endl;
		alice.decrementGrade();
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cout << e.what() << std::endl; }
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << std::endl; }

	return (0);
}