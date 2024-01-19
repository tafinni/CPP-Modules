#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "AForm.hpp"
# include <iostream>

class AForm;

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;

	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &b);
		Bureaucrat &operator=(const Bureaucrat &b);
		~Bureaucrat();

		Bureaucrat(std::string name, int grade);

		std::string getName();
		int			getGrade() const;

		void	increment();
		void	decrement();

		void	signForm(AForm &f);

		void	executeForm(AForm const & form);

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

std::ostream &operator<<(std::ostream &stream, Bureaucrat &b);

#endif // BUREAUCRAT_HPP