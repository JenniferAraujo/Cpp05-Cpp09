#include "./includes/Bureaucrat.hpp"
#include "./includes/AForm.hpp"
#include "./includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << CYAN << "ShrubberyCreationForm default constructor called" << RESET << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << CYAN << "Attributes default constructor called" << RESET << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy) : AForm(cpy), _target(cpy._target)
{
	std::cout << CYAN << "ShrubberyCreationForm copy constructor called" << RESET << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator= (const ShrubberyCreationForm& copy)
{
	if (this == &copy)
		return (*this);
	std::cout << CYAN << "ShrubberyCreationForm copy assignment operator overload" << RESET << std::endl;
	this->_target = copy._target;
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, ShrubberyCreationForm *a)
{
	//rever isso aqui 
	out << "AForm: " << a->getName() << "\tgrade isSigned: " << a->getgradeToSign() <<"\tgrade execute: " << a->getgradeToExecute() << "\tisSigned: "<< (a->getisSigned() ? "yes ✅" : "no ❌") << std::endl;
	return (out);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << CYAN << "ShrubberyCreationForm destructor called" << RESET << std::endl;
}