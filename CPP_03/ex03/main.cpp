/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:45:13 by tfinni            #+#    #+#             */
/*   Updated: 2023/11/07 16:03:56 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

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

	/* - ex03 - */
	std::cout << "\n\n/ / / / / /  EX03  / / / / / / " << std::endl;
	DiamondTrap Diamond("Diamond");
	DiamondTrap DiamondClone(Diamond);
	std::cout << std::endl;

	std::cout << Diamond << std::endl;
	Diamond.whoAmI();
	std::cout << DiamondClone << std::endl;
	DiamondClone.whoAmI();
	std::cout << std::endl;

	Diamond.attack("DiamondClone");
	DiamondClone.takeDamage(Diamond.getAttackDamage());
	Diamond.beRepaired(3);
	std::cout << Diamond << std::endl;
	std::cout << DiamondClone << "\n" << std::endl;
	

	Diamond.whoAmI();
	std::cout << std::endl;

	Diamond.highFivesGuys();
	Diamond.guardGate();

	std::cout << std::endl;
	return (0);
}
