#include "Form.hpp"

Form::Form(): _signGrade(1), _exGrade(1)
{
	std::cout << "Form default constructor" << std::endl;
}

Form::Form(const Form &f): _name(f._name), _signed(f._signed), _signGrade(f._signGrade), _exGrade(f._exGrade)
{
	std::cout << "Form copy constructor" << std::endl;
}

Form &Form::operator=(const Form &f)
{
	std::cout << "Form copy assignment operator" << std::endl;
	if (this != &f)
		this->_signed = f._signed;
	return (*this);
}

Form::~Form()
{
	std::cout << "Form " << this->getName() << " destructor" << std::endl;
}

Form::Form(std::string name, int signGrade, int exGrade): _name(name), _signed(false), _signGrade(signGrade), _exGrade(exGrade)
{
	if (signGrade < 1 || exGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150 || exGrade > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form " << this->_name << " constructor" << std::endl;
}

const std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getSigned() const
{
	return (this->_signed);
}

int Form::getSignGrade() const
{
	return (this->_signGrade);
}

int Form::getExGrade() const
{
	return (this->_exGrade);
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= this->_signGrade)
		this->_signed = true;
	else if (b.getGrade() < 1)
		throw Form::GradeTooHighException();
	else
		throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Form exception, grade is out of bounds (too high)");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Form exception, grade is out of bounds (too low)");
}

std::ostream &operator<<(std::ostream &s, Form &f)
{
	s << "Form " << f.getName() << ". Signed: " << f.getSigned() << ", Sign grade: " << f.getSignGrade() << ", Exec grade: " << f.getExGrade();
	return (s);
}

