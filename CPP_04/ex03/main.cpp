/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:33:30 by tfinni            #+#    #+#             */
/*   Updated: 2023/11/18 13:08:28 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << std::endl;
	delete bob;
	delete me;
	delete src;

	std::cout << "\n - - - 1 - - - \n" << std::endl;

	std::cout << "Creating MateriaSource for storing possible materias" << std::endl;
	MateriaSource source;
	std::cout << "Adding new materias to the sources" << std::endl;
	source.learnMateria(new Ice());
	source.learnMateria(new Cure());
	
	std::cout << "Creates character Bob" << std::endl;
	Character Bob("Bob");
	std::cout << "Materia is cloned from the source to Bob" << std::endl;
	Bob.equip(source.createMateria("ice"));

	std::cout << "Character Foo is created and Bob uses his materia slot 0" << std::endl;
	Character Foo("Foo");
	Bob.use(0, Foo);


	std::cout << "\n - - - 2 - - - \n" << std::endl;

	std::cout << "Filling Bob's materia inventory" << std::endl;
	Bob.equip(source.createMateria("ice"));
	Bob.equip(source.createMateria("ice"));
	Bob.equip(source.createMateria("ice"));

	std::cout << "Bob's inventory should be full, adding another materia Cure to make sure it won't be saved" << std::endl;
	Bob.equip(source.createMateria("cure"));
	std::cout << "Using Bob's whole inventory and one more to check inventory size" << std::endl;
	Bob.use(0, Foo);
	Bob.use(1, Foo);
	Bob.use(2, Foo);
	Bob.use(3, Foo);
	Bob.use(4, Foo);

	std::cout << "\nUnequip Bob's slot 0 from ice and add cure" << std::endl;
	AMateria *dropped;
	dropped = Bob.getDrop(0);
	Bob.unequip(0);
	delete dropped;
	Bob.equip(source.createMateria("cure"));
	std::cout << "Using cure" << std::endl;
	Bob.use(0, Foo);
	
	std::cout << "\nCreating clone of Bob and using materia slot 0" << std::endl;
	Character BobClone(Bob);
	Bob.use(0, Foo);
	std::cout << "Original Bob changes slot 0 from Cure to Ice, printing Bob and BobClone to make sure BobClone still has Cure" << std::endl;
	dropped = Bob.getDrop(0);
	Bob.unequip(0);
	delete dropped;
	Bob.equip(source.createMateria("ice"));
	Bob.use(0, Foo);
	BobClone.use(0, Foo);
	

	std::cout << "\nUsing non existing and NULL inventory slot" << std::endl;
	dropped = Bob.getDrop(3);
	Bob.unequip(3);
	delete dropped;
	Bob.use(10, Foo);
	Bob.use(3, Foo);

	return 0;
}