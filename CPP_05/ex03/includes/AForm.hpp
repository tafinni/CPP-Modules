#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool	_signed;
		const int _signGrade;
		const int _exGrade;
		virtual void execute(Bureaucrat const & executor) const = 0;
	
	public:
		AForm();
		AForm(const AForm &f);
		AForm &operator=(const AForm &f);
		~AForm();

		AForm(std::string name, int signGrade, int exGrade);

		const std::string	getName() const;
		bool				getSigned() const;
		int					getSignGrade() const;
		int					getExGrade() const;

		void beSigned(const Bureaucrat &b);

		void setSigned(const bool result);

		int formRights(const Bureaucrat &b) const;


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
	class FormNotSigned: public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &s, AForm &f);

#endif // AFORM_HPP