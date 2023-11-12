/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:42:07 by tfinni            #+#    #+#             */
/*   Updated: 2023/11/07 16:02:59 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main()
{
	ClapTrap Bob("Bob");
	ClapTrap Clone(Bob);
	ClapTrap Foo("Foo");

	std::cout << Bob << std::endl;
	std::cout << Clone << std::endl;
	std::cout << Foo << std::endl;

	Bob.attack("Foo");
	std::cout << Bob << std::endl;
	Foo.takeDamage(Bob.getAttackDamage());
	Foo.beRepaired(3);
	std::cout << Foo << std::endl;

	/* - ex01 - */
	std::cout << "\n\n/ / / / / /  EX01  / / / / / / " << std::endl;
	ScavTrap Scav("Scav");
	ScavTrap ScavClone(Scav);

	std::cout << Scav << std::endl;
	std::cout << ScavClone << std::endl;

	Scav.attack("Bob");
	Bob.takeDamage(Scav.getAttackDamage());
	std::cout << Bob << std::endl;

	Foo.attack("Scav");
	Scav.takeDamage(Foo.getAttackDamage());
	Scav.beRepaired(3);
	std::cout << Scav << std::endl;

	Scav.guardGate(); 
	std::cout<<std::endl;
	
	return (0);
}
