#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
    _name = "Name";
	_grade = 150;
    std::cout << CYAN << "Bureaucrat default constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade)
{
	_name = name;
    _grade = grade;
	std::cout << CYAN << "Name default constructor called" << RESET << std::endl;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& copy)
{
	*this = copy;
    std::cout << CYAN << "Bureaucrat copy constructor called" << RESET << std::endl;
}

// Copy assignment operator overload
Bureaucrat& Bureaucrat::operator= (const Bureaucrat& copy)
{
    if (this == &copy)
        return (*this);
    std::cout << CYAN << "Bureaucrat copy assignment operator overload" << RESET << std::endl;
    _name = copy._name;
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

// Bureaucrat::GradeTooHighException()
// {

// }


Bureaucrat::~Bureaucrat()
{
	std::cout << CYAN << "Bureaucrat destructor called" << RESET << std::endl;
}
