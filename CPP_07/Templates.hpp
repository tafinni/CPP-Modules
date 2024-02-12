#ifndef TEMPLATES_HPP
# define TEMPLATES_HPP

template <typename T> T max(T x, T y)
{
    return (x > y) ? x : y;
}

template <typename T> T min(T x, T y)
{
    return (x < y) ? x : y;
}

template <typename T> T swap(T x, T y)
{
    T temp = x;
    x = y;
    y = temp;
    return (0);
}

#endif