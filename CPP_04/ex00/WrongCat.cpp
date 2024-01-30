/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:31:58 by tfinni            #+#    #+#             */
/*   Updated: 2023/11/18 12:31:59 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat default constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(WrongCat &wc): WrongAnimal()
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = wc;
}

WrongCat &WrongCat::operator=(WrongCat &wc)
{
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this != &wc)
	{
		this->type = wc.type;
	}
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "Wrong Meow!" << std::endl;
}

