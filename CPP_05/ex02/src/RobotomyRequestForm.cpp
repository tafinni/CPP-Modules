# include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robotomy", 72, 45), _target(NULL) {
	std::cout << "Robotomy default constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &r): AForm(r)
{
	std::cout << "Robotomy copy constructor" << std::endl;
	*this = r;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &r)
{
	if (this != &r)
	{
		this->setSigned(r.getSigned());
		this->_target = r._target;
		std::cout << "Robotomy copy assignment operator" << std::endl;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "Robotomy destructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target): AForm("Robotomy", 72, 45), _target(target) {
	std::cout << "Robotomy constructor" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	static int i;

	if (this->getSigned() == false)
		throw AForm::FormNotSigned();
	else if (this->getExGrade() < executor.getGrade())
		throw AForm::GradeTooLowException();

	i++;
	if ((i / 2) % 2 != 0)
		std::cout << this->_target << " has been robotomized" << std::endl;
	else
		throw RobotomyRequestForm::FailedRobotomy();
}

const char *RobotomyRequestForm::FailedRobotomy::what() const throw()
{
	return ("Exception, Robotomy failed");
}