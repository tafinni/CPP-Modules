/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:44:03 by tfinni            #+#    #+#             */
/*   Updated: 2023/11/07 15:28:54 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* - ex00 - */

void	ClapTrap::attack(const std::string &target)
{
	if (this->_energyPoints > 0)
	{
		std::cout << "\033[0;33mClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!\033[0m" << std::endl;
		this->_energyPoints--;
	}
	else
		std::cout << "\033[0;33mClapTrap " << this->_name << " doesn't have enough Energy Points to attack!\033[0m" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints > amount)
	{	std::cout << "\033[0;33mClapTrap " << this->_name << " takes " << amount << " points of damage!\033[0m" << std::endl;
		this->_hitPoints = this->_hitPoints - amount;
	}
	else
	{
		std::cout << "\033[0;33mClapTrap " << this->_name << " is out of health\033[0m" << std::endl;
		this->_hitPoints = 0;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 0)
	{
		std::cout << "\033[0;33mClapTrap " << this->_name << " repairs\033[0m" << std::endl;
		this->_hitPoints = this->_hitPoints + amount;
		this->_energyPoints--;
	}
	else
		std::cout << "\033[0;33mClapTrap " << this->_name << " is out of energy\033[0m" << std::endl;
}


ClapTrap::ClapTrap(void): _name(), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "\033[0;33mClapTrap default contructor called\033[0m" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "\033[0;33mClapTrap Contructor called\033[0m" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &ct)
{
	std::cout << "\033[0;33mClapTrap copy contructor called\033[0m" << std::endl;
	*this = ct;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &ct)
{
	std::cout << "\033[0;33mClapTrap copy assignment operator called\033[0m" << std::endl;
	if (this != &ct)
	{
		this->_name = ct._name;
		this->_hitPoints = ct._hitPoints;
		this->_energyPoints = ct._energyPoints;
		this->_attackDamage = ct._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "\033[0;33mClapTrap destructor called\033[0m" << std::endl;
}

/* - Printing ClapTrap - */

std::string	ClapTrap::getName(void)
{
	return (this->_name);
}

unsigned int ClapTrap::getHitPoints(void)
{
	return (this->_hitPoints);
}

unsigned int ClapTrap::getEnergyPoints(void)
{
	return (this->_energyPoints);
}

unsigned int ClapTrap::getAttackDamage(void)
{
	return (this->_attackDamage);
}

std::ostream &operator<<(std::ostream &os, ClapTrap &ct)
{
	os << "\nSTATS:\n"
	"Name: " << ct.getName() <<
	"\nHit Points: " << ct.getHitPoints() <<
	"\nEnergy Points: " << ct.getEnergyPoints() <<
	"\nAttack Damage: " << ct.getAttackDamage() << std::endl;
	return (os);
}
