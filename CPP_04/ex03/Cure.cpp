/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:33:16 by tfinni            #+#    #+#             */
/*   Updated: 2023/11/18 12:33:17 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{
	//std::cout << "Cure default constructor" << std::endl;
}

Cure::Cure(Cure const &c): AMateria("cure")
{
	//std::cout << "Cure copy constructor" << std::endl;
	*this = c;
}

Cure &Cure::operator=(Cure const &c)
{
	//std::cout << "Cure copy assignment operator" << std::endl;
	if (this != &c)
	{
		this->_type = c._type;
	}
	return (*this);
}

Cure::~Cure()
{
	//std::cout << "Cure destructor" << std::endl;
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
