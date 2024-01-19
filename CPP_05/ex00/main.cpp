#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat First("Bob", 3);
	std::cout << First << " - start grade" << std::endl;
	First.decrement();
	std::cout << First << " - decremented grade" << std::endl;
	First.increment();
	std::cout << First << " - incremented grade\n" << std::endl;
	First.increment();
	First.increment();
	try {
	First.increment();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	try {
	Bureaucrat Second("Low", 151);
	std::cout << Second;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	Bureaucrat Third("Test", 10);
	std::cout << Third << std::endl;
	Bureaucrat Fourth(Third);
	std::cout << Fourth << std::endl << std::endl;

	Bureaucrat Fifth("Name", 5);
	std::cout << Fifth << std::endl;
	Fifth = Fourth;
	std::cout << Fifth << std::endl << std::endl;

	return (0);
}