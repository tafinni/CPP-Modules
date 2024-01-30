/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:33:36 by tfinni            #+#    #+#             */
/*   Updated: 2023/11/18 12:33:37 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	//std::cout << "MateriaSource default constructor" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &m)
{
	//std::cout << "MateriaSource copy constructor" << std::endl;
	*this = m;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &m)
{
	//std::cout << "MateriaSource copy assignment operator" << std::endl;
	if (this != &m)
	{
		for (int i = 0; i < 4; i++)
			this->_materia[i] = m._materia[i];
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	//std::cout << "MateriaSource destructor" << std::endl;
    for (int i = 0; i < 4; i++)
    {
	    if (this->_materia[i])
		{
            delete this->_materia[i];
			this->_materia[i] = NULL;
		}
	}
}

void	MateriaSource::learnMateria(AMateria *materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->_materia[i])
		{
			this->_materia[i] = materia;
			break ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i] != NULL)
		{
			if (this->_materia[i]->getType() == type)
				return (this->_materia[i]->clone());
		}
	}
	return (NULL);
}

