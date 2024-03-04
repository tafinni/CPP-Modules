/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:28:55 by tfinni            #+#    #+#             */
/*   Updated: 2024/03/04 13:11:48 by tfinni           ###   ########.fr       */
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
	if (bit.readInput(argv[1]) == false)
		return 1;
	return 0;
}