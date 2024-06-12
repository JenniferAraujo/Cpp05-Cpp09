#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		std::string _target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		ShrubberyCreationForm& operator= (const ShrubberyCreationForm& copy);

		//methods
		std::string  const &getTarget() const;
		void	executeAction(Bureaucrat const& executor) const;
		void	beSigned(const Bureaucrat& b);

		~ShrubberyCreationForm();
};

std::ostream	&operator<<(std::ostream &out, ShrubberyCreationForm *a);

#endif