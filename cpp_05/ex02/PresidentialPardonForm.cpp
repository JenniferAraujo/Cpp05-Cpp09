#include "./includes/Bureaucrat.hpp"
#include "./includes/AForm.hpp"
#include "./includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << MAGENTA << "PresidentialPardonForm default constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << MAGENTA << "Attributes default constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpy) : AForm(cpy), _target(cpy._target)
{
	std::cout << MAGENTA << "PresidentialPardonForm copy constructor called" << RESET << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator= (const PresidentialPardonForm& copy)
{
	if (this == &copy)
		return (*this);
	std::cout << MAGENTA << "PresidentialPardonForm copy assignment operator overload" << RESET << std::endl;
	this->_target = copy._target;
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, PresidentialPardonForm *a)
{
	out << MAGENTA << "Form: " << a->getName() << "\tGrade to sign: " << a->getgradeToSign() <<"\tgrade to execute: " << a->getgradeToExecute() << "\tIs Signed? "<< (a->getisSigned() ? "yes ✅" : "no ❌") << RESET << std::endl;
	return (out);
}

void PresidentialPardonForm::beSigned(const Bureaucrat& b)
{
	if (getisSigned())
		throw AForm::AFormAlreadySigned();
	if (b.getGrade() > getgradeToSign())
		throw AForm::GradeTooLowException();
	setSigned(true);
}

void	PresidentialPardonForm::executeAction(Bureaucrat const& executor) const
{
	(void)executor;
	std::cout << MAGENTA <<  _target << " has been pardoned by Zaphod Beeblebrox." << RESET << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << MAGENTA << "PresidentialPardonForm destructor called" << RESET << std::endl;
}