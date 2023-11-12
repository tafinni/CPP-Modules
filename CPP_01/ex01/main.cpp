/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:06:28 by tfinni            #+#    #+#             */
/*   Updated: 2023/10/31 14:06:29 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name);

int	main(void)
{
	int		size = 3;
	std::cout << "Horde size: " << size << "\n---" << std::endl;
	Zombie	*zombies = zombieHorde(size, "Foo");

	for (int i = 0; i < size; i++)
	{
		std::cout << "Zombie number: " << i + 1 << std::endl;
		zombies[i].announce();
	}

	std::cout << "---\nDeleting zombies" << std::endl;
	delete[] zombies;
	return (0);
}
