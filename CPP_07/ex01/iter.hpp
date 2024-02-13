#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T>
void printAddress(T& address)
{
	std::cout << "address: " << std::addressof(address) << std::endl;
}

template<typename T, typename L, typename U>
void iter(T* address, L lenght, U function)
{
	for (size_t i = 0; i < lenght; i++)
		function(address[i]);
	
}

#endif