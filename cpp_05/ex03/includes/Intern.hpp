#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <string>

class   Intern {
	public:
		Intern();
		Intern(const Intern& copy);
		Intern& operator= (const Intern& copy);

		//Forms
		static AForm	*createShrubbery(const std::string target);
		static AForm	*createRobotomy(const std::string target);
		static AForm	*createPresidential(const std::string target);

		//makeForm
		AForm* makeForm(const std::string formName, const std::string target);
		~Intern();

};

#endif