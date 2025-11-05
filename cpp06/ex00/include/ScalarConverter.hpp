/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotasakatsume <kotasakatsume@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 19:19:02 by kosakats          #+#    #+#             */
/*   Updated: 2025/11/05 18:33:03 by kotasakatsu      ###   ########.fr       */
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
    // --- メインの変換関数（唯一の公開メソッド） ---
    
    static void convert(const std::string &literal);
    // --- 型判定に使う列挙型 ---
    enum Type {
        TYPE_CHAR,
        TYPE_INT,
        TYPE_FLOAT,
        TYPE_DOUBLE,
        TYPE_INVALID
    };
    static Type detectType(const std::string &literal);

private:
    // --- コンストラクタ系（インスタンス化禁止） ---
    ScalarConverter();
    ScalarConverter(const ScalarConverter &);
    ScalarConverter &operator=(const ScalarConverter &);
    ~ScalarConverter();

    // --- 型判定 ---

    // --- 疑似リテラル判定 (nan, infなど) ---
    static bool isPseudoLiteral(const std::string &literal);

    // --- 各型から変換処理 ---
    static void convertFromChar(char c);
    // static void convertFromInt(int n);
    // static void convertFromFloat(float f);
    // static void convertFromDouble(double d);

    // --- 変換結果の出力 ---
    static void printResult(char c, int i, float f, double d,
                            bool impossibleFlags[4]);
};

#endif
