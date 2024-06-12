#include "./includes/Intern.hpp"

int main(void)
{
	std::cout << "\n-------* Constructors *------- \n";
	Intern someRandomIntern;
	Bureaucrat bob("Bob", 1);
	AForm* form;

	std::cout << "\n-------* Creating and execute RobotomyRequest *------- \n";
	form = someRandomIntern.makeForm("RobotomyRequest", "Bender");
	if (form)
	{
		form->beSigned(bob);
		bob.executeForm(*form);
		delete form;
	}
	std::cout << "\n-------* Creating and execute ShrubberyCreation *------- \n";
	form = someRandomIntern.makeForm("ShrubberyCreation", "Home");
	if (form)
	{
		form->beSigned(bob);
		bob.executeForm(*form);
		delete form;
	}
	std::cout << "\n-------* Creating and execute PresidentialPardon *------- \n";
	form = someRandomIntern.makeForm("PresidentialPardon", "Alice");
	if (form)
	{
		form->beSigned(bob);
		bob.executeForm(*form);
		delete form;
	}
	std::cout << "\n-------* Creating invalid form *------- \n";
	form = someRandomIntern.makeForm("Unknown Form", "Target");
	if (form)
		delete form;
	return (0);
}

