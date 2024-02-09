#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>

#include <chrono>

Base *generate()
{
    std::srand(std::chrono::high_resolution_clock::now().time_since_epoch().count());
	int value = std::rand();

	if (value % 3 == 0)
		return (new A);
	else if (value % 2 == 0)
		return (new B);
	else
		return (new C);

}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p) != nullptr)
		std::cout << "* A" << std::endl;

	if (dynamic_cast<B*>(p) != nullptr)
		std::cout << "* B" << std::endl;

	if (dynamic_cast<C*>(p) != nullptr)
		std::cout << "* C" << std::endl;
}

void identify(Base &p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "& A" << std::endl;
	}
	catch (std::bad_cast &e) { }

	try
	{
		dynamic_cast<B&>(p);
		std::cout << "& B" << std::endl;
	}
	catch (std::bad_cast &e) { }

	try
	{
		dynamic_cast<C&>(p);
		std::cout << "& C" << std::endl;
	}
	catch (std::bad_cast &e) { } 
}

int main()
{
	std::cout << "--- test1 ---" << std::endl;
	Base *test1;
	test1 = generate();
	identify(test1);
	identify(*test1);
	std::cout << std::endl;

	std::cout << "--- test2 ---" << std::endl;
	Base *test2;
	test2 = generate();
	identify(test2);
	identify(*test2);
	std::cout << std::endl;
	
	std::cout << "--- test3 ---" << std::endl;
	Base *test3;
	test3 = generate();
	identify(test3);
	identify(*test3);
	std::cout << std::endl;

	std::cout << "--- test4 ---" << std::endl;
	Base *test4;
	test4 = generate();
	identify(test4);
	identify(*test4);
	std::cout << std::endl;

	std::cout << "--- test5 ---" << std::endl;
	Base *test5;
	test5 = generate();
	identify(test5);
	identify(*test5);

	delete test1;
	delete test2;
	delete test3;
	delete test4;
	delete test5;

	return 0;
}