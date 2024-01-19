#include "../includes/Intern.hpp"

Intern::Intern() {
	std::cout << "Intern constructor" << std::endl;
}

Intern::Intern(const Intern &i)
{
	(void)i;
	std::cout << "Intern copy constructor" << std::endl;
}

Intern &Intern::operator=(const Intern &i)
{
	(void)i;
	std::cout << "Intern copy assignment operator" << std::endl;
	return (*this);
}

Intern::~Intern() {
	std::cout << "Intern destructor" << std::endl;
}

AForm *Intern::makeForm(const std::string name, const std::string target)
{
	std::string level[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	int i = 0;

	while ( i < 3 && name.compare(level[i]) != 0)
		i++;
	switch (i)
	{
		case 0:
			std::cout << "Intern creates form " << name << std::endl;
			return (new PresidentialPardonForm(target));
		case 1:
			std::cout << "Intern creates form " << name << std::endl;
			return (new RobotomyRequestForm(target));
		case 2:
			std::cout << "Intern creates form " << name << std::endl;
			return (new ShrubberyCreationForm(target));
		default:
			try { throw Intern::InvalidFormName(); }
			catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}
			return (NULL);
	}
}

const char *Intern::InvalidFormName::what() const throw()
{
	return ("Intern given invalid form name");
}
