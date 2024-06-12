#include "./includes/PresidentialPardonForm.hpp"
#include "./includes/RobotomyRequestForm.hpp"
#include "./includes/ShrubberyCreationForm.hpp"
#include "./includes/Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& copy)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = copy;
}

Intern& Intern::operator= (const Intern& copy)
{
	if (this == &copy)
		return (*this);
	std::cout << CYAN << "Intern copy assignment operator overload" << RESET << std::endl;
	return (*this);
}

AForm* Intern::createShrubbery(const std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string formName, const std::string target)
{
	std::string formNames[] = {"ShrubberyCreation", "RobotomyRequest", "PresidentialPardon"};
	AForm* (*formCreators[])(const std::string) = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPresidential
	};
	for (int i = 0; i < 3; ++i)
	{
		if (formNames[i] == formName) {
			std::cout << "Intern creates " << formName << std::endl;
			return ((*formCreators[i])(target));
		}
	}
	std::cout << "Error: Unknown form name " << formName << std::endl;
	return (NULL);
}

Intern::~Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}



