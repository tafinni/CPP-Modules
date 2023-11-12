/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:06:37 by tfinni            #+#    #+#             */
/*   Updated: 2023/10/31 14:06:38 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	std::cout << "Allocating zombies\n---" << std::endl;
	Zombie *zombies = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		std::cout << "Naming zombie " << i + 1 << std::endl;
		zombies[i].setName(name);
	}
	std::cout << "---" << std::endl;
	return (zombies);
}
