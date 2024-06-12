#include "./includes/Bureaucrat.hpp"
#include "./includes/AForm.hpp"
#include "./includes/PresidentialPardonForm.hpp"
#include "./includes/RobotomyRequestForm.hpp"
#include "./includes/ShrubberyCreationForm.hpp"

int main(void)
{
	try
	{
		std::cout << "\n-------* Constructors *------- \n";

		Bureaucrat assistant("Assistant", 100);
		Bureaucrat ceo("CEO", 1);

		AForm *presidentialForm = new PresidentialPardonForm("Some dude");
		AForm *robotomyForm = new RobotomyRequestForm("Target");
		AForm *shrubberyForm = new ShrubberyCreationForm("Home");

		std::cout << "\n-------* Attempting to execute forms without signature *-------\n";
		assistant.executeForm(*presidentialForm);
		ceo.executeForm(*robotomyForm);
		assistant.executeForm(*shrubberyForm);
		std::cout << std::endl;
		std::cout << "\n-------* Signing forms *-------\n";
		ceo.signForm(*presidentialForm);
		ceo.signForm(*robotomyForm);
		assistant.signForm(*shrubberyForm);
		std::cout << std::endl;
		std::cout << "\n-------* Executing forms *-------\n";
		assistant.executeForm(*presidentialForm);
		ceo.executeForm(*robotomyForm);
		assistant.executeForm(*shrubberyForm);
		std::cout << std::endl;
		std::cout << "\n-------* Attempting to create bureaucrats with invalid grade *-------\n";
		try {
			Bureaucrat invalidBureaucrat("Invalid", 0);
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
		std::cout << "\n-------* Attempting to execute forms with invalid grade *-------\n";
		try {
			assistant.executeForm(*presidentialForm);
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
		std::cout << "\n-------* Attempting to sign forms with bureaucrats with invalid grade *-------\n";
		try {
			assistant.signForm(*presidentialForm);
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
		std::cout << "\n-------* Attempting to execute forms with unsigned bureaucrats *-------\n";
		try {
			Bureaucrat unSigned("Unsigned", 50);
			unSigned.executeForm(*presidentialForm);
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << "\n-------* Destructors *-------\n";
		delete presidentialForm;
		delete robotomyForm;
		delete shrubberyForm;
	}
	catch (const std::exception &e) {
		std::cout << "\033[31mError: " << e.what() << "\033[0m\n";
	}
	return (0);
}
