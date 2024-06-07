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
	out << "Form: " << a->getName() << "\tGrade to sign: " << a->getgradeToSign() <<"\tgrade to execute: " << a->getgradeToExecute() << "\tIs Signed? "<< (a->getisSigned() ? "yes ✅" : "no ❌") << std::endl;
	return (out);
}

std::string const &RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void RobotomyRequestForm::beSigned(const Bureaucrat& b)
{
	if (getisSigned())
		throw AForm::AFormAlreadySigned();
	if (b.getGrade() > getgradeToSign())
		throw AForm::GradeTooLowException();
	setSigned(true);
}

void	RobotomyRequestForm::executeAction()const
{
	std::cout << "BZZZZZZZ... VRRRRR... 🤖" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "The robotomy of " << _target << " has failed." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << CYAN << "RobotomyRequestForm destructor called" << RESET << std::endl;
}
