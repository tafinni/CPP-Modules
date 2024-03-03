/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:28:47 by tfinni            #+#    #+#             */
/*   Updated: 2024/02/27 15:21:55 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../BitcoinExchange.hpp"

bool BitcoinExchange::validDateFormat(const std::string date)
{
    std::regex pattern("\\d{4}-\\d{2}-\\d{2}");
    return std::regex_match(date, pattern);
}

bool BitcoinExchange::validDay(const int year, const int month, const int day)
{
    if (month == 2)
    {
        if (year % 100 == 0)
        {
            if (year % 400 != 0)
            {
                if (day > 28)
                return false;
            }
        }
        else if (year % 4 == 0)
        {
            if (day > 29)
                return false;
        }
        else
            if (day > 28)
                return false;
    }
    else
    {
        if (month < 8 && month % 2 != 0)
        {
            if (day > 31)
                return false;
        }
        else if (month > 7 && month % 2 == 0)
        {
            if (day > 31)
                return false;
        }
        else
            if (day > 30)
                return false;
    }
    return true;
}

void BitcoinExchange::validDateValues(const std::string date)
{
    std::istringstream ss(date);
    int year, month, day;
    char dash;

    ss >> year >> dash >> month >> dash >> day;

    if (year < 2009 || day > 31 || day < 1 || month > 12 || month < 1)
        throw DateOutOfBounds();
    else if (year == 2009 && month == 1 && day == 1)
        throw BadInput();
    else if (validDay(year, month, day) == false)
        throw BadInput();
}

bool BitcoinExchange::validDate(const std::string date)
{
    try
    {
        if (validDateFormat(date) == false)
            throw BadInput();
        validDateValues(date);
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << date << std::endl;
        return false;
    }
    return true;
}

bool BitcoinExchange::validRate(const std::string rate)
{
    float value = std::stof(rate);

    try
    {
        if (value < 0)
            throw NotPositiveNumber();
        else if (value >= std::numeric_limits<int>::max())
            throw TooLargeNumber();        
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }
    try
    {
        if (!std::regex_match(rate, static_cast<std::regex>("^[+-]?\\d+(\\.\\d+)?$")))
            throw BadInput();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << rate << std::endl;
        return false;
    }
    
    return true;
}