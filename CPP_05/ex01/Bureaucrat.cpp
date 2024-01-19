#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &b): _name(b._name), _grade(b._grade) {
	std::cout << "Bureaucrat " << this->_name << " copy constructor" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &b)
{
	std::cout << "Bureaucrat " << this->_name << " copy assignment operator" << std::endl;
	if (this != &b)
		this->_grade = b._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << this->_name << " destructor" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = grade;
	std::cout << "Bureaucrat " << this->_name << " constructor" << std::endl;
}

std::string Bureaucrat::getName()
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::increment()
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade += 1;
}

void	Bureaucrat::decrement()
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade -= 1;
}

void	Bureaucrat::signForm(Form &f)
{
	if (f.getSigned() == false)
	{
		f.beSigned(*this);
		std::cout << "Bureaucrat " << this->_name << " signed form " << f.getName() << std::endl;
	}
	else if (f.getSigned() == true && this->_grade > f.getSignGrade())
		std::cout << "Bureaucrat " << this->_name << " couldn't sign form " << f.getName() << " because it is already signed and Bureaucrat's grade is too low" << std::endl;
	else if (f.getSigned() == true)
		std::cout << "Bureaucrat " << this->_name << " couldn't sign form " << f.getName() << " because it is already signed" << std::endl;
	
	//do grade check to form.cpp
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat exception, grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat exception, grade too low");
}

std::ostream &operator<<(std::ostream &stream, Bureaucrat &b)
{
	stream << "Bureaucrat " << b.getName() << ", grade: " << b.getGrade();
	return (stream);
}



