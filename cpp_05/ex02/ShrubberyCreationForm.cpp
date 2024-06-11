#include "./includes/Bureaucrat.hpp"
#include "./includes/AForm.hpp"
#include "./includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << YELLOW << "ShrubberyCreationForm default constructor called" << RESET << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << YELLOW << "Attributes default constructor called" << RESET << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), _target(copy._target)
{
	std::cout << YELLOW << "ShrubberyCreationForm copy constructor called" << RESET << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator= (const ShrubberyCreationForm& copy)
{
	if (this == &copy)
		return (*this);
	std::cout << YELLOW << "ShrubberyCreationForm copy assignment operator overload" << RESET << std::endl;
	this->_target = copy._target;
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, ShrubberyCreationForm *a)
{
	out << YELLOW << "Form: " << a->getName() << "\tGrade to sign: " << a->getgradeToSign() <<"\tgrade to execute: " << a->getgradeToExecute() << "\tIs Signed? "<< (a->getisSigned() ? "yes ✅" : "no ❌") << RESET << std::endl;
	return (out);
}

std::string const &ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void    ShrubberyCreationForm::beSigned(const Bureaucrat& b)
{
	if (getisSigned())
		throw AForm::AFormAlreadySigned();
	if (b.getGrade() > getgradeToSign())
		throw AForm::GradeTooLowException();
	setSigned(true);
}

void	ShrubberyCreationForm::executeAction(Bureaucrat const& executor) const
{
	(void)executor;
	std::ofstream file((_target + "_shrubbery").c_str());
	if (file.is_open())
	{
		file << "                & \n";
		file << "              &  & &\n";
		file << "             &&  & &\n";
		file << "           & &&  & & &\n";
		file << "          &&& &&  & &&\n";
		file << "      && &\\/&\\|& ()|/ @,&&\n";
		file << "      &\\/(/&/&||/& /_/_)&/_&\n";
		file << "   &() &\\/&|()|/&\\/ '%\" & ()\n";
		file << "  &_\\_&&_\\ |& |&&/&__%_/_& &&\n";
		file << "&&   && & &| &| /& & % ()& /&&\n";
		file << "   ()&_---()&\\&\\|&&-&&--%---()~\n";
		file << "             &&|||&&\n";
		file << "             &&|||&&\n";
		file << "             &&|||&&\n";
		file << "             &&|||&&\n";
		file << "         , -=-~  .-^-, -=-~";
		file.close();
	}
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << YELLOW << "ShrubberyCreationForm destructor called" << RESET << std::endl;
}