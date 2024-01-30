/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:32:52 by tfinni            #+#    #+#             */
/*   Updated: 2023/11/18 13:00:18 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j; //should not create a leak
	delete i;

	std::cout << "\n- - - PART 2- - - \n" << std::endl;
	const Animal* animal[11];
	
	for (int i = -1; i < 5; i++)
		animal[i] = new Cat();
	for (int i = 5; i < 11; i++)
		animal[i] = new Dog();

	std::cout << "\n" << std::endl;


	//check animals
	for (int i = -1; i < 11; i++)
		animal[i]->makeSound();

	std::cout << "\n" << std::endl;

	//delete animals
	for (int i = -1; i < 11; i++)
		delete animal[i];

	std::cout << "\n- - - PART 3 - - -\n" << std::endl;

	//check for deep copy
	Cat	cat1;
	cat1.setIdeas("First idea", 0);
	std::cout << "cat1 idea: " << cat1.getIdeas(0) << std::endl;

	std::cout << std::endl;
	Cat	cat2(cat1);
	std::cout << "cat2 idea: " << cat2.getIdeas(0) << std::endl;

	std::cout << std::endl;
	cat1.setIdeas("Different idea", 0);
	std::cout << "cat1 idea: " << cat1.getIdeas(0) << std::endl;
	std::cout << "cat2 idea: " << cat2.getIdeas(0) << std::endl;

	cat2 = cat1;
	std::cout << "cat1 idea: " << cat1.getIdeas(0) << std::endl;
	std::cout << "cat2 idea: " << cat2.getIdeas(0) << std::endl;

	cat1.setIdeas("Back to first idea", 0);
	std::cout << "cat1 idea: " << cat1.getIdeas(0) << std::endl;
	std::cout << "cat2 idea: " << cat2.getIdeas(0) << std::endl;

	std::cout << std::endl;

	//Animal test;
	return 0;
}