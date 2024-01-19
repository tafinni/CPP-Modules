#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137), _target(NULL) {
	std::cout << "Shrubbery default constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &s) : AForm(s)
{
	std::cout << "Shrubbery copy constructor" << std::endl;
	*this = s;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &s)
{
	if (this != &s)
	{
		this->_target = s._target;
		this->setSigned(s.getSigned());
		std::cout << "Shrubbery copy assignment operator" << std::endl;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "Shrubbery destructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("Shrubbery", 145, 137), _target(target) {
	std::cout << "Shrubbery constructor" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
		throw AForm::FormNotSigned();
	else if (this->getExGrade() < executor.getGrade())
		throw AForm::GradeTooLowException();

	std::ofstream file((this->_target + std::string("_shrubbery")).c_str());

	if (!file)
		throw ShrubberyCreationForm::NoOpenFile();
	else
	{
		file << "        //\\" << std::endl;
		file << "       //  \\" << std::endl;
		file << "      //    \\" << std::endl;
		file << "     //      \\" << std::endl;
		file << "    //        \\" << std::endl;
		file << "   //          \\" << std::endl;
		file << "  //            \\" << std::endl;
		file << " //______________\\" << std::endl;
		file << "       ||||" << std::endl;
		file << "       ||||" << std::endl;
		file << "       ||||" << std::endl << std::endl;
		file << "        //\\" << std::endl;
		file << "       //, \\" << std::endl;
		file << "      //  , \\" << std::endl;
		file << "     //,     \\" << std::endl;
		file << "    //   ,    \\" << std::endl;
		file << "   //        , \\" << std::endl;
		file << "  //  ,    ,    \\" << std::endl;
		file << " //______________\\" << std::endl;
		file << "       ||||" << std::endl;
		file << "       ||||" << std::endl;
		file << "       ||||" << std::endl;
		file.close();
	}

}

const char *ShrubberyCreationForm::NoOpenFile::what() const throw()
{
	return ("Exception, failed to oepn shrubbery file");
}

