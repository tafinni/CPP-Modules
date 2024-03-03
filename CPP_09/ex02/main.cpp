#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac < 2)
            throw WrongArgs();
        
        PmergeMe pm;
        pm.sort(ac, av);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}

const char *InvalidValue::what() const throw()
{
	return "Invalid value";
}

const char* WrongArgs::what() const throw()
{
    return "Wrong amount of arguments";
}