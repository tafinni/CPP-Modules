/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:33:38 by tfinni            #+#    #+#             */
/*   Updated: 2023/11/18 12:33:39 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria *_materia[4];
		
	public:
		MateriaSource();
		MateriaSource(MateriaSource const &m);
		MateriaSource &operator=(MateriaSource const &m);
		~MateriaSource();

		void	learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif