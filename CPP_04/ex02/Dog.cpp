/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:32:48 by tfinni            #+#    #+#             */
/*   Updated: 2023/11/18 12:32:49 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	this->_brain = new Brain;
}

Dog::Dog(Dog &d): Animal()
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->_brain = new Brain;
	*this = d;
}

Dog	&Dog::operator=(Dog &d)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &d)
	{
		this->type = d.type;
		*(this->_brain) = *(d._brain);
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
}

void	Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}

void	Dog::setIdeas(std::string idea, int i) const
{
	this->_brain->alterIdeas(idea, i);
}

std::string	Dog::getIdeas(int i) const
{
	return (this->_brain->accessIdeas(i)); 
}