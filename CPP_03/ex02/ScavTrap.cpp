/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:42:12 by tfinni            #+#    #+#             */
/*   Updated: 2023/11/07 15:58:40 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void	ScavTrap::attack(const std::string &target)
{
	if (this->_energyPoints > 0)
	{
		std::cout << "\033[0;31mScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!\033[0m" << std::endl;
		this->_energyPoints--;
 	}
	else
		std::cout << "\033[0;31mcavTrap " << this->_name << "doesn't have enough Energy Points to attack!\033[0m" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "\033[0;31mScavTrap " << this->_name << " is now in Gate keeper mode\033[0m" << std::endl;
}

ScavTrap::ScavTrap(void): ClapTrap()
{
	std::cout << "\033[0;31mScavTrap default constructor called\033[0m" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << "\033[0;31mScavTrap constructor called\033[0m" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap &st)
{
	std::cout << "\033[0;31mScavTrap copy constructor called\033[0m" << std::endl;
	*this = st;
}

ScavTrap &ScavTrap::operator=(ScavTrap &st)
{
	std::cout << "\033[0;31mScavTrap copy assignment operator called!\033[0m" << std::endl;
	if (this != &st)
	{
		this->_name = st._name;
		this->_hitPoints = st._hitPoints;
		this->_energyPoints = st._energyPoints;
		this->_attackDamage = st._attackDamage;
	}
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "\033[0;31mScavTrap destructor called\033[0m" << std::endl;	
}

