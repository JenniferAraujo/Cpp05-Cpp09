#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <cctype>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <iomanip> 
# include <cstdlib>
# include <ctime>

# define CYAN    "\e[0;36m"
# define MAGENTA "\033[0;35m"
# define YELLOW  "\e[0;33m"
# define GREEN	"\e[0;32m"
# define ORANGE	"\e[38;5;208m"
# define RED	"\e[0;31m"
# define RESET "\033[0m"

class Bureaucrat
{
	private: 
		std::string	_name;
		int	_grade;
	public:
		//constructors
		Bureaucrat();
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(const Bureaucrat& copy);
		
		Bureaucrat& operator= (const Bureaucrat& copy);
		
		//methods
		std::string const &getName() const;
		int	const &getGrade() const;
		void	incrementGrade();
		void	decrementGrade();

		//destructors
		~Bureaucrat();

		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, Bureaucrat *a);

#endif