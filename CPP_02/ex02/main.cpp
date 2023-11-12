/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:25:43 by tfinni            #+#    #+#             */
/*   Updated: 2023/11/05 15:25:44 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "\nown tests:" << std::endl;
	Fixed c(1);
	Fixed d(2);
	std::cout << "c " << c << ", d " << d << std::endl;

	std::cout << "\nMin: " << Fixed::min(c, d) << std::endl;
	std::cout << "Max: " << Fixed::max(c, d) << std::endl;

	std::cout << "\nbefore ++c " << c << ", ++c " << ++c << "\nc++ " << c++ << ", after c++ " << c << std::endl;
	std::cout << "\nbefore --c " << c << ", --c " << --c << "\nc-- " << c-- << ", after c-- " << c << std::endl;
	
	{
 	std::cout <<std::endl;
    std::cout<< "\033[1m\033[35m An additional test \033[0m" <<std::endl;
    Fixed a(8.5f);
    Fixed b(4.5f);

    std::cout<< "\033[35ma = " << a<< "\033[0m" <<std::endl;

    std::cout<< "\033[35mb = "<< b << "\033[0m"<<std::endl<<std::endl;

    std::cout<< "a > b: " << (a > b) <<std::endl;
    std::cout<< "a < b: " << (a < b) <<std::endl;
    std::cout<< "a >= b: " << (a >= b) <<std::endl;
    std::cout<< "a <= b: " << (a <= b) <<std::endl;
    std::cout<< "a == b: " << (a == b) <<std::endl;
    std::cout<< "a != b: " << (a != b) <<std::endl<<std::endl;

    std::cout<< "a + b: "<< (a + b) <<std::endl;
    std::cout<< "a - b: "<< (a - b) <<std::endl;
    std::cout<< "a / b: "<< (a / b) <<std::endl;
    std::cout<< "a * b: "<< (a * b) <<std::endl<<std::endl;

    std::cout<< "a++:" <<std::endl;
    std::cout<< (a++) <<std::endl;
    std::cout<< "a after ++:" <<std::endl;
    std::cout<< (a) <<std::endl<<std::endl;

    std::cout<< "++a:" <<std::endl;
    std::cout<< (++a) <<std::endl<<std::endl;

    std::cout<< "a--:" <<std::endl;
    std::cout<< (a--) <<std::endl;
    std::cout<< "a after --:" <<std::endl;
    std::cout<< (a) <<std::endl<<std::endl;

    std::cout<< "--a:" <<std::endl;
    std::cout<< (--a) <<std::endl<<std::endl;

    std::cout<< "find min: "<< a.min(a, b) <<std::endl;
    std::cout<< "find max: " << b.max(a, b) <<std::endl;
	}

	return 0;
}
