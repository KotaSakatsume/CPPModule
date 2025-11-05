/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotasakatsume <kotasakatsume@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 19:50:11 by kosakats          #+#    #+#             */
/*   Updated: 2025/11/05 18:35:43 by kotasakatsu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::printResult(char c, int i, float f, double d, bool impossibleFlags[4])
{
    std::cout << std::fixed << std::setprecision(1);

    if (impossibleFlags[0])
        std::cout << "char: Non displayable" << std::endl;
        
    else if (impossibleFlags[1])
        std::cout << "char: impossible" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;

    if (impossibleFlags[1])
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;

    if (impossibleFlags[2])
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;

    if (impossibleFlags[3])
        std::cout << "double: impossible" << std::endl;
    else
        std::cout << "double: " << d << std::endl;
}

bool ScalarConverter::isPseudoLiteral(const std::string &literal)
{
    if (literal == "nan"  || literal == "nanf"  ||
    literal == "+inf" || literal == "+inff" ||
    literal == "-inf" || literal == "-inff")
        return true;
    else
        return false;
}

ScalarConverter::Type ScalarConverter::detectType(const std::string &literal)
{
    // ① 疑似リテラル判定 (nan, infなど)
    if (isPseudoLiteral(literal))
        return TYPE_INVALID; // これは特殊処理側で扱う

    // ② 1文字だけで、数字ではない場合 → char
    if (literal.length() == 1 && !isdigit(literal[0]))
        return TYPE_CHAR;

    // ③ "f" で終わる → float っぽい
    if (literal[literal.size() - 1] == 'f' && literal.find('.') != std::string::npos)
        return TYPE_FLOAT;

    // ④ '.' を含むが 'f' がない → double
    if (literal.find('.') != std::string::npos)
        return TYPE_DOUBLE;

    // ⑤ 数字だけなら int
    bool isInt = true;
    size_t i = 0;
    if (literal[0] == '+' || literal[0] == '-') // ±対応
        i++;
    for (; i < literal.length(); i++) {
        if (!isdigit(literal[i])) {
            isInt = false;
            break;
        }
    }
    if (isInt)
        return TYPE_INT;

    // ⑥ どれにも当てはまらない → invalid
    return TYPE_INVALID;
}

void ScalarConverter::convertFromChar(char c)
{
    int i = static_cast<int>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);

    bool impossibleFlags[4] = {false, false, false, false};

    // charが非表示（制御文字など）の場合は「非表示」と出す
    if (!std::isprint(c))
        impossibleFlags[0] = true;  // char表示不可能

    printResult(c, i, f, d, impossibleFlags);
}


void ScalarConverter::convert(const std::string &literal)
{
    std::cout << "Converting: " << literal << std::endl;
    Type type = detectType(literal);
    
    if (isPseudoLiteral(literal)) {
        float f = std::strtof(literal.c_str(), NULL);
        double d = static_cast<double>(f);
        bool impossibleFlags[4] = {true, true, false, false};
        printResult(0, 0, f, d, impossibleFlags);
        return;
    }
    switch (type)
    {
    case TYPE_CHAR:
        convertFromChar(literal[0]);
        break;
    case TYPE_INT:
        convertFromInt(std::atoi(literal.c_str()));
        break;
    case TYPE_FLOAT:
        convertFromFloat(std::strtof(literal.c_str(), NULL));
        break;
    case TYPE_DOUBLE:
        convertFromDouble(std::strtod(literal.c_str(), NULL));
        break;
    default:
        std::cout << "Invalid literal" << std::endl;
        break;
    }

}
