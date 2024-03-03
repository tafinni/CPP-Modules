/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:28:41 by tfinni            #+#    #+#             */
/*   Updated: 2024/02/27 12:28:42 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other): _data(other._data) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        _data = other._data;

    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

const char* BitcoinExchange::NoFileOpen::what() const throw()
{
    return "could not open file.";
}

const char* BitcoinExchange::WrongFileStart::what() const throw()
{
    return "wrong first line of input or data file.";
}

const char* BitcoinExchange::BadInput::what() const throw()
{
    return "bad input => ";
}

const char* BitcoinExchange::DateOutOfBounds::what() const throw()
{
    return "date out of bounds => ";
}

const char* BitcoinExchange::NotPositiveNumber::what() const throw()
{
    return "not a positive number.";
}

const char* BitcoinExchange::TooLargeNumber::what() const throw()
{
    return "too large number.";
}