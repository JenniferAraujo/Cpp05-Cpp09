#include "./includes/Bureaucrat.hpp"
#include "./includes/AForm.hpp"
#include "./includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << CYAN << "PresidentialPardonForm default constructor called" << RESET << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << CYAN << "Attributes default constructor called" << RESET << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpy) : AForm(cpy), _target(cpy._target)
{
	std::cout << CYAN << "PresidentialPardonForm copy constructor called" << RESET << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator= (const PresidentialPardonForm& copy)
{
	if (this == &copy)
		return (*this);
	std::cout << CYAN << "PresidentialPardonForm copy assignment operator overload" << RESET << std::endl;
	this->_target = copy._target;
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, PresidentialPardonForm *a)
{
	//rever isso aqui 
	out << "AForm: " << a->getName() << "\tgrade isSigned: " << a->getgradeToSign() <<"\tgrade execute: " << a->getgradeToExecute() << "\tisSigned: "<< (a->getisSigned() ? "yes ✅" : "no ❌") << std::endl;
	return (out);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << CYAN << "PresidentialPardonForm destructor called" << RESET << std::endl;
}