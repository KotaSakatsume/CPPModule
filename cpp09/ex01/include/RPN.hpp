/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 19:37:57 by kotasakatsu       #+#    #+#             */
/*   Updated: 2026/02/16 15:31:54 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <climits>

class RPN
{
private:
    std::stack<int> _stack;

    bool isOperator(const std::string& token) const;
    bool isNumber(const std::string& token) const;
    void applyOperator(const std::string& op);

public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

    void evaluate(const std::string& expression);

};

#endif
