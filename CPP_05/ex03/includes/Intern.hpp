#ifndef INTERN_HPP
# define INTERN_HPP

# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &i);
		Intern &operator=(const Intern &i);
		~Intern();

		AForm *makeForm(const std::string name, const std::string target);

		/* Exceptions */
		class InvalidFormName : public std::exception
		{
			virtual const char *what() const throw();
		};
};

#endif