#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	std::cout << "--- Test given in subject ---" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "Values in container:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << std::endl << std::endl;


	std::cout << "--- Same test but with std::list ---" << std::endl;
	std::list<int> test;
	test.push_front(5);
	test.push_front(17);

	std::cout << test.front() << std::endl;
	test.pop_front();
	std::cout << test.size() << std::endl;
	test.push_back(3);
	test.push_back(5);
	test.push_back(737);
	//[...]
	test.push_back(0);
	std::list<int>::iterator it2 = test.begin();
	std::list<int>::iterator ite2 = test.end();
	++it2;
	--it2;
	std::cout << "Values in container:" << std::endl;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}	


	std::cout << std::endl << "--- Testing copy constructor (values should match to previous examples)---" << std::endl;
	MutantStack<int> copy(mstack);
	MutantStack<int>::iterator it3 = copy.begin();
	MutantStack<int>::iterator ite3 = copy.end();
	while (it3 != ite3)
	{
		std::cout << *it3 << std::endl;
		++it3;
	}


	std::cout << std::endl << "--- Testing copy assignment operator (values should match to previous examples)---" << std::endl;
	MutantStack<int> copy2;
	copy2 = copy;
	MutantStack<int>::iterator it4 = copy2.begin();
	MutantStack<int>::iterator ite4 = copy2.end();
	while (it4 != ite4)
	{
		std::cout << *it4 << std::endl;
		++it4;
	}

	std::cout << std::endl << "--- Testing that other std::stack functions work ---" << std::endl;
	MutantStack<int> test2;

	std::cout << "Testing empty with .empty(): " << test2.empty() << std::endl;
	test2.push(100);
	std::cout << "Testing not empty with .empty(): " << test2.empty() << std::endl << std::endl;

	std::cout << "--- Testing .swap() and swapping copy2 and test2 \ncopy2: ---" << std::endl;
	test2.swap(copy2);
	it4 = copy2.begin();
	ite4 = copy2.end();
	while (it4 != ite4)
	{
		std::cout << *it4 << std::endl;
		++it4;
	}
	std::cout << "test2:" << std::endl;
	it4 = test2.begin();
	ite4 = test2.end();
	while (it4 != ite4)
	{
		std::cout << *it4 << std::endl;
		++it4;
	}

	return 0;
}