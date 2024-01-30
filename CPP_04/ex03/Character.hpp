/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:33:13 by tfinni            #+#    #+#             */
/*   Updated: 2023/11/18 12:33:14 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria	*_materiaInventory[4];

	public:
		Character();
		Character(std::string name);
		Character(Character const &c);
		Character &operator=(Character const &c);
		~Character();

		std::string const & getName() const;
		AMateria* getDrop(int idx);
		void droppedItem(AMateria* m);
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

};

#endif