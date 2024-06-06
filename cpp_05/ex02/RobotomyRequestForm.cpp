#include "./includes/Bureaucrat.hpp"
#include "./includes/AForm.hpp"
#include "./includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << CYAN << "RobotomyRequestForm default constructor called" << RESET << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << CYAN << "Attributes default constructor called" << RESET << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy) : AForm(cpy), _target(cpy._target)
{
	std::cout << CYAN << "RobotomyRequestForm copy constructor called" << RESET << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator= (const RobotomyRequestForm& copy)
{
	if (this == &copy)
		return (*this);
	std::cout << CYAN << "RobotomyRequestForm copy assignment operator overload" << RESET << std::endl;
	this->_target = copy._target;
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, RobotomyRequestForm *a)
{
	//rever isso aqui 
	out << "AForm: " << a->getName() << "\tgrade isSigned: " << a->getgradeToSign() <<"\tgrade execute: " << a->getgradeToExecute() << "\tisSigned: "<< (a->getisSigned() ? "yes ✅" : "no ❌") << std::endl;
	return (out);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << CYAN << "RobotomyRequestForm destructor called" << RESET << std::endl;
}