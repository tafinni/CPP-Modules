/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:32:13 by tfinni            #+#    #+#             */
/*   Updated: 2023/11/18 12:52:13 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
	private:
		Brain	*_brain;

	public:
		Cat();
		Cat(Cat &c);
		Cat	&operator=(Cat &c);
		virtual ~Cat();

		virtual void makeSound() const;

		void setIdeas(std::string idea, int i) const;
		std::string getIdeas(int i) const;

};

#endif