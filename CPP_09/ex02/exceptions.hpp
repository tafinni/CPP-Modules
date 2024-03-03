#ifndef EXCEPTIONS_HPP
# define EXCEPTIONS_HPP

# include <exception>

class InvalidValue: public std::exception
{
	public:
		const char* what() const throw();
};

class WrongArgs: public std::exception
{
	public:
		const char* what() const throw();
};

#endif