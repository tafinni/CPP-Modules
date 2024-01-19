#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "../includes/AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &s);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &s);
		~ShrubberyCreationForm();

		ShrubberyCreationForm(const std::string target);

		void execute(Bureaucrat const & executor) const;

		/* Exceptions */
		class NoOpenFile: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif // SHRUBBERYCREATIONFORM_HPP