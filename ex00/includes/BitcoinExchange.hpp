/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohei <kohei@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 10:32:36 by kohei             #+#    #+#             */
/*   Updated: 2023/08/06 19:05:04 by kohei            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <sstream>
#include <fstream>

class BitcoinExchange
{
    public:
        BitcoinExchange(void);
        BitcoinExchange(BitcoinExchange const &src);
        ~BitcoinExchange(void);
        BitcoinExchange                 &operator=(BitcoinExchange const &rhs);
        void                            calculate(std::string const &path);
        std::map<std::string, double>   getData(void) const;

    private:
        void                            readFromDB(void);
        bool                            checkFormat(std::string const &date, std::string const &rate);
        bool                            checkDate(std::string const &date);
        bool                            checkRate(std::string const &rate);
        double                          findRate(std::string const &date);
        std::map<std::string, double>   _data;
        int                             _firstYear;
        int                             _firstMonth;
        int                             _firstDay;
};
#endif