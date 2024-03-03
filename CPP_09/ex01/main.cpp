#include "RPN.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac != 2)
         throw RPN::WrongArgs();
        
        RPN rpn;
        rpn.calculate(av[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}