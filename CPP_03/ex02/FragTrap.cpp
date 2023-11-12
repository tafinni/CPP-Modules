/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:44:09 by tfinni            #+#    #+#             */
/*   Updated: 2023/11/07 15:59:09 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap()
{
	std::cout << "\033[0;32mFragTrap default constructor called\033[0m" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << "\033[0;32mFragTrap constructor called\033[0m" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(FragTrap &ft)
{
	std::cout << "\033[0;32mFragTrap copy constructor called\033[0m" << std::endl;
	*this = ft;
}

FragTrap &FragTrap::operator=(FragTrap &ft)
{
	std::cout << "\033[0;32mFragTrap copy assignment operator called\033[0m" << std::endl;
	if (this != &ft)
	{
		this->_name = ft._name;
		this->_hitPoints = ft._hitPoints;
		this->_energyPoints = ft._energyPoints;
		this->_attackDamage = ft._attackDamage;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "\033[0;32mFragTrap destructor called\033[0m" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout <<  "\033[0;32mFragTrap " << this->_name << " : High fives guys!\033[0m" << std::endl;
}