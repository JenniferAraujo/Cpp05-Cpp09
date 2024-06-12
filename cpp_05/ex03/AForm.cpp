#include "./includes/Bureaucrat.hpp"
#include "./includes/AForm.hpp"

AForm::AForm(): _name("Name"), _gradeToSign(150), _gradeToExecute(150), _isSigned(false)
{
	std::cout << CYAN << "AForm default constructor called" << RESET << std::endl;
}

AForm::AForm(std::string name, const int gradeToSign, const int gradeToExecute): _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _isSigned(false)
{
	std::cout << CYAN << "Attributes default constructor called" << RESET << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw (GradeTooHighException());
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw (GradeTooLowException());
}

AForm::AForm(const AForm& copy): _name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute), _isSigned(copy._isSigned)
{
	std::cout << CYAN << "AForm copy constructor called" << RESET << std::endl;
}

AForm& AForm::operator= (const AForm& copy)
{
	if (this == &copy)
		return (*this);
	std::cout << CYAN << "AForm copy assignment operator overload" << RESET << std::endl;
	_isSigned = copy._isSigned;
	return (*this);
}

std::string const &AForm::getName() const
{
	return (this->_name);
}

int	const &AForm::getgradeToExecute() const
{
	return (this->_gradeToExecute);
}

int	const &AForm::getgradeToSign() const
{
	return (this->_gradeToSign);
}

bool    AForm::getisSigned() const
{
	return (this->_isSigned);
}

void AForm::setSigned(bool signedStatus)
{
    _isSigned = signedStatus;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("\e[0;31mGrade is too high! 😞\033[0m");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("\e[0;31mGrade is to low! 😞\033[0m");
}

const char* AForm::gradeToSignTooHighException::what() const throw()
{
	return ("\e[0;31mGrade isSigned is too high! 😞\033[0m");
}

const char* AForm::gradeToSignTooLowException::what() const throw()
{
	return ("\e[0;31mGrade isSigned is to low! 😞\033[0m");
}

const char* AForm::AFormAlreadySigned::what() const throw()
{
	return ("\e[0;31mAForm is already signed! ⛔\033[0m");
}

const char* AForm::FormNotSigned::what() const throw()
{
	return ("\e[0;31mAForm not signed! ⛔\033[0m");
}

void	AForm::execute(Bureaucrat const& executor) const
{
    if (!_isSigned)
        throw FormNotSigned();
    if (executor.getGrade() > _gradeToExecute)
        throw GradeTooLowException();
    this->executeAction(executor);
}

std::ostream	&operator<<(std::ostream &out, AForm *a)
{
	out << CYAN << "AForm: " << a->getName() << "\tgrade isSigned: " << a->getgradeToSign() <<"\tgrade execute: " << a->getgradeToExecute() << "\tisSigned: "<< (a->getisSigned() ? "yes ✅" : "no ❌") << RESET << std::endl;
	return (out);
}

AForm::~AForm()
{
	std::cout << CYAN << "AForm destructor called" << RESET << std::endl;
}
