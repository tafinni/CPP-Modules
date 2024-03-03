/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:28:55 by tfinni            #+#    #+#             */
/*   Updated: 2024/02/28 17:53:13 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	BitcoinExchange bit;
	try
	{
		if (argc != 2)
			throw BitcoinExchange::NoFileOpen();

		if (bit.readData() == false)
		{
			std::cerr << "Error is in data file" << std::endl;
			return 1;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	bit.readInput(argv[1]);
	return 0;
}