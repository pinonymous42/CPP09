/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohei <kohei@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 10:08:34 by kohei             #+#    #+#             */
/*   Updated: 2023/08/06 18:46:56 by kohei            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(): _stack()
{
}

RPN::RPN(RPN const &src): _stack(src.getStack())
{
}

RPN::~RPN(void)
{
}

RPN &RPN::operator=(RPN const &rhs)
{
    if (this != &rhs)
        this->_stack = rhs._stack;
    return (*this);
}

int RPN::calculate(std::string const &str)
{
    int     i = 0;
    int     num = 0;
    int     tmp = 0;
    int     len = str.length();
    int     numCount = 0;

    while (i < len)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            num = str[i] - '0';
            this->_stack.push(num);
            numCount++;
        }
        else if (str[i] == '+')
        {
            if (numCount <= 1)
            {
                std::cout << "Error: Invalid expression." << std::endl;
                std::exit(1);
            }
            tmp = this->_stack.top();
            this->_stack.pop();
            tmp += this->_stack.top();
            this->_stack.pop();
            this->_stack.push(tmp);
            numCount--;
        }
        else if (str[i] == '-')
        {
            if (numCount <= 1)
            {
                std::cout << "Error: Invalid expression." << std::endl;
                std::exit(1);
            }
            tmp = this->_stack.top();
            this->_stack.pop();
            tmp = this->_stack.top() - tmp;
            this->_stack.pop();
            this->_stack.push(tmp);
            numCount--;
        }
        else if (str[i] == '*')
        {
            if (numCount <= 1)
            {
                std::cout << "Error: Invalid expression." << std::endl;
                std::exit(1);
            }
            tmp = this->_stack.top();
            this->_stack.pop();
            tmp *= this->_stack.top();
            this->_stack.pop();
            this->_stack.push(tmp);
            numCount--;
        }
        else if (str[i] == '/')
        {
            if (numCount <= 1)
            {
                std::cout << "Error: Invalid expression." << std::endl;
                std::exit(1);
            }
            if (this->_stack.top() == 0)
            {
                std::cout << "Divide by zero." << std::endl;
                std::exit(1);
            }
            tmp = this->_stack.top();
            this->_stack.pop();
            tmp = this->_stack.top() / tmp;
            this->_stack.pop();
            this->_stack.push(tmp);
            numCount--;
        }
        else if (str[i] == ' ')
            ;
        else
        {
            std::cout << "Error: Invalid character." << std::endl;
            std::exit(1);
        }
        i++;
    }
    if (numCount != 1)
    {
        std::cout << "Error: Invalid expression." << std::endl;
        std::exit(1);
    }
    return (this->_stack.top());
}

std::stack<int> RPN::getStack(void) const
{
    return (this->_stack);
}