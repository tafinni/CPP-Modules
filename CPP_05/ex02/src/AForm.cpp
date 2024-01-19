#include "../includes/AForm.hpp"

AForm::AForm(): _signGrade(1), _exGrade(1)
{
	std::cout << "AForm default constructor" << std::endl;
}

AForm::AForm(const AForm &f): _name(f._name), _signed(f._signed), _signGrade(f._signGrade), _exGrade(f._exGrade)
{
	std::cout << "AForm copy constructor" << std::endl;
}

AForm &AForm::operator=(const AForm &f)
{
	std::cout << "AForm copy assignment operator" << std::endl;
	if (this != &f)
		this->_signed = f._signed;
	return (*this);
}

AForm::~AForm()
{
	std::cout << "AForm " << this->getName() << " destructor" << std::endl;
}

AForm::AForm(std::string name, int signGrade, int exGrade): _name(name), _signed(false), _signGrade(signGrade), _exGrade(exGrade)
{
	if (signGrade < 1 || exGrade < 1)
		throw AForm::GradeTooHighException();
	else if (signGrade > 150 || exGrade > 150)
		throw AForm::GradeTooLowException();
	std::cout << "AForm " << this->_name << " constructor" << std::endl;
}

const std::string AForm::getName() const
{
	return (this->_name);
}

bool AForm::getSigned() const
{
	return (this->_signed);
}

int AForm::getSignGrade() const
{
	return (this->_signGrade);
}

int AForm::getExGrade() const
{
	return (this->_exGrade);
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= this->_signGrade)
		this->_signed = true;
	else if (b.getGrade() < 1)
		throw AForm::GradeTooHighException();
	else
		throw AForm::GradeTooLowException();
}

void AForm::setSigned(const bool result)
{
	this->_signed = result;
}

int	AForm::formRights(const Bureaucrat &b) const
{
	if (this->_signed == false)
		throw AForm::FormNotSigned();
	else if (this->_exGrade < b.getGrade())
		throw AForm::GradeTooLowException();

	this->execute(b);
	return (0);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Exception, grade is out of bounds (too high)");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Exception, grade is out of bounds (too low)");
}

const char *AForm::FormNotSigned::what() const throw()
{
	return ("Exception, form not signed");
}

std::ostream &operator<<(std::ostream &s, AForm &f)
{
	s << "AForm " << f.getName() << ". Signed: " << f.getSigned() << ", Sign grade: " << f.getSignGrade() << ", Exec grade: " << f.getExGrade();
	return (s);
}

