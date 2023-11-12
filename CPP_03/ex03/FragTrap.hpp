/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:45:10 by tfinni            #+#    #+#             */
/*   Updated: 2023/11/07 14:45:11 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	private:
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap &ft);
		FragTrap &operator=(FragTrap &ft);
		~FragTrap();

		void	highFivesGuys(void);

		static const int	_baseHitPoints = 100;
		static const int	_baseEnergyPoints = 100;
		static const int	_baseAttackDamage = 30;
};

#endif