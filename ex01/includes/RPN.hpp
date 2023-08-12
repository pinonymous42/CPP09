/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohei <kohei@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 10:08:32 by kohei             #+#    #+#             */
/*   Updated: 2023/08/04 10:42:29 by kohei            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
    public:
        RPN(void);
        RPN(RPN const &src);
        ~RPN(void);
        RPN &operator=(RPN const &rhs);
        int calculate(std::string const &str);
        std::stack<int> getStack(void) const;

    private:
        std::stack<int> _stack;
};

#endif