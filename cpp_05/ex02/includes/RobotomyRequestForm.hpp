#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
		private:
			std::string _target;
		public:
			RobotomyRequestForm();
			RobotomyRequestForm(std::string target);
			RobotomyRequestForm(const RobotomyRequestForm& copy);
			RobotomyRequestForm& operator= (const RobotomyRequestForm& copy);

			~RobotomyRequestForm();
};

std::ostream	&operator<<(std::ostream &out, RobotomyRequestForm *a);

#endif