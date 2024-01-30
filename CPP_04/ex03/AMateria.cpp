/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:33:06 by tfinni            #+#    #+#             */
/*   Updated: 2023/11/18 12:33:07 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type): _type(type)
{
	//std::cout << "AMateria string constructor" << std::endl;
}

AMateria::AMateria()
{
	//std::cout << "AMateria default contructor" << std::endl;
}

AMateria::AMateria(AMateria &am)
{
	//std::cout << "AMateria copy constructor" << std::endl;
	*this = am;
}

AMateria &AMateria::operator=(AMateria &am)
{
	//std::cout << "AMateria copy assignment operator" << std::endl;
	if (this != &am)
	{
		this->_type = am._type;
	}
	return (*this);
}

AMateria::~AMateria()
{
	//std::cout << "AMateria destructor" << std::endl;
}

std::string const &AMateria::getType() const
{
	return (this->_type);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "* use on " << target.getName() << " *" << std::endl;
}