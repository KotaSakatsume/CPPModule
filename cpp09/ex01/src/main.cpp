/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotasakatsume <kotasakatsume@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 19:37:59 by kotasakatsu       #+#    #+#             */
/*   Updated: 2026/01/07 14:43:53 by kotasakatsu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " \"<RPN expression>\"" << std::endl;
        return 1;
    }

    RPN rpnCalculator;
    try
    {
        rpnCalculator.evaluate(argv[1]);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
