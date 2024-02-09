#include "Serializer.hpp"

int main()
{
    Data *test = new Data;

    test->str = "test_str";
    test->i = 10;
    std::cout << "original str: " << test->str << std::endl;
    std::cout << "original int: " << test->i << std::endl << std::endl;

    uintptr_t ptr = Serializer::serialize(test);

    Data *result = Serializer::deserialize(ptr);

    std::cout << "result str: " << result->str << std::endl;
    std::cout << "result int: " << result->i << std::endl;

    delete test;
    return 0;
}