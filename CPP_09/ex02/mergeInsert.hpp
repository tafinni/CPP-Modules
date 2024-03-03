#ifndef MERGEINSERT_HPP
# define MERGEINSERT_HPP

# include <algorithm>
# include <limits>
# include "exceptions.hpp"

template <typename T>
void initContainer(T& container, const int ac, char **av)
{
    for (int i = 1; i < ac; i++)
    {
        for (char *c = av[i]; *c != '\0'; c++)
        {
            if (std::isdigit(*c) == false && *c != '+')
                throw InvalidValue();
        }
        int res = std::atoi(av[i]);
        if (res > std::numeric_limits<typename T::value_type>::max() || res < 0)
            throw InvalidValue();
        container.push_back(res);
    }
}

template <typename T>
void sortContainer(T& container)
{
    typename T::iterator begin = container.begin(), middle = container.begin(), end = container.end();
    std::advance(middle, container.size() / 2);

    T first, second;
    first.assign(begin, middle);
    second.assign(middle, end);

    if (first.size() > 2)
        sortContainer(first);
    else if (first.size() > 1 && first[0] > first[1])
            std::swap(first[0], first[1]);

    if (second.size() > 2)
        sortContainer(second);
    else if (second.size() > 1 && second[0] > second[1])
        std::swap(second[0], second[1]);

    std::merge(first.begin(), first.end(), second.begin(), second.end(), container.begin());

}

template <typename T>
void mergeInsert(T& container)
{
	int odd = -1;

    if (container.size() % 2 != 0)
    {
        odd = container.back();
        container.pop_back();
    }

    sortContainer(container);    

    if (odd != -1)
    {
        typename T::iterator it = std::lower_bound(container.begin(), container.end(), odd);
        container.insert(it, odd);
    }
}

#endif
