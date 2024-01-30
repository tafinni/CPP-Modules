/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:32:43 by tfinni            #+#    #+#             */
/*   Updated: 2023/11/18 12:32:44 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	this->_brain = new Brain;
}

Cat::Cat(Cat &c): Animal()
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_brain = new Brain;
	*this = c;
}

Cat	&Cat::operator=(Cat &c)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &c)
	{
		this->type = c.type;
		*(this->_brain) = *(c._brain);
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
}

void	Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}

void	Cat::setIdeas(std::string idea, int i) const
{
	this->_brain->alterIdeas(idea, i);
}

std::string	Cat::getIdeas(int i) const
{
	return (this->_brain->accessIdeas(i)); 
}