/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:33:20 by tfinni            #+#    #+#             */
/*   Updated: 2023/11/18 12:33:21 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{
	//std::cout << "Ice default constructor" << std::endl;
}

Ice::Ice(Ice const &c): AMateria("ice")
{
	//std::cout << "Ice copy constructor" << std::endl;
	*this = c;
}

Ice &Ice::operator=(Ice const &c)
{
	//std::cout << "Ice copy assignment operator" << std::endl;
	if (this != &c)
	{
		this->_type = c._type;
	}
	return (*this);
}

Ice::~Ice()
{
	//std::cout << "Ice destructor" << std::endl;
}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots and icebolt at " << target.getName() << " *" << std::endl;
}