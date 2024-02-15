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

		int size();

		class OutOFBounds: public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Value out of bounds";
				}
		};

};

# include "Array.tpp"

#endif