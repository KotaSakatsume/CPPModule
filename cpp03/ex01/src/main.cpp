/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 19:28:56 by kosakats          #+#    #+#             */
/*   Updated: 2025/10/15 17:07:54 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

int main()
{
    ScavTrap s1("Serena");

    s1.attack("target dummy");
    s1.takeDamage(30);
    s1.beRepaired(20);
    s1.guardGate();

    std::cout << "----- Copy Test -----" << std::endl;
    ScavTrap s2 = s1;
    s2.attack("another dummy");

    return 0;
}

