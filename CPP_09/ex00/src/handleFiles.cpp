/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handleFiles.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:28:44 by tfinni            #+#    #+#             */
/*   Updated: 2024/02/27 15:34:07 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../BitcoinExchange.hpp"

bool  BitcoinExchange::readData()
{
    std::ifstream data_file("data.csv");
    if (!data_file.is_open())
        throw NoFileOpen();

    std::string line;
    std::getline(data_file, line);
    if (line != "date,exchange_rate")
        throw WrongFileStart();

    while (std::getline(data_file, line))
    {
        std::istringstream ss(line);
        std::string date, rate;

        try
        {
            if (std::getline(ss, date, ',') && std::getline(ss, rate))
            {
                    if (validDate(date) == false || validRate(rate) == false)
                        throw BadInput();
                _data.insert(std::pair<std::string, float>(date, std::stof(rate)));
            }
            else
                throw BadInput();
        }
        catch (std::exception &e)
        {
            std::cerr << "Error: " << e.what() << date << "," << rate << std::endl;
            return false;
        }
    }
    return true;
}

bool BitcoinExchange::readInput(std::string file_name)
{
    std::ifstream input_file(file_name);
    try
    {
        if (!input_file.is_open())
            throw NoFileOpen();

        std::string line;
        std::getline(input_file, line);
        if (line != "date | value")
            throw WrongFileStart();
        while (std::getline(input_file, line))
        {
            std::istringstream ss(line);
            ss.str(line);
            handleLine(ss);
        }
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }
    return true;
}

void BitcoinExchange::handleLine(std::istringstream &ss)
{
    std::string date, rate;

    if (std::getline(ss, date, '|') && std::getline(ss, rate))
    {
        if (date.size() < 9 || rate.size() < 2)
            return ;
        date = date.substr(0, 10);
        rate = rate.substr(1);
        if (validDate(date) == false || validRate(rate) == false)
            return ;
        else if (std::stof(rate) >= 1000)
            try {throw TooLargeNumber();}
            catch (std::exception &e) {std::cerr << "Error: " << e.what() << std::endl; return;}
        printResult(date, std::stof(rate));
    }
    else
        try
        {
            throw BadInput();
        }
        catch(const std::exception &e)
        {
            std::cerr << "Error: " << e.what() << date << std::endl;;
        }
}

void BitcoinExchange::printResult(const std::string date, const float rate)
{
    for (std::map<std::string, float>::iterator it = _data.begin(); it != _data.end(); it++)
    {
        if (it->first == date)
        {
            std::cout << date << " => " << rate << " = " << std::setprecision(2) << rate * it->second << std::endl;
            return ;
        }
    }
    std::map<std::string, float>::iterator nearest = _data.lower_bound(date);
    if (nearest != _data.begin())
        nearest--;
    else if (nearest == _data.begin() && nearest->first < _data.begin()->first)
    {
        std::cout << "Error: date out of bounds" << std::endl;
        return ;
    }
    std::cout << date << " => " << rate << " = " << std::setprecision(2) << rate * nearest->second << std::endl;
}
