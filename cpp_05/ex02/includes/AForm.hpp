#ifndef AFORM_HPP
# define AFORM_HPP

#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private: 
		const std::string _name; //nome
		const int	_gradeToSign; //grade minimo p assinar o Aform
		const int	_gradeToExecute; //grade minimo p executar o Aform
		bool		_isSigned; //bool p saber se o Aform ja foi assinado

	public:
		AForm();
		AForm(std::string name, const int gradeToSign, const int gradeToExecute);
		AForm(const AForm& copy); //copy constructor
		
		//Getters
		std::string const &getName() const;
		int	const &getgradeToExecute() const;
		int	const &getgradeToSign() const;
		bool	getisSigned() const;
		void	setSigned(bool signedStatus);

		virtual void	beSigned(const Bureaucrat& b) = 0; //altera o status do Aform p assinar 

		AForm& operator= (const AForm& copy);
		~AForm();

		class GradeTooHighException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
		class gradeToSignTooHighException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
		class gradeToSignTooLowException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
		class AFormAlreadySigned : public std::exception{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, AForm *a);

#endif