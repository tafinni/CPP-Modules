#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <exception>
# include <algorithm>
# include <cstdlib>
# include <ctime>
# include <chrono>

class Span
{
	private:
		unsigned int _n;
		std::vector<int> _container;

	public:

		Span();
		Span(const Span &s);
		Span &operator=(const Span &s);
		~Span();

		Span(unsigned int n);

		void	addNumber(int value);
		void	addMany(int count);
		int		shortestSpan();
		int		longestSpan();	

		std::vector<int>* getContainer();

	class ContainerFull: public std::exception
	{
		public:
			const char *what() const throw();
	};

	class NotEnoughValues: public std::exception
	{
		public:
			const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, Span &sp);

#endif