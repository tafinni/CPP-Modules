/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:33:11 by tfinni            #+#    #+#             */
/*   Updated: 2023/11/18 12:33:12 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	//std::cout << "Character default constructor" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_materiaInventory[i] = NULL;
}

Character::Character(std::string name): _name(name)
{
	//std::cout << "Character string constructor" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_materiaInventory[i] = NULL;
}

Character::Character(Character const &c)
{
	//std::cout << "Character copy constructor" << std::endl;
	*this = c;
}

Character &Character::operator=(Character const &c)
{
	//std::cout << "Character assignment operator" << std::endl;
	if (this != &c)
	{
		this->_name = c._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_materiaInventory[i] != NULL)
			{
				delete this->_materiaInventory[i];
				this->_materiaInventory[i] = NULL;
			}
		}
		for (int i = 0; i < 4; i++)
			this->_materiaInventory[i] = c._materiaInventory[i]->clone();
	}
	return (*this);
}

Character::~Character()
{
	//std::cout << "Character destructor" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_materiaInventory[i] != NULL)
		{
			delete this->_materiaInventory[i];
			this->_materiaInventory[i] = NULL;
		}
	}
}

AMateria* Character::getDrop(int idx)
{
	return (this->_materiaInventory[idx]);
}

std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materiaInventory[i] == NULL)
		{
			this->_materiaInventory[i] = m;
//			std::cout << "Character " << this->_name << " has equipped " << this->_materiaInventory[i]->getType() << std::endl;
			return ;
		}
	}
	delete m;
}

void Character::unequip(int idx)
{
	if (idx < 4 && this->_materiaInventory[idx] != NULL)
	{
//		std::cout << "Character " << this->_name << " unequipped " << this->_materiaInventory[idx]->getType() << std::endl;
		this->_materiaInventory[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 4 && this->_materiaInventory[idx] != NULL)
		this->_materiaInventory[idx]->use(target);
}
