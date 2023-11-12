/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:44:40 by tfinni            #+#    #+#             */
/*   Updated: 2023/11/07 14:44:41 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
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
};

#endif