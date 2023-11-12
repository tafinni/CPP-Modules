/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:44:27 by tfinni            #+#    #+#             */
/*   Updated: 2023/11/07 16:03:46 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

	/* - ex02 - */
	std::cout << "\n\n/ / / / / /  EX02  / / / / / / " << std::endl;
	FragTrap Frag("Frag");
	FragTrap FragClone(Frag);

	std::cout << Frag << std::endl;
	std::cout << FragClone << std::endl;

	Frag.attack("Scav");
	Scav.takeDamage(Frag.getAttackDamage());
	std::cout << Frag << std::endl;
	std::cout << Scav << std::endl;

	Frag.highFivesGuys();
	std::cout << std::endl;
	
	return (0);
}
