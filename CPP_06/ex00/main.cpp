#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	std::cout << std::fixed << std::setprecision(1);
	if (argc == 2)
		ScalaConverter::convert(argv[1]);	
	return (0);
}