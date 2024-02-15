#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
	std::cout << "Empty array" << std::endl;
    Array<int> emptyArray;
    try
    {
        std::cout << "Size: " << emptyArray.size() << std::endl;
        std::cout << "Trying to print from empty array: " << std::endl << emptyArray[0] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;

	std::cout << "Int array" << std::endl;
	Array<int> intArray(10);
    for (int i = 0; i < 10; i++)
		intArray[i] = i;
	std::cout << "Size: " << intArray.size() << std::endl;
    for (int i = 0; i < 10; i++)
        std::cout << intArray[i] << "  ";
    std::cout << std::endl << std::endl;

	std::cout << "Double array" << std::endl;
	Array<double> doubleArray(10);
    for (int i = 0; i < 10; i++)
		doubleArray[i] = i + 0.5;
	std::cout << "Size: " << doubleArray.size() << std::endl;
    for (int i = 0; i < 10; i++)
        std::cout << doubleArray[i] << "  ";
    std::cout << std::endl << std::endl;

    std::cout << "Testing copy constructor" << std::endl;
    Array<int> intArray2(intArray);
    std::cout << "First array" << std::endl;
    std::cout << "Size: " << intArray.size() << std::endl;
    for (int i = 0; i < 10; i++)
        std::cout << intArray[i] << "  ";
    std::cout << std::endl << "Second array" << std::endl;
    std::cout << "Size: " << intArray2.size() << std::endl;
    for (int i = 0; i < 10; i++)
        std::cout << intArray2[i] << "  ";
    std::cout << std::endl << std::endl;

    std::cout << "Testing copy assignment operator" << std::endl;
    Array<double> doubleArray2(5);
    for (int i = 0; i < 5; i++)
        doubleArray2[i] = i + 15.5;
    std::cout << "Original size and values: " << doubleArray2.size() << std::endl;
    for (int i = 0; i < 5; i++)
        std::cout << doubleArray2[i] << "  ";
    std::cout << std::endl;
    doubleArray2 = doubleArray;
    std::cout << "New size and values: " << doubleArray2.size() << std::endl;
    for (int i = 0; i < doubleArray2.size(); i++)
        std::cout << doubleArray2[i] << "  ";
    std::cout << std::endl << std::endl;



    std::cout << std::endl << "Tests given in subject: " << std::endl;

    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;

    return 0;
}