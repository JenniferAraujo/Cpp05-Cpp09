#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form {
    private: 
        const std::string _name; //nome
        const int     _gradeToSign; //grade minimo p assinar o form
        const int     _gradeToExecute; //grade minimo p executar o form
        bool    _isSigned; //bool p saber se o form ja foi assinado

    public:
        Form();
        Form(std::string name, const int gradeToSign, const int gradeToExecute);
        Form(const Form& copy); //copy constructor
		
        //Getters
        std::string const &getName() const;
        int	const &getgradeToExecute() const;
        int	const &getgradeToSign() const;
	    bool    getisSigned() const;

        //methods
        void    beSigned(const Bureaucrat& b); //altera o status do form p assinar 
        void    signForm(Form& form); //tenta assinar um form

		Form& operator= (const Form& copy);
        ~Form();

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
};

std::ostream	&operator<<(std::ostream &out, Form *a);

#endif