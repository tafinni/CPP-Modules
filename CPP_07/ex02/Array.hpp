#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template <typename T>
class Array
{
	private:
		T	*_array;
		int	_arrlen;

	public:
		Array();
		Array(const Array &a);
		Array &operator=(const Array &a);
		~Array();

		Array(unsigned int n);

		T &operator[](const int value);

		int size() const;

		class OutOfBounds: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

};

# include "Array.tpp"

#endif