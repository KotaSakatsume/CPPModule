/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 19:19:02 by kosakats          #+#    #+#             */
/*   Updated: 2025/11/05 19:02:57 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <iomanip>
#include <cmath>

class ScalarConverter
{
public:
    static void convert(const std::string &literal);
    enum Type {
        TYPE_CHAR,
        TYPE_INT,
        TYPE_FLOAT,
        TYPE_DOUBLE,
        TYPE_INVALID
    };
    static Type detectType(const std::string &literal);

private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &);
    ScalarConverter &operator=(const ScalarConverter &);
    ~ScalarConverter();

    static bool isPseudoLiteral(const std::string &literal);

    static void convertFromChar(char c);
    static void convertFromInt(int n);
    static void convertFromFloat(float f);
    static void convertFromDouble(double d);

    static void printResult(char c, int i, float f, double d,
                            bool impossibleFlags[4]);
};

#endif
