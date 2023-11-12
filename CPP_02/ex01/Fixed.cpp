/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:25:27 by tfinni            #+#    #+#             */
/*   Updated: 2023/11/05 15:27:10 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* - ex00 - */

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixedValue = 0;
}

Fixed::Fixed(const Fixed &first)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = first;
}

Fixed &Fixed::operator=(const Fixed &first)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &first)
		this->_fixedValue = first.getRawBits();
	return (*this);	
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedValue = raw;
}

int		Fixed::getRawBits(void) const
{
	return (this->_fixedValue);
}

/* - ex01 - */

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedValue = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedValue = roundf(value * (1 << Fixed::_fractionalBits));
}

float	Fixed::toFloat(void) const
{
	float value = static_cast<float>(this->_fixedValue) / (1 << this->_fractionalBits);
	return (value);
}

int		Fixed::toInt(void) const
{
	return (this->_fixedValue >> _fractionalBits);
}

std::ostream& operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
} 
