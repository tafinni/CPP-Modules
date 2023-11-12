/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:45:22 by tfinni            #+#    #+#             */
/*   Updated: 2023/11/07 14:45:23 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
	private:
	public:
		void	attack(const std::string &target);
		void	guardGate(void);

		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ScavTrap &st);
		ScavTrap &operator=(ScavTrap &st);
		~ScavTrap(void);

		static const int	_baseHitPoints = 100;
		static const int	_baseEnergyPoints = 50;
		static const int	_baseAttackDamage = 20;
};

#endif