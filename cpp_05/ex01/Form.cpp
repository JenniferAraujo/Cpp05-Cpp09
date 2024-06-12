#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form(): _name("Name"), _gradeToSign(150), _gradeToExecute(150), _isSigned(false)
{
	std::cout << CYAN << "Form default constructor called" << RESET << std::endl;
}

Form::Form(std::string name, const int gradeToSign, const int gradeToExecute): _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _isSigned(false)
{
	std::cout << CYAN << "Attributes default constructor called" << RESET << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw (GradeTooHighException());
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw (GradeTooLowException());
}

Form::Form(const Form& copy): _name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute), _isSigned(copy._isSigned)
{
	std::cout << CYAN << "Form copy constructor called" << RESET << std::endl;
}

Form& Form::operator= (const Form& copy)
{
	if (this == &copy)
		return (*this);
	std::cout << CYAN << "Form copy assignment operator overload" << RESET << std::endl;
	_isSigned = copy._isSigned;
	return (*this);
}

std::string const &Form::getName() const
{
	return (this->_name);
}

int	const &Form::getgradeToExecute() const
{
	return (this->_gradeToExecute);
}

int	const &Form::getgradeToSign() const
{
	return (this->_gradeToSign);
}

bool    Form::getisSigned() const
{
	return (this->_isSigned);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("\e[0;31mGrade is too high! 😞\033[0m");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("\e[0;31mGrade is to low! 😞\033[0m");
}

const char* Form::gradeToSignTooHighException::what() const throw()
{
	return ("\e[0;31mGrade isSigned is too high! 😞\033[0m");
}

const char* Form::gradeToSignTooLowException::what() const throw()
{
	return ("\e[0;31mGrade isSigned is to low! 😞\033[0m");
}

const char* Form::FormAlreadySigned::what() const throw()
{
	return ("\e[0;31mForm is already signed! ⛔\033[0m");
}

void    Form::beSigned(const Bureaucrat& b)
{
	if (_isSigned)
		throw FormAlreadySigned();
	if (b.getGrade() > _gradeToSign)
		throw (gradeToSignTooLowException());
	_isSigned = true;
}

std::ostream	&operator<<(std::ostream &out, Form *a)
{
	out << "Form: " << a->getName() << "\tgrade isSigned: " << a->getgradeToSign() <<"\tgrade execute: " << a->getgradeToExecute() << "\tisSigned: "<< (a->getisSigned() ? "yes ✅" : "no ❌") << std::endl;
	return (out);
}

Form::~Form()
{
	std::cout << CYAN << "Form destructor called" << RESET << std::endl;
}
