/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 13:12:05 by kosakats          #+#    #+#             */
/*   Updated: 2025/10/04 13:13:06 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

void Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-"
              << "pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. "
              << "You didn’t put enough bacon in my burger! If you did, "
              << "I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. "
              << "I’ve been coming for years whereas you started working "
              << "here since last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now."
              << std::endl;
}

// 単体レベルでの呼び出し
void Harl::complain(std::string level)
{
    if (level == "DEBUG")
        debug();
    else if (level == "INFO")
        info();
    else if (level == "WARNING")
        warning();
    else if (level == "ERROR")
        error();
    else
        std::cout << "[ Probably complaining about insignificant problems ]\n"
                  << "Although there are several ways to deal with Harl, one of the most effective is to SWITCH it off."
                  << std::endl;
}

// 指定レベル以上をまとめて表示
void Harl::complainFromLevel(std::string level)
{
    int lv = -1;
    if (level == "DEBUG") lv = 0;
    else if (level == "INFO") lv = 1;
    else if (level == "WARNING") lv = 2;
    else if (level == "ERROR") lv = 3;

    switch (lv)
    {
        case 0:
            std::cout << "[ DEBUG ]" << std::endl;
            debug();
        case 1:
            std::cout << "[ INFO ]" << std::endl;
            info();
        case 2:
            std::cout << "[ WARNING ]" << std::endl;
            warning();
        case 3:
            std::cout << "[ ERROR ]" << std::endl;
            error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]\n"
                      << "Although there are several ways to deal with Harl, one of the most effective is to SWITCH it off."
                      << std::endl;
            break;
    }
}
