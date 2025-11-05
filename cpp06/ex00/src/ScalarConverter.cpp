/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 19:50:11 by kosakats          #+#    #+#             */
/*   Updated: 2025/11/04 19:40:42 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool isPseudoLiteral(const std::string &literal)
{
    if (literal == "nan"  || literal == "nanf"  ||
    literal == "+inf" || literal == "+inff" ||
    literal == "-inf" || literal == "-inff")
        return true;
    else
        return false;
}

ScalarConverter::Type detectType(const std::string &literal)
{
    if(isPseudoLiteral(literal) == 0)
    {
        return ;
    }
}

void ScalarConverter::convert(const std::string &literal)
{
    std::cout << "Converting: " << literal << std::endl;
    detectType(literal);
}
