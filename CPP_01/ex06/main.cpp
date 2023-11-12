/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:07:18 by tfinni            #+#    #+#             */
/*   Updated: 2023/10/31 14:07:19 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl	harl;

	std::cout << "\n--- DEBUG ---" << std::endl;
	harl.complain("DEBUG");

	std::cout << "\n--- INFO ---" << std::endl;
	harl.complain("INFO");

	std::cout << "\n--- WARNING ---" << std::endl;
	harl.complain("WARNING");

	std::cout << "\n--- ERROR ---" << std::endl;
	harl.complain("ERROR");

	std::cout << "\n--- test ---" << std::endl;
	harl.complain("test");

	std::cout << "\n--- empty ---" << std::endl;
	harl.complain("");
	
	return (0);
}
