#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <iomanip>

# include "mergeInsert.hpp"

class PmergeMe
{
    public:
        std::vector<int> _vector;
        std::deque<int>  _deque;

        PmergeMe();
        PmergeMe(const PmergeMe & other);
        PmergeMe & operator=(const PmergeMe & other);
        ~PmergeMe();

        void sort(const int ac, char **av);
};

#endif
