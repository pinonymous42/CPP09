/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohei <kohei@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 10:32:34 by kohei             #+#    #+#             */
/*   Updated: 2023/08/06 19:12:19 by kohei            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
    readFromDB();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src): _data(src.getData())
{
}

BitcoinExchange::~BitcoinExchange(void)
{

}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
    if (this != &rhs)
        this->_data = rhs._data;
    return (*this);
}

void    BitcoinExchange::readFromDB(void)
{
    std::ifstream ifs("./data.csv");
    if (!ifs)
    {
        std::cout << "Error: file not found." << std::endl;
        std::exit(1);
    }
    std::string line;
    int count = 0;

    while (getline(ifs, line))
    {
        double value;
        if (count == 0)
        {
            count++;
            continue;
        }
        std::string key = line.substr(0, line.find(','));
        std::string tmp = line.substr(line.find(',') + 1);

        std::istringstream iss(tmp);
        iss >> value;

        _data[key] = value;
        count++;
    }
    ifs.close();

    //for (std::map<std::string, double>::iterator it = _data.begin(); it != _data.end(); it++)
    //{
    //    std::cout << std::setprecision(10) << it->first << " " << it->second << std::endl;
    //}
}

bool BitcoinExchange::checkFormat(std::string const &date, std::string const &rate)
{     
    if (date.length() != 10)
    {
        std::cout << "Error: wrong format." << std::endl;
        return (false);
    }
    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
        {
            if (date[i] != '-')
            {
                std::cout << "Error: wrong format." << std::endl;
                return (false);
            }
        }
        else if (date[i] < '0' || date[i] > '9')
        {
            std::cout << "Error: wrong format." << std::endl;
            return (false);
        }
    }
    //std::cout << rate << std::endl;
    for (int i = 0; i < (int)rate.length(); i++)
    {
        if (rate[i] == '.' || (i == 0 && rate[i] == '-'))
            continue;
        if (rate[i] < '0' || rate[i] > '9')
        {
            std::cout << "Error: wrong format." << std::endl;
            return (false);
        }
    }
    if (checkDate(date) == false || checkRate(rate) == false)
        return (false);
    return (true);
}

bool BitcoinExchange::checkDate(std::string const &date)
{
    static int count = 0;
    int monthDay[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::string tmp = date;
    std::stringstream ss;
    std::string strYear = tmp.substr(0, tmp.find('-'));
    tmp = tmp.substr(tmp.find('-') + 1);
    std::string strMonth = tmp.substr(0, tmp.find('-'));
    tmp = tmp.substr(tmp.find('-') + 1);
    std::string strDay = tmp.substr(0, tmp.find(' '));
    ss << strYear << " " << strMonth << " " << strDay;
    int year, month, day;
    ss >> year >> month >> day;
    if (count == 0)
    {
        _firstYear = year;
        _firstMonth = month;
        _firstDay = day;
    }
    count++;
    if (year < 0 || month < 0 || month > 12)
    {
        std::cout << "Error: bad input => ";
        std::cout << date << std::endl;
        return (false);
    }
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        monthDay[1] = 29;
    }
    if (day < 1 || day > monthDay[month - 1])
    {
        std::cout << "Error: bad input => ";
        std::cout << date << std::endl;
        return (false);
    }
    return (true);
}

bool BitcoinExchange::checkRate(std::string const &rate)
{
    std::stringstream ss;
    ss << rate;
    double value;
    ss >> value;
    if (value > 1000.0)
    {
        std::cout << "Error: too large a number." << std::endl;
        return (false);
    }
    else if (value < 0.0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return (false);
    }
    return (true);
}

double BitcoinExchange::findRate(std::string const &date)
{
    int count = 0;
    std::string yearStr, monthStr, dayStr, tmp;
    int year, month, day;
    std::stringstream ss1;
    
    tmp = date;
    yearStr = tmp.substr(0, tmp.find('-'));
    tmp = tmp.substr(tmp.find('-') + 1);
    monthStr = tmp.substr(0, tmp.find('-'));
    tmp = tmp.substr(tmp.find('-') + 1);
    dayStr = tmp;
    ss1 << yearStr << " " << monthStr << " " << dayStr;
    ss1 >> year >> month >> day;

    if (year < _firstYear || (year == _firstYear && month < _firstMonth) || (year == _firstYear && month == _firstMonth && day < _firstDay))
    {
        std::cout << "Error: bad input => ";
        std::cout << date << std::endl;
        
    }
    
    std::map<std::string, double>::iterator it = _data.begin();
    std::map<std::string, double>::iterator itBefore;

    for (; it != _data.end(); it++)
    {
        if (count == 0)
        {
            count++;
            continue;
        }
        std::stringstream ss2;
        int yearDB, monthDB, dayDB;
        std::string yearDBStr, monthDBStr, dayDBStr;
        tmp = it->first;
        yearDBStr = tmp.substr(0, tmp.find('-'));
        tmp = tmp.substr(tmp.find('-') + 1);
        monthDBStr = tmp.substr(0, tmp.find('-'));
        tmp = tmp.substr(tmp.find('-') + 1);
        dayDBStr = tmp;
        ss2 << yearDBStr << " " << monthDBStr << " " << dayDBStr;
        ss2 >> yearDB >> monthDB >> dayDB;
        if (year == yearDB)
        {
            if (month == monthDB)
            {
                if (day == dayDB)
                    return (it->second);
                else if (day < dayDB)
                    return (itBefore->second);
            }
            else if (month < monthDB)
                return (itBefore->second);
        }
        else if (year < yearDB)
            return (itBefore->second);
        count++;
        itBefore = it;
    }
    return (itBefore->second);
}

void BitcoinExchange::calculate(std::string const &path)
{
    std::ifstream ifs(path);
    if (!ifs)
    {
        std::cout << "Error: could not open file." << std::endl;
        std::exit(1);
    }

    std::string line;
    int count = 0;
    
    while (getline(ifs, line))
    {
        std::string date = line.substr(0, line.find(" | "));
        std::string rate;
        if (line.find(" | ") != std::string::npos)
            rate = line.substr(line.find(" | ") + 3);
        else
            rate = "";
        if (count == 0 || line == "")
        {
            if (count == 0 && line != "date | value")
            {
                std::cout << "Error: wrong header." << std::endl;
                std::exit(1);
            }
            count++;
            continue;
        }
        if (checkFormat(date, rate) == false)
        {
            count++;
            continue ;
        }
        std::istringstream iss(rate);
        double num;
        iss >> num;
        findRate(date);
        std::cout << date << " => ";
        std::cout << std::setprecision(10) << num << " = " << findRate(date) * num << std::endl;
        count++;
    }
}

std::map<std::string, double> BitcoinExchange::getData(void) const
{
    return (this->_data);
}