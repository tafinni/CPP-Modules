#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>

template<typename T>
typename T::iterator easyFind(T type, int value)
{
    typename T::iterator check = std::find(type.begin(), type.end(), value);
    if (check == std::end(type))
        throw std::exception();
    return (check);
}

#endif