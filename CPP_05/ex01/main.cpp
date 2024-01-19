#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
		Bureaucrat	First("First", 20);
		Form		High("High-form", 5, 2);
		Form		Ok("Ok-form", 30, 25);

		std::cout << std::endl;
		First.signForm(Ok);
		try {
			First.signForm(High);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl; 
		}

		std::cout << std::endl << High << std::endl;
		std::cout << Ok << std::endl;
		High = Ok;
		std::cout << High << std::endl;
		std::cout << std::endl;

	return (0);
}