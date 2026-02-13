/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotasakatsume <kotasakatsume@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 19:38:01 by kotasakatsu       #+#    #+#             */
/*   Updated: 2026/02/13 15:41:38 by kotasakatsu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>

RPN::RPN() {}

RPN::~RPN() {}

bool RPN::isOperator(const std::string& token) const
{
    return token == "+" || token == "-" || token == "*" || token == "/";
}
bool RPN::isNumber(const std::string& token) const
{
    return token.length() == 1 && std::isdigit(token[0]);
}

void RPN::applyOperator(const std::string& op)
{
    int b = _stack.top();
    _stack.pop();
    int a = _stack.top();
    _stack.pop();
    int result;
    if (op == "+")
        result = a + b;
    else if (op == "-")
        result = a - b;
    else if (op == "*")
        result = a * b;
    else if (op == "/")
        result = a / b;
    _stack.push(result);
}

void RPN::evaluate(const std::string& expression)
{
    std::string token;
    std::stringstream ss(expression);
    while (ss >> token)
    {
        if (isNumber(token))
        {
            _stack.push(token[0] - '0');
        }
        else if (isOperator(token))
        {
            if (_stack.size() < 2)
                throw std::runtime_error("Insufficient values in the expression");
            applyOperator(token);
        }
        else
        {
            throw std::runtime_error("Invalid token: " + token);
        }
    }
    if (_stack.size() != 1)
        throw std::runtime_error("Invalid expression");
    std::cout << _stack.top() << std::endl;
}
