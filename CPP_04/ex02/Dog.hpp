/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:32:50 by tfinni            #+#    #+#             */
/*   Updated: 2023/11/18 12:52:30 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
	private:
		Brain	*_brain;
	public:
		Dog();
		Dog(Dog &d);
		Dog	&operator=(Dog &d);
		~Dog();

		virtual void	makeSound() const;

		void setIdeas(std::string idea, int i) const;
		std::string getIdeas(int i) const;
};

#endif