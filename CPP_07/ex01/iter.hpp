#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T>
void printAddress(T& address)
{
	std::cout << "address: " << std::addressof(address) << std::endl;
}

template<typename addressType, typename lenghtType, typename functionType>
void iter(addressType* address, lenghtType lenght, functionType function)
{
	for (size_t i = 0; i < lenght; i++)
		function(address[i]);
	
}

#endif