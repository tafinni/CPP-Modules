#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &r);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &r);
		~RobotomyRequestForm();

		RobotomyRequestForm(const std::string target);

		void execute(Bureaucrat const & executor) const;

		/* Exceptions */
		class FailedRobotomy: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif // ROBOTOMYREQUESTFORM_HPP