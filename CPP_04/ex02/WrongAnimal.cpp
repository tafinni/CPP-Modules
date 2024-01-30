/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:32:56 by tfinni            #+#    #+#             */
/*   Updated: 2023/11/18 12:32:57 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal &wa)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = wa;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal &wa)
{
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	if (this != &wa)
	{
		this->type = wa.type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Wrong no sound" << std::endl;
}