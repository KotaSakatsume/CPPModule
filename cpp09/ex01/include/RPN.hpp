/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotasakatsume <kotasakatsume@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 19:37:57 by kotasakatsu       #+#    #+#             */
/*   Updated: 2026/01/07 14:43:47 by kotasakatsu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>

class RPN
{
private:
    std::stack<int> _stack;

    bool isOperator(const std::string& token) const;
    bool isNumber(const std::string& token) const;
    void applyOperator(const std::string& op);

public:
    RPN();
    // RPN(const RPN& other);
    // RPN& operator=(const RPN& other);
    ~RPN();

    void evaluate(const std::string& expression);

};

#endif
