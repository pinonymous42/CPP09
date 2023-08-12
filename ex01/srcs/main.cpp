/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohei <kohei@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 10:08:44 by kohei             #+#    #+#             */
/*   Updated: 2023/08/04 10:24:16 by kohei            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    RPN     rpn;
    int     result;

    if (argc != 2)
    {
        std::cout << "Invalid input!" << std::endl;
        return (1);
    }
    result = rpn.calculate(argv[1]);
    std::cout << result << std::endl;
    return (0);
}