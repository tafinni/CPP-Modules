#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool	_signed;
		const int _signGrade;
		const int _exGrade;
	
	public:
		Form();
		Form(const Form &f);
		Form &operator=(const Form &f);
		~Form();

		Form(std::string name, int signGrade, int exGrade);

		const std::string	getName() const;
		bool				getSigned() const;
		int					getSignGrade() const;
		int					getExGrade() const;

		void beSigned(const Bureaucrat &b);


	/* Exceptions */
	class GradeTooHighException: public std::exception
	{
		public:
			virtual const char *what() const throw(); 
	};
	class GradeTooLowException: public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &s, Form &f);

#endif // FORM_HPP