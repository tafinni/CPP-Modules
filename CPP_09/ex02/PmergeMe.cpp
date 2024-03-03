#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe & other): _vector(other._vector), _deque(other._deque) {}

PmergeMe & PmergeMe::operator=(const PmergeMe & other) 
{
    if (this != &other)
    {
        _vector = other._vector;
        _deque = other._deque;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::sort(const int ac, char **av)
{
    // vector
    clock_t startVec = clock();
    initContainer(_vector, ac, av);

    std::cout << "Before: " << std::endl;
    for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl << std::endl;

    mergeInsert(_vector);
    clock_t endVec = clock();


    // deque
    clock_t startDeq = clock();
    initContainer(_deque, ac, av);

    for (std::deque<int>::iterator it = _deque.begin(); it != _deque.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl << std::endl;

    mergeInsert(_deque);
    clock_t endDeq = clock();


    // print result
    std::cout << "After: " << std::endl;
    for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl << std::endl;

    for (std::deque<int>::iterator it = _deque.begin(); it != _deque.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl << std::endl;

    std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << std::setprecision(5) << (endVec - startVec) / static_cast<double>(CLOCKS_PER_SEC) << " seconds" <<  std::endl;
    std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque : " << std::setprecision(5) << (endDeq - startDeq) / static_cast<double>(CLOCKS_PER_SEC) << " seconds" << std::endl;

}

