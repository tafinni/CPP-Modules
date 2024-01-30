/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:32:07 by tfinni            #+#    #+#             */
/*   Updated: 2023/11/18 12:32:08 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(Brain &b)
{
	std::cout << "Brain copy vonstructor called" << std::endl;
	*this = b;
}

Brain &Brain::operator=(Brain &b)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &b)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = b._ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

std::string Brain::accessIdeas(int i) const
{
	return (this->_ideas[i]);
}

void Brain::alterIdeas(std::string idea, int i)
{
	this->_ideas[i] = idea;
}

