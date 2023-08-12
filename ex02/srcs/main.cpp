/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohei <kohei@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:34:01 by kohei             #+#    #+#             */
/*   Updated: 2023/07/24 22:20:45 by kohei            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    std::vector<unsigned int> vector;
    if (argc == 1)
    {
        std::cout << "Error: Invalid input" << std::endl;
        return (1);
    }
    for (int i = 1; i < argc; i++)
    {
        std::string tmp(argv[i]);
        std::istringstream ss(tmp);
        int num;
        if (!(ss >> num) || num <= 0)
        {
            std::cout << "Error: Input positive number" << std::endl;
            return (1);
        }
        vector.push_back(num);
    }
    
    PmergeMe pmergeme(vector);
    pmergeme.measureAndSort();

    return (0);
}