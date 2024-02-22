#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	std::cout << "--- Test given in subject ---" << std::endl;
	MutantStack<int> mstack;
	mstack.push(1);
	mstack.push(2);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(4);
	mstack.push(0);
	//[...]
	mstack.push(6);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << std::endl << std::endl;

	std::cout << "* Same test but with std::list" << std::endl;
	std::list<int> test;
	test.push_front(8);
	test.push_front(2);

	std::cout << test.front() << std::endl;
	test.pop_front();
	std::cout << test.size() << std::endl;
	test.push_back(3);
	test.push_back(4);
	test.push_back(0);
	//[...]
	test.push_back(6);
	std::list<int>::iterator it2 = test.begin();
	std::list<int>::iterator ite2 = test.end();
	++it2;
	--it2;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
	std::list<int> t(test);
	

	std::cout << std::endl << "--- Testing copy constructor ---" << std::endl;
	MutantStack<int> copy(mstack);
	MutantStack<int>::iterator it3 = copy.begin();
	MutantStack<int>::iterator ite3 = copy.end();
	while (it3 != ite3)
	{
		std::cout << *it3 << std::endl;
		++it3;
	}

	return 0;
}