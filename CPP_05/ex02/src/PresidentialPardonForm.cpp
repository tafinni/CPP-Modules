#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential", 25, 5), _target(NULL) {
	std::cout << "Presidential default constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &p): AForm(p)
{
	std::cout << "Presidential copy constructor" << std::endl;
	*this = p;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &p)
{
	if (this != &p)
	{
		this->_target = p._target;
		this->setSigned(p.getSigned());
		std::cout << "Presidential copy assignment operator" << std::endl;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "Presidential destructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target): AForm("Presidential", 25, 5), _target(target) {
	std::cout << "Presidential constructor" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
		throw AForm::FormNotSigned();
	else if (this->getExGrade() < executor.getGrade())
		throw AForm::GradeTooLowException();
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
