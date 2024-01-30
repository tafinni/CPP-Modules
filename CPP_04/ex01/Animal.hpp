/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:32:05 by tfinni            #+#    #+#             */
/*   Updated: 2023/11/18 12:55:24 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:
		std::string	type;
		
	public:
		Animal();
		Animal(Animal &a);
		Animal	&operator=(Animal &a);
		virtual ~Animal();

		virtual void makeSound() const;
		std::string getType() const;

};


#endif