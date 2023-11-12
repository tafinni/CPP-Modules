/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:06:08 by tfinni            #+#    #+#             */
/*   Updated: 2023/10/31 14:06:09 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int	main(void)
{
	Zombie	*zombie = newZombie("Foo");
	
	zombie->announce();
	std::cout << "-- Deleting allocated zombie --" << std::endl;
	delete(zombie);
	std::cout << "-- Creating zombie on the stack --" << std::endl;
	randomChump("Hoo");
	return (0);
}