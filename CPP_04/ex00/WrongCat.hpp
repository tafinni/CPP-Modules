/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:32:00 by tfinni            #+#    #+#             */
/*   Updated: 2023/11/18 12:32:01 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{

	public:
		WrongCat();
		WrongCat(WrongCat &wc);
		WrongCat &operator=(WrongCat &wc);
		~WrongCat();

		void	makeSound() const;
};

#endif