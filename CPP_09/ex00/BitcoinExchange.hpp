/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:28:50 by tfinni            #+#    #+#             */
/*   Updated: 2024/02/28 17:51:02 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <iostream>
# include <regex>
# include <sstream>
# include <fstream>
# include <map>
# include <utility>
# include <ctime>
# include <iomanip>
# include <limits>

class BitcoinExchange
{
    private:
        std::map<std::string, float> _data;

    public:
        BitcoinExchange(); 
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange& operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        /* validation.cpp */
        bool validDateFormat(const std::string date);
        bool validDate(const std::string date);
        void validDateValues(const std::string date);
        bool validDay(const int year, const int month, const int day);
        bool validRate(const std::string rate);

        /* handleFiles.cpp */
        bool readData();
        void handleLine(std::istringstream &ss);
        void printResult(const std::string date, const float rate);
        bool readInput(std::string input_file);

        /* Exceptions */
        class NoFileOpen: public std::exception
        {
            public:
                const char *what() const throw();
        };
        class WrongFileStart: public std::exception
        {
            public:
                const char *what() const throw();
        };
        class BadInput: public std::exception
        {
            public:
                const char *what() const throw();
        };
        class DateOutOfBounds: public std::exception
        {
            public:
                const char *what() const throw();
        };
        class NotPositiveNumber: public std::exception
        {
            public:
                const char *what() const throw();
        };
        class TooLargeNumber: public std::exception
        {
            public:
                const char *what() const throw();
        };
};

#endif