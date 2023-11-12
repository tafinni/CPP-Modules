/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:25:35 by tfinni            #+#    #+#             */
/*   Updated: 2023/11/05 15:25:36 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* - ex00 - */

Fixed::Fixed(void)
{
//	std::cout << "Default constructor called" << std::endl;
	this->_fixedValue = 0;
}

Fixed::Fixed(const Fixed &first)
{
//	std::cout << "Copy constructor called" << std::endl;
	*this = first;
}

Fixed &Fixed::operator=(const Fixed &first)
{
//	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &first)
		this->_fixedValue = first.getRawBits();
	return (*this);	
}

Fixed::~Fixed(void)
{
//	std::cout << "Destructor called" << std::endl;
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedValue = raw;
//	std::cout << "Called setRawBits" << std::endl;
}

int		Fixed::getRawBits(void) const
{
//	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedValue);
}

/* - ex01 - */

Fixed::Fixed(const int value)
{
//	std::cout << "Int constructor called" << std::endl;
	this->_fixedValue = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
//	std::cout << "Float constructor called" << std::endl;
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

/* - ex02 - */
/* - comparison operators - */
bool	Fixed::operator>(const Fixed &fixed)
{
	return (this->getRawBits() > fixed.getRawBits());
}

bool	Fixed::operator<(const Fixed &fixed)
{
	return (this->getRawBits() < fixed.getRawBits());
}

bool	Fixed::operator>=(const Fixed &fixed)
{
	return (this->getRawBits() >= fixed.getRawBits());
}

bool	Fixed::operator<=(const Fixed &fixed)
{
	return (this->getRawBits() <= fixed.getRawBits());
}

bool	Fixed::operator==(const Fixed &fixed)
{
	return (this->getRawBits() == fixed.getRawBits());
}

bool	Fixed::operator!=(const Fixed &fixed)
{
	return (this->getRawBits() != fixed.getRawBits());
}

/* - arithmetic operators - */

Fixed Fixed::operator+(const Fixed &fixed)
{
	return (this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed)
{
	return (this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed)
{
	return (this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed)
{
	return (this->toFloat() / fixed.toFloat());
}

/* - increments, decrements - */
Fixed Fixed::operator--(void)
{
	this->_fixedValue -= 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed	fixed(*this);
	fixed._fixedValue = this->_fixedValue--;
	return (fixed);
}

Fixed Fixed::operator++(void)
{
	this->_fixedValue += 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	fixed(*this);

	fixed._fixedValue = this->_fixedValue++;
	return (fixed);
}

Fixed &Fixed::min(Fixed &first, Fixed &second)
{
	if (first.getRawBits() < second.getRawBits())
		return (first);
	return (second);
}

const Fixed &Fixed::min(const Fixed &first, const Fixed &second)
{
	if (first.getRawBits() < second.getRawBits())
		return (first);
	return (second);
}

Fixed &Fixed::max(Fixed &first, Fixed &second)
{
	if (first.getRawBits() > second.getRawBits())
		return (first);
	return (second);
}

const Fixed &Fixed::max(const Fixed &first, const Fixed &second)
{
	if (first.getRawBits() > second.getRawBits())
		return (first);
	return (second);
}

