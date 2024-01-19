#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

int	main()
{
	Bureaucrat				First("First", 150);
	Bureaucrat				Second("Second", 1);
	PresidentialPardonForm	Presidential("Test1");
	RobotomyRequestForm		Robotomy("Test2");
	ShrubberyCreationForm	Shrubbery("Test3");

	
	std::cout << std::endl << "PRESIDENTIAL FORM" << std::endl;
	std::cout << "--- Testing signing form with too low grade ---" << std::endl;
	First.signForm(Presidential);

	std::cout << std::endl << "--- Singing form, should work ---" << std::endl;
	Second.signForm(Presidential);

	std::cout << std::endl << "--- Testing executing form with too low grade ---" << std::endl;
	First.executeForm(Presidential);

	std::cout << std::endl << "--- Executing, should work ---" << std::endl;
	Second.executeForm(Presidential);



	std::cout << std::endl << "ROBOROMY FORM" << std::endl;
	std::cout << "--- Testing signing form with too low grade ---" << std::endl;
	First.signForm(Robotomy);

	std::cout << std::endl << "--- Singing form, should work ---" << std::endl;
	Second.signForm(Robotomy);

	std::cout << std::endl << "--- Testing executing form with too low grade ---" << std::endl;
	First.executeForm(Robotomy);

	std::cout << std::endl << "--- Executing, should work ---" << std::endl;
	Second.executeForm(Robotomy);
	Second.executeForm(Robotomy);
	Second.executeForm(Robotomy);
	Second.executeForm(Robotomy);
	Second.executeForm(Robotomy);
	Second.executeForm(Robotomy);
	Second.executeForm(Robotomy);
	Second.executeForm(Robotomy);

	std::cout << std::endl << "SHRUBBERY FORM" << std::endl;
	std::cout << "--- Testing signing form with too low grade ---" << std::endl;
	First.signForm(Shrubbery);

	std::cout << std::endl << "--- Singing form, should work ---" << std::endl;
	Second.signForm(Shrubbery);

	std::cout << std::endl << "--- Testing executing form with too low grade ---" << std::endl;
	First.executeForm(Shrubbery);

	std::cout << std::endl << "--- Executing, should work ---" << std::endl;
	Second.executeForm(Shrubbery);


	std::cout << std::endl;
	return (0);
}