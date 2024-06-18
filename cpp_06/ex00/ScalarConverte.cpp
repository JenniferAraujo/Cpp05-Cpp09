#include "ScalarConverte.hpp"

ScalarConverte::ScalarConverte()
{
	std::cout << BLUE << "ScalarConverte default constructor called" << RESET << std::endl;
}

ScalarConverte::ScalarConverte(std::string const string): _string(string)
{
	std::cout << BLUE << "Attributes default constructor called" << RESET << std::endl;
}

ScalarConverte::ScalarConverte(const ScalarConverte& copy): _string(copy._string), _char(copy._char), _int(copy._int), _float(copy._float), _double(copy._double)
{
	std::cout << BLUE << "ScalarConverte copy constructor called" << RESET << std::endl;
}

ScalarConverte& ScalarConverte::operator= (const ScalarConverte& copy)
{
	if (this == &copy)
		return *this;
	std::cout << BLUE << "ScalarConverte copy assignment operator overload" << RESET << std::endl;
	_string = copy._string; 
	_char = copy._char; 
	_int = copy._int; 
	_float = copy._float;
	_double = copy._double;
	return (*this);
}

ScalarConverte::~ScalarConverte()
{
	std::cout << BLUE << "ScalarConverte destructor called" << RESET << std::endl;
}