#include "iter.hpp"

void printNumber(int i)
{
	std::cout << "number: " << i << std::endl;
}

int main()
{
	int array1[] = {0, 1, 2, 3, 4};

	iter(array1, std::size(array1), printAddress <int>);

	iter(array1, std::size(array1), printNumber);

	return (0);
}