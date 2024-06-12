#include "./includes/Bureaucrat.hpp"
#include "./includes/AForm.hpp"
#include "./includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << ORANGE << "RobotomyRequestForm default constructor called" << RESET << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << ORANGE << "Attributes default constructor called" << RESET << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy) : AForm(cpy), _target(cpy._target)
{
	std::cout << ORANGE << "RobotomyRequestForm copy constructor called" << RESET << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator= (const RobotomyRequestForm& copy)
{
	if (this == &copy)
		return (*this);
	std::cout << ORANGE << "RobotomyRequestForm copy assignment operator overload" << RESET << std::endl;
	this->_target = copy._target;
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, RobotomyRequestForm *a)
{
	out << ORANGE << "Form: " << a->getName() << "\tGrade to sign: " << a->getgradeToSign() <<"\tgrade to execute: " << a->getgradeToExecute() << "\tIs Signed? "<< (a->getisSigned() ? "yes ✅" : "no ❌") << RESET << std::endl;
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

void	RobotomyRequestForm::executeAction(Bureaucrat const& executor) const
{
	(void)executor;
	std::cout << "BZZZZZZZ... VRRRRR... 🤖" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << ORANGE << _target << " has been robotomized successfully." << RESET << std::endl;
	else
		std::cout << ORANGE << "The robotomy of " << _target << " has failed." << RESET << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << ORANGE << "RobotomyRequestForm destructor called" << RESET << std::endl;
}
