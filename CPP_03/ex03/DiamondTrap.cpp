/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:45:00 by tfinni            #+#    #+#             */
/*   Updated: 2023/11/07 16:15:42 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "\033[0;36mDiamondTrap default constructor called\033[0m" << std::endl;
	this->_hitPoints = this->FragTrap::_baseHitPoints;
	this->_energyPoints = this->ScavTrap::_baseEnergyPoints;
	this->_attackDamage = this->FragTrap::_baseAttackDamage;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	std::cout << "\033[0;36mDiamondTrap constructor called\033[0m" << std::endl;
	this->_name = name;
	this->ClapTrap::_name = name + "_clap_name";
	this->_hitPoints = this->FragTrap::_baseHitPoints;
	this->_energyPoints = this->ScavTrap::_baseEnergyPoints;
	this->_attackDamage = this->FragTrap::_baseAttackDamage;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "\033[0;36mDiamondTrap destructor called\033[0m" << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "\033[0;36mWho am I? I am DiamondTrap " << this->_name << " and ClapTrap " << this->ClapTrap::_name << "\033[0m" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap &dt)
{
	std::cout << "\033[0;36mDiamondTrap copy constructor called\033[0m" << std::endl;
	*this = dt;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap &dt)
{
	std::cout << "\033[0;36mDiamondTrap copy assignment operator called\033[0m" << std::endl;
	if (this != &dt)
	{
		this->_name = dt._name;
		this->ClapTrap::_name = dt.ClapTrap::_name;
		this->_hitPoints = dt._hitPoints;
		this->_energyPoints = dt._energyPoints;
		this->_attackDamage = dt._attackDamage;
	}
	return (*this);
}

