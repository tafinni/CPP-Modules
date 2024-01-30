/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:32:41 by tfinni            #+#    #+#             */
/*   Updated: 2023/11/18 12:32:42 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	public:
		std::string _ideas[100];

		Brain();
		Brain(Brain &b);
		Brain &operator=(Brain &b);
		~Brain();

		std::string accessIdeas(int i) const;
		void alterIdeas(std::string idea, int i);
};

#endif