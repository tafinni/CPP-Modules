/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:32:35 by tfinni            #+#    #+#             */
/*   Updated: 2023/11/18 12:32:36 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(Animal &a)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = a;
}

Animal	&Animal::operator=(Animal &a)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &a)
	{
		this->type = a.type;
	}
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "No sound" << std::endl;
}

std::string Animal::getType() const
{
	return (type);
}