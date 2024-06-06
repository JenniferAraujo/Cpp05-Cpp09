#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Name")
{
	_grade = 150;
	std::cout << CYAN << "Bureaucrat default constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade): _name(name)
{
	_grade = grade;
	std::cout << CYAN << "Name and Grade default constructor called" << RESET << std::endl;
	if (grade < 1)
		throw (GradeTooLowException());
	else if (grade > 150)
		throw (GradeTooHighException());

}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& copy): _name(copy._name)
{
	_grade = copy._grade;
	std::cout << CYAN << "Bureaucrat copy constructor called" << RESET << std::endl;
}

// Copy assignment operator overload
Bureaucrat& Bureaucrat::operator= (const Bureaucrat& copy)
{
	if (this == &copy)
		return (*this);
	std::cout << CYAN << "Bureaucrat copy assignment operator overload" << RESET << std::endl;
	_grade = copy._grade;
	return (*this);
}

std::string const &Bureaucrat::getName() const
{
	return (this->_name);
}

int const &Bureaucrat::getGrade() const
{
	return (this->_grade);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("\e[0;31mGrade is too high! 😞\033[0m");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("\e[0;31mGrade is to loow! 😞\033[0m");
}

void	Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

std::ostream	&operator<<(std::ostream &out, Bureaucrat *a)
{
	out << "Bureaucrat " << a->getName() << "\n\tgrade: " << a->getGrade() << std::endl;
	return (out);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << CYAN << "Bureaucrat destructor called" << RESET << std::endl;
}