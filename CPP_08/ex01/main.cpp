#include "Span.hpp"

int main()
{
	std::cout << "--- Test given in subject ---" << std::endl;
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl << std::endl;


	std::cout << "--- Other tests ---" << std::endl;
	Span sp2 = Span(10);
	std::cout << "* Adding too many values with addMany" << std::endl;
	try
	{
		sp2.addMany(11);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "* Adding too many values with addNumber" << std::endl;
	try
	{
		sp2.addNumber(11);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << sp2 << std::endl;

	std::cout << std::endl << "* Adding many values with addMany" << std::endl;
	Span sp3 = Span(10);
	sp3.addMany(7);
	sp3.addMany(3);
	std::cout << sp3 << std::endl;
	std::cout << sp3.shortestSpan() << std::endl;
	std::cout << sp3.longestSpan() << std::endl << std::endl;

	std::cout << std::endl << "--- Testing not enough values ---" << std::endl;
	Span sp5 = Span(2);
	sp5.addMany(1);
	std::cout << "* Testing with shortestSpan" << std::endl;
	try
	{
		std::cout << sp5.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "* Testing with longestSpan" << std::endl;
	try
	{
		std::cout << sp5.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}


	std::cout << std::endl << "--- Testing copy constructor ---" << std::endl;
	Span sp4 = Span(sp3);
	std::cout << sp3 << std::endl;
	std::cout << sp4 << std::endl;

	std::cout << std::endl << "--- Testing copy assignment operator ---" << std::endl;
	sp4 = sp;
	std::cout << sp << std::endl;
	std::cout << sp4 << std::endl << std::endl;




	return 0;
}