/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:25:29 by tfinni            #+#    #+#             */
/*   Updated: 2023/11/05 15:25:30 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					_fixedValue;
		static const int	_fractionalBits = 8;
		
	public:
		/* - ex00 - */
		Fixed();
		Fixed(const Fixed &first);
		Fixed &operator=(const Fixed &first);
		~Fixed();
		int	getRawBits(void) const;
		void	setRawBits(int const raw);

		/* - ex01 - */
		Fixed(const int value);
		Fixed(const float value);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream& operator<<(std::ostream &os, const Fixed &fixed);

#endif

