#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string _target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		PresidentialPardonForm& operator= (const PresidentialPardonForm& copy);

		void	beSigned(const Bureaucrat& b);
		void	executeAction(Bureaucrat const& executor) const;

		~PresidentialPardonForm();
};

std::ostream	&operator<<(std::ostream &out, PresidentialPardonForm *a);

#endif