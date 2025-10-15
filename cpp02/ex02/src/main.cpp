/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 15:40:40 by kosakats          #+#    #+#             */
/*   Updated: 2025/10/14 14:47:44 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
#include <iostream>

int main(void) {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << ">" << std::endl;
    std::cout << (a < b) << std::endl;
    std::cout << std::endl;
    std::cout << "<" << std::endl;
    std::cout << (a > b) << std::endl;
    std::cout << std::endl;
    std::cout << ">=" << std::endl;
    std::cout << (a >= b) << std::endl;
    std::cout << std::endl;
    std::cout << "<=" << std::endl;
    std::cout << (a <= b) << std::endl;
    std::cout << std::endl;
    std::cout << "==" << std::endl;
    std::cout << (a == b) << std::endl;
    std::cout << std::endl;
    std::cout << "!=" << std::endl;
    std::cout << (a != b) << std::endl;
    std::cout << std::endl;
    std::cout << "+" << std::endl;
    std::cout << (a + b) << std::endl;
    std::cout << std::endl;
    std::cout << "-" << std::endl;
    std::cout << (a - b) << std::endl;
    std::cout << std::endl;
    std::cout << "*" << std::endl;
    std::cout << (a * b) << std::endl;
    std::cout << std::endl;
    std::cout << "/" << std::endl;
    std::cout << (a / b) << std::endl;
    std::cout << std::endl;
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;

    return 0;
}
