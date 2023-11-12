/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:07:01 by tfinni            #+#    #+#             */
/*   Updated: 2023/10/31 14:48:17 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <cstring>

int	replacer(char **argv)
{
	std::ifstream inFile(argv[1], std::ios::in);
	if (!inFile.is_open())
	{
		std::cout << "Error opening inFile" << std::endl;
		return (1);
	}

	std::string name = argv[1] + (std::string)".replace";
	std::ofstream outFile(name.c_str(), std::ios::out);
	if (!outFile.is_open())
	{
		std::cout << "Error opening outFile" << std::endl;
		return (1);
	}

	std::string	read_result;		
	std::getline(inFile, read_result, '\0');
	size_t	start = read_result.find(argv[2]);
	while (start != std::string::npos)
	{
		read_result.erase(start, std::strlen(argv[2]));
		read_result.insert(start, argv[3]);
		start = read_result.find(argv[2]);
	}
	outFile << read_result;
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Usage: ./replacer [file] [str to replace] [str to replace with]" << std::endl;
		return (1);
	}
	if (replacer(argv) == 1)
		return (1);
	return (0);
}