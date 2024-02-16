#include "iter.hpp"

template<typename T>
void printAddress(T& address)
{
	std::cout << "address: " << std::addressof(address) << std::endl;
}

void printNumber(const int& i)
{
	std::cout << "number: " << i << std::endl;
}

void printStr(const std::string& array)
{
	std::cout << "array: " << array << std::endl;
}

int main()
{

	int array1[] = {0, 1, 2, 3, 4};

	std::string array2[] = {"ABC", "DEF", "GHI", "JKL", "MNO"};

	std::cout << "- Testing with template -" << std::endl;
	iter(array1, 5, printAddress);

	std::cout << std::endl << "- Testing with int array -" << std::endl;
	iter(array1, 5, printNumber);

	std::cout << std::endl << "- Testing with std::string array -" << std::endl;
	iter(array2, 5, printStr);

	return (0);
}
