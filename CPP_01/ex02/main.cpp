/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:06:39 by tfinni            #+#    #+#             */
/*   Updated: 2023/10/31 14:06:40 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "string address:		" << &str << std::endl;
	std::cout << "stringPTR address:	" << stringPTR << std::endl;
	std::cout << "stingREF address:	" << &stringREF << std::endl;

	std::cout << "\nstring:		" << str << std::endl;
	std::cout << "stringPTR:	" << *stringPTR << std::endl;
	std::cout << "stringREF:	" << stringREF << std::endl;

	return (0);
}