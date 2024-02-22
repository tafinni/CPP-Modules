#include "easyfind.hpp"
#include <array>
#include <vector>

int main()
{
    std::array<int,10> container = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << "--- Array container ---" << std::endl;
    std::cout << "- Trying to find value that's not in the container -" << std::endl;
    try
    {
        std::cout << easyFind(container, 12) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: Value not found" << std::endl;
    }

    std::cout << std::endl << "- Finding valid value -" << std::endl;
    try
    {
        easyFind(container, 8);
        std::cout << "Value found" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: Value not found" << std::endl;
    }

    std::cout << std::endl << std::endl << "--- Vector container ---" << std::endl;
    std::vector<int> container2;
    for (int i = 0; i < 10; i++)
        container2.push_back(i);

    std::cout << "- Trying to find value that's not in the container -" << std::endl;
    try
    {
        easyFind(container2, 12);
        std::cout << "Value found" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: Value not found" << std::endl;
    }

    std::cout << std::endl << "- Finding valid value -" << std::endl;
    try
    {
        easyFind(container2, 8);
        std::cout << "Value found" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: Value not found" << std::endl;
    }

    return 0;
}
