#include "../includes/Intern.hpp"

int	main()
{
	Intern Intern;
	Bureaucrat First("First", 150);
	Bureaucrat Second("Second", 1);
	
	std::cout << std::endl << "WRONG NAME" << std::endl;
	AForm *Test = Intern.makeForm("NotName", "OK");
	(void)Test;

	std::cout << std::endl << "PRESIDENTIAL FORM" << std::endl;
	AForm *Presidential = Intern.makeForm("PresidentialPardonForm", "OK");

	std::cout << std::endl << "--- Testing signing form with too low grade ---" << std::endl;
	First.signForm(*Presidential);

	std::cout << std::endl << "--- Singing form, should work ---" << std::endl;
	Second.signForm(*Presidential);

	std::cout << std::endl << "--- Testing executing form with too low grade ---" << std::endl;
	First.executeForm(*Presidential);

	std::cout << std::endl << "--- Executing, should work ---" << std::endl;
	Second.executeForm(*Presidential);


	std::cout << std::endl << "ROBOTOMY FORM" << std::endl;
	AForm *Robotomy = Intern.makeForm("RobotomyRequestForm", "OK");

	std::cout << "--- Testing signing form with too low grade ---" << std::endl;
	First.signForm(*Robotomy);

	std::cout << std::endl << "--- Singing form, should work ---" << std::endl;
	Second.signForm(*Robotomy);

	std::cout << std::endl << "--- Testing executing form with too low grade ---" << std::endl;
	First.executeForm(*Robotomy);

	std::cout << std::endl << "--- Executing, should work ---" << std::endl;
	Second.executeForm(*Robotomy);
	Second.executeForm(*Robotomy);
	Second.executeForm(*Robotomy);
	Second.executeForm(*Robotomy);
	Second.executeForm(*Robotomy);
	Second.executeForm(*Robotomy);
	Second.executeForm(*Robotomy);
	Second.executeForm(*Robotomy);


	std::cout << std::endl << "SHRUBBERY FORM" << std::endl;
	AForm *Shrubbery = Intern.makeForm("ShrubberyCreationForm", "OK");

	std::cout << "--- Testing signing form with too low grade ---" << std::endl;
	First.signForm(*Shrubbery);

	std::cout << std::endl << "--- Signing form, should work ---" << std::endl;
	Second.signForm(*Shrubbery);

	std::cout << std::endl << "--- Testing executing form with too low grade ---" << std::endl;
	First.executeForm(*Shrubbery);

	std::cout << std::endl << "--- Executing, should work ---" << std::endl;
	Second.executeForm(*Shrubbery);


	std::cout << std::endl;
	return (0);
}