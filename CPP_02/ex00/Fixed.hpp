/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:25:19 by tfinni            #+#    #+#             */
/*   Updated: 2023/11/05 15:25:20 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					_fixedValue;
		static const int	_fractionalBits = 8;
		
	public:
		Fixed();
		Fixed(const Fixed &first);
		Fixed &operator=(const Fixed &first);
		~Fixed();

		int	getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
