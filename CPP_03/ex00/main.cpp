/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:43:48 by tfinni            #+#    #+#             */
/*   Updated: 2023/11/07 14:43:50 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap Bob("Bob");
	ClapTrap Clone(Bob);
	ClapTrap Foo("Foo");

	std::cout << Bob << std::endl;
	std::cout << Clone << std::endl;
	std::cout << Foo << std::endl;

	Bob.attack("Foo");
	Foo.takeDamage(Bob.getAttackDamage());
	std::cout << Foo << std::endl;
	Foo.beRepaired(3);
	std::cout << Foo << std::endl;

	
	return (0);
}
