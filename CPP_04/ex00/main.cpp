/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:31:49 by tfinni            #+#    #+#             */
/*   Updated: 2023/11/18 12:31:50 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "\n" << j->getType() << " " << std::endl;
	std::cout << i->getType() << "\n" << std::endl;

	std::cout << "Cat sound: ";
	i->makeSound(); //will output the cat sound!
	std::cout << "Dog sound: ";
	j->makeSound();
	std::cout << "Animal sound: ";
	meta->makeSound();
	std::cout << std::endl;

	delete meta;
	delete j;
	delete i;

	std::cout << "\n--- testing with wrongs ---" << std::endl;

	const WrongAnimal* animal = new WrongAnimal();
	const WrongAnimal* cat = new WrongCat();
	const Cat anotherCat;

	std::cout << "\n" << cat->getType() << "\n" << std::endl;

	std::cout << "Cat sound WrongAnimal base: ";
	cat->makeSound(); //will output the WrongAnimal sound!
	std::cout << "Cat sound Cat base: ";
	anotherCat.makeSound(); //will output the cat sound!
	std::cout << "Animal sound: ";
	animal->makeSound();
	std::cout << std::endl;

	delete animal;
	delete cat;

	return 0;
}