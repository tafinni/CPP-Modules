#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T>
void iter(T* address, int lenght, void (*function)(T const &))
{
	for (int i = 0; i < lenght; i++)
		function(address[i]);
	
}

#endif